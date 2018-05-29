package com.sogou.speech.utils;

import com.sogou.speech.domain.Account;

public class DataEngine {
    public native static int add(int a, float b);

    public native static int add(int a[]);

    public native static String getToken();

    public native short[] vad(short[] data);

    public native boolean verify(short[] data);

    /**
     * 底层直接修改上层数组
     */
    public native void init(int[] ret);

    public native static String getPwd(String str);

    public native static int checkout(Account account, Callback callback);

    public native Account getAccount();

    public native void catchException();

    // jni层起线程 模拟网络请求 异步回调
    public native void getHtml(Callback callback);

    public interface Callback {
        void callback(int code, String msg);
    }

    static {
        System.loadLibrary("specch");
    }
}
