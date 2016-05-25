package com.example.learnjni;

import android.util.Log;

public class JniTest {
	public String name = "hello";

	public native String getString();

	/**
	 * 获取部分string
	 * 
	 * @param str
	 * @return
	 */
	public native String getFraString(String str);

	/**
	 * 获取二维数组
	 * 
	 * @param index
	 * @return
	 */
	public native int[][] getTwoArray(int index);

	public native void setName();

	public native void jniCallBack();

	public native Student getStudent();

	public void callBack() {
		Log.i("jni", "回调成功");
	}
}
