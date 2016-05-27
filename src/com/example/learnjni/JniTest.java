package com.example.learnjni;

import android.content.Context;
import android.util.Log;

public class JniTest {
	public String name = "hello";
	private Context mContext;

	public JniTest(Context mContext) {
		super();
		this.mContext = mContext;
	}

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

	public native String getContentFromPath(String path);
	// public native void startActivity(Context context);

	public void callBack() {
		Log.i("jni", "回调成功");
	}
}
