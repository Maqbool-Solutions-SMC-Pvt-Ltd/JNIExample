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

    // Get the class of the Runnable object
    jclass runnableClass = (*env)->GetObjectClass(env, runner);

    // Get the 'run' method ID of the Runnable class
    jmethodID runMethod = (*env)->GetMethodID(env, runnableClass, "run", "()V");
    if (runMethod == NULL) {
        printf("Could not find 'run' method!\n");
        return;
    }

    // Call the 'run' method on the Runnable object
    printf("Calling Runnable's run() method from C...\n");
    (*env)->CallVoidMethod(env, runner, runMethod);

    // Call the Java callback method
    jclass mainClass = (*env)->FindClass(env, "com/example/jni/MainApp");
    if (mainClass == NULL) {
        printf("Could not find MainApp class!\n");
        return;
    }

    jmethodID callbackMethod = (*env)->GetStaticMethodID(env, mainClass, "callbackFromNative", "()V");
    if (callbackMethod == NULL) {
        printf("Could not find callbackFromNative method!\n");
        return;
    }

    printf("Calling Java callback method from C...\n");
    (*env)->CallStaticVoidMethod(env, mainClass, callbackMethod);
}
