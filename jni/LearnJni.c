#include "jni.h"
#include <string.h>
JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getString(
		JNIEnv *env, jobject ob) {

	return (*env)->NewStringUTF(env, "2222222222222");
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getTwoArray
 * Signature: (I)[[I
 */JNIEXPORT jobjectArray JNICALL Java_com_example_learnjni_JniTest_getTwoArray(
		JNIEnv *env, jobject ob, jint index) {
	jclass jintArrayClass = (*env)->FindClass(env, "[I");
	jobjectArray jobjectArrayTemp = (*env)->NewObjectArray(env, index,
			jintArrayClass, NULL);
	int i = 0;
	for (i = 0; i < index; i++) {
		jintArray jintArrayTemp = (*env)->NewIntArray(env, index);
		jint temp[index];
		int j = 0;
		for (j = 0; j < index; j++) {
			temp[j] = j;
		}
		(*env)->SetIntArrayRegion(env, jintArrayTemp, 0, index, temp);
		(*env)->SetObjectArrayElement(env, jobjectArrayTemp, i, jintArrayTemp);
		(*env)->DeleteLocalRef(env, jintArrayTemp);
	}
	return jobjectArrayTemp;
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    setName
 * Signature: ()V
 */JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_setName(JNIEnv *env,
		jobject ob) {
	jclass obClass = (*env)->GetObjectClass(env, ob);
	if (obClass == NULL) {
		return;
	}
	jfieldID fildD = (*env)->GetFieldID(env, obClass, "name",
			"Ljava/lang/String;");
	if (fildD == NULL) {
		return;
	}
	jstring inTemp = (*env)->GetObjectField(env, ob, fildD);
	jstring str = (*env)->NewStringUTF(env, "the world");
	char* inTempChar = (*env)->GetStringUTFChars(env, inTemp, NULL);
	char* strChar = (*env)->GetStringUTFChars(env, str, NULL);
	char* wa = strcat(inTempChar, strChar);
	jstring last = (*env)->NewStringUTF(env, wa);
	(*env)->SetObjectField(env, ob, fildD, last);
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    jniCallBack
 * Signature: ()V
 */JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_jniCallBack(
		JNIEnv *env, jobject ob) {
	jclass obclass = (*env)->GetObjectClass(env, ob);
	jmethodID methodID = (*env)->GetMethodID(env, obclass, "callBack", "()V");
	(*env)->CallVoidMethod(env, ob, methodID);
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getStudent
 * Signature: ()Lcom/example/learnjni/Student;
 */JNIEXPORT jobject JNICALL Java_com_example_learnjni_JniTest_getStudent(
		JNIEnv *env, jobject ob) {
	jclass obClass = (*env)->FindClass(env, "com/example/learnjni/Student");
	jmethodID methodID = (*env)->GetMethodID(env, obClass, "<init>",
			"(ILjava/lang/String;)V");
	jstring name = (*env)->NewStringUTF(env, "小明");
	jobject student = (*env)->NewObject(env, obClass, methodID, 10, name);
	return student;
}
