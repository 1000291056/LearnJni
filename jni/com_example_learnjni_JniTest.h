/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_learnjni_JniTest */

#ifndef _Included_com_example_learnjni_JniTest
#define _Included_com_example_learnjni_JniTest
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getString
  (JNIEnv *, jobject);

/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getTwoArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_example_learnjni_JniTest_getTwoArray
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_example_learnjni_JniTest
 * Method:    setName
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_setName
  (JNIEnv *, jobject);

/*
 * Class:     com_example_learnjni_JniTest
 * Method:    jniCallBack
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_learnjni_JniTest_jniCallBack
  (JNIEnv *, jobject);

/*
 * Class:     com_example_learnjni_JniTest
 * Method:    getStudent
 * Signature: ()Lcom/example/learnjni/Student;
 */
JNIEXPORT jobject JNICALL Java_com_example_learnjni_JniTest_getStudent
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif