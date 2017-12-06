#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    jmethodID helloWorld_methodID = env->GetMethodID(clazz, "helloWorld", "(Ljava/lang/String;)V");
    if (helloWorld_methodID == NULL) return;
    const char *msg = "hello world";
    jstring jmsg = env->NewStringUTF(msg);
    env->CallVoidMethod(instance, helloWorld_methodID, jmsg);

}

int retval_hello1 = 1, retval_hello2 = 2;

void *threadFunc(void *arg) {
    int count = *(int *) arg;
    for (int i = 0; i < count; i++) {
        sleep(1);
        LOGI("hello  i=%d", i);
    }
    pthread_exit(&retval_hello1);
}

extern "C"
JNIEXPORT void JNICALL
Java_ndkdemo_com_ndkdemo_MainActivity_startNativeThread(JNIEnv *env, jobject instance, jint count) {
    pthread_t pthread;
    int *arg = new int(count);
    retval_hello1 = pthread_create(&pthread, NULL, threadFunc, arg);
    if (retval_hello1 != 0) {
        LOGI("pthread_create error!\n");
    }
}