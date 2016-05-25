#include "jni.h"
#include <string.h>

JNIEXPORT jstring JNICALL Java_com_example_learnjni_JniTest_getString(
		JNIEnv *env, jobject jobject) {
	return (*env)->NewStringUTF(env, "aaa");
}
