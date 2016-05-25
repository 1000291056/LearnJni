package com.example.learnjni;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {
	static {
		System.loadLibrary("LearnJni");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		TextView textView = (TextView) findViewById(R.id.helloTv);
		JniTest test=new JniTest();
		textView.setText(test.getString());
//		int[][] a=test.getTwoArray(10);
//		test.setName();
//		Log.i("jni", a+"");
//		textView.setText(textView.getText()+test.name);
//		test.jniCallBack();
//		Student student=test.getStudent();
//		Log.i("jni", student.toString());
	}

}
