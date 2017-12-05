#include <jni.h>
#include <string>
#include<Android/log.h>


#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型

extern "C"
JNIEXPORT jstring JNICALL
Java_ndkdemo_com_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
