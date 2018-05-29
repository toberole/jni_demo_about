package com.sogou.speech.activity;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.sogou.speech.R;
import com.sogou.speech.domain.Account;
import com.sogou.speech.utils.DataEngine;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        int a = 1;
//        float b = 2.1f;
//        Log.i("AAAA", "" + a + " + " + b + " = " + String.valueOf(DataEngine.add(a, b)));
//
//
//        int arr[] = new int[]{1, 2, 3, 4, 5};
//        Log.i("AAAA", "total: " + DataEngine.add(arr));
//
//        Log.i("AAAA", "getString: " + DataEngine.getToken());
//
//        Log.i("AAAA", "getString: " + DataEngine.getPwd("hello"));
//
//        Log.i("AAAA", "getString: " + DataEngine.getPwd("Tom"));

//        Account account = new Account();
//        account.name = "123";
//        account.pwd = "456";
//        Log.i("AAAA", "checkout: " + DataEngine.checkout(account));

        DataEngine dataEngine = new DataEngine();
//        int ret[] = new int[3];
//        dataEngine.init(ret);
//        for (int i = 0; i < 3; i++) {
//            Log.i("AAAA", "ret[" + i + "]= " + ret[i]);
//        }
//
//        boolean b = dataEngine.verify(new short[]{1, 3, 5});
//        Log.i("AAAA", "b: " + b);
//
//        short[] rets = dataEngine.vad(new short[]{1,2,3,4,5});
//        for (int i = 0; i < rets.length; i++) {
//            Log.i("AAAA", "rets[" + i + "]" + rets[i]);
//
//        }

        Log.i("AAAA", "getPwd " + dataEngine.getPwd("hello"));
        java.util.UUID.randomUUID().toString();
        Account account = dataEngine.getAccount();
//
//        Log.i("AAAA", account.toString());

        dataEngine.checkout(account, new DataEngine.Callback() {
            @Override
            public void callback(int code, String msg) {
                Log.i("AAAA", "callback code: " + code + " msg: " + msg);

            }
        });

//        try {
//            dataEngine.catchException();
//        } catch (Exception e) {
//            Log.i("AAAA", e.getMessage());
//        }

       // dataEngine.catchException();

        dataEngine.getHtml(new DataEngine.Callback() {
            @Override
            public void callback(int code, String msg) {
                Log.i("jni-log", "callback code: " + code + " msg: " + msg);
            }
        });

    }
}
