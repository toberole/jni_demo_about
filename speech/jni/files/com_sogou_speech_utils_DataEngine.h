/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_sogou_speech_utils_DataEngine */

#ifndef _Included_com_sogou_speech_utils_DataEngine
#define _Included_com_sogou_speech_utils_DataEngine
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    add
 * Signature: (IF)I
 */
JNIEXPORT jint JNICALL Java_com_sogou_speech_utils_DataEngine_add__IF
  (JNIEnv *, jclass, jint, jfloat);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    add
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_sogou_speech_utils_DataEngine_add___3I
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    getToken
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sogou_speech_utils_DataEngine_getToken
  (JNIEnv *, jclass);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    vad
 * Signature: ([S)[S
 */
JNIEXPORT jshortArray JNICALL Java_com_sogou_speech_utils_DataEngine_vad
  (JNIEnv *, jobject, jshortArray);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    verify
 * Signature: ([S)Z
 */
JNIEXPORT jboolean JNICALL Java_com_sogou_speech_utils_DataEngine_verify
  (JNIEnv *, jobject, jshortArray);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    init
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_sogou_speech_utils_DataEngine_init
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    getPwd
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sogou_speech_utils_DataEngine_getPwd
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    checkout
 * Signature: (Lcom/sogou/speech/domain/Account;Lcom/sogou/speech/utils/DataEngine/Callback;)I
 */
JNIEXPORT jint JNICALL Java_com_sogou_speech_utils_DataEngine_checkout
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_sogou_speech_utils_DataEngine
 * Method:    getAccount
 * Signature: ()Lcom/sogou/speech/domain/Account;
 */
JNIEXPORT jobject JNICALL Java_com_sogou_speech_utils_DataEngine_getAccount
  (JNIEnv *, jobject);


JNIEXPORT void JNICALL Java_com_sogou_speech_utils_DataEngine_catchException
  (JNIEnv *, jobject);


JNIEXPORT void JNICALL Java_com_sogou_speech_utils_DataEngine_getHtml
   (JNIEnv *, jclass, jobject);


#ifdef __cplusplus
}
#endif
#endif
