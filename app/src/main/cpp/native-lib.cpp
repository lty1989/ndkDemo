#include <jni.h>
#include <string>
#include<Android/log.h>
#include <pthread.h>


#define LOG_TAG "ndkDemo"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__) // 定义LOGI类型

extern "C"
JNIEXPORT jstring JNICALL
Java_ndkdemo_com_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    char *hello = "Hello from C++00";
    LOGI("%s\n", hello);
    return env->NewStringUTF(hello);
}
extern "C"
JNIEXPORT void JNICALL
Java_ndkdemo_com_ndkdemo_MainActivity_callJavaHelloWorld2(JNIEnv *env, jobject instance) {
    jclass clazz = env->GetObjectClass(instance);
    if (clazz == NULL) return;
    jmethodID helloWorld_methodID = env->GetMethodID(clazz, "helloWorld", "(java/lang/String;)V");
    if (helloWorld_methodID == NULL) return;
    const char *msg = "hello world";
    jstring jmsg = env->NewStringUTF(msg);
    env->CallVoidMethod(instance, helloWorld_methodID, jmsg);

}