#include<android/log.h>

// 打印log
#define TAG "jni-log"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


#ifndef SPEECH_LOG_H
#define SPEECH_LOG_H

#endif //SPEECH_LOG_H


/**
* 向 java 层抛出 exception
*/
void throwException(JNIEnv *env,const char *exceptionName,const char *exceptionMsg){
    env->ExceptionDescribe();

    env->ExceptionClear();

    jclass errCls = env->FindClass(exceptionName);

    if(NULL != errCls && NULL != exceptionMsg){
        env->ThrowNew(errCls, exceptionMsg);
    }
}