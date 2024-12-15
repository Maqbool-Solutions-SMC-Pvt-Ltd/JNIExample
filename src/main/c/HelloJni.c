#include <jni.h>
#include <stdio.h>
#include "com_example_jni_MainApp.h"

JNIEXPORT void JNICALL Java_com_example_jni_MainApp_sayHello
  (JNIEnv *env, jclass cls, jobject runner) {
    // Print message from C
    printf("Hello from C!\n");

    // Ensure the Runnable object is not NULL
    if (runner == NULL) {
        printf("Runnable object is NULL!\n");
        return;
    }

    // Find the MainApp class
    jclass mainClass = (*env)->FindClass(env, "com/example/jni/MainApp");
    if (mainClass == NULL) {
        printf("Could not find MainApp class!\n");
        return;
    }

    // Find the callbackFromNative method in MainApp
    jmethodID callbackMethod = (*env)->GetStaticMethodID(env, mainClass, "callbackFromNative", "(Ljava/lang/Runnable;)V");
    if (callbackMethod == NULL) {
        printf("Could not find callbackFromNative method!\n");
        return;
    }

    // Pass the Runnable object directly to callbackFromNative
    printf("Calling Java callback method from C...\n");
    (*env)->CallStaticVoidMethod(env, mainClass, callbackMethod, runner);
}
