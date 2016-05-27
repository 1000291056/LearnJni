#include "jni.h"
#include <string.h>
#include <stdio.h>
JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getString(
		JNIEnv *env, jobject jobject) {
	return (*env)->NewStringUTF(env, "aaa");
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getFraString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getFraString(
		JNIEnv *env, jobject jobject, jstring jstr) {
	int size = (*env)->GetStringLength(env, jstr);
	jchar jstrChar[size];
	(*env)->GetStringRegion(env, jstr, 0, size > 2 ? size - 1 : size, jstrChar);
	jstring js = (*env)->NewString(env, jstrChar, size > 2 ? size - 1 : size);
	return js;
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    setName
 * Signature: ()V
 */JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_setName(JNIEnv *env,
		jobject ob) {
	if (ob == NULL) {
		return;
	}
	jclass obClass = (*env)->GetObjectClass(env, ob);
	if (obClass == NULL) {
		return;
	}
	jfieldID fildD = (*env)->GetFieldID(env, obClass, "name",
			"Ljava/lang/String;");
	if (fildD == NULL) {
		return;
	}
	if (fildD == NULL) {
		return;
	}
	jstring jsTemp = (*env)->NewStringUTF(env, "the world");
	(*env)->SetObjectField(env, ob, fildD, jsTemp);
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    jniCallBack
 * Signature: ()V
 */JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_jniCallBack(
		JNIEnv *env, jobject ob) {
	jclass obClass = (*env)->GetObjectClass(env, ob);
	jmethodID method = (*env)->GetMethodID(env, obClass, "callBack", "()V");
	(*env)->CallVoidMethodA(env, ob, method, NULL);
}

/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getStudent
 * Signature: ()Lcom/example/learnjni/Student;
 */JNIEXPORT jobject JNICALL Java_com_example_learnjni_JniTest_getStudent(
		JNIEnv *env, jobject ob) {
	jclass obClass = (*env)->FindClass(env, "com/example/learnjni/Student");
	if (obClass == NULL) {
		return NULL;
	}
	jmethodID methedId = (*env)->GetMethodID(env, obClass, "<init>",
			"(ILjava/lang/String;)V");
	jobject object = (*env)->NewObject(env, obClass, methedId, 11,
			(*env)->NewStringUTF(env, "小明"));
	return object;
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getTwoArray
 * Signature: (I)[[I
 */JNIEXPORT jobjectArray JNICALL Java_com_example_learnjni_JniTest_getTwoArray(
		JNIEnv *env, jobject object, jint index) {
	jclass arrayClass = (*env)->FindClass(env, "[I");
	if (arrayClass == NULL) {
		return NULL;
	}
	jobjectArray objectArray = (*env)->NewObjectArray(env, index, arrayClass,
			NULL);
	if (objectArray == NULL) {
		return NULL;
	}
	int i = 0;
	for (i = 0; i < (*env)->GetArrayLength(env, objectArray); i++) {
		int j = 0;
		jintArray intArray = (*env)->NewIntArray(env, index);
		jint jints[index];

		for (j = 0; j < index; j++) {
			jints[j];
		}
		(*env)->SetIntArrayRegion(env, intArray, 0, index, jints);
		(*env)->SetObjectArrayElement(env, objectArray, i, intArray);
		(*env)->DeleteLocalRef(env, intArray);
	}
	return objectArray;
}
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getContentFromPath
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getContentFromPath(
		JNIEnv *env, jobject ob, jstring path) {
	FILE *file = fopen(path, "r");

}
;
