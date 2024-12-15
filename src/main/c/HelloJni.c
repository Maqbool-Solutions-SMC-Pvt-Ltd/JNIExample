#include <jni.h>
#include <stdio.h>
#include "com_example_jni_MainApp.h"

JNIEXPORT void JNICALL Java_com_example_jni_MainApp_sayHello
  (JNIEnv *env, jclass cls, jstring message) {
    // Convert Java string to C string
    const char *nativeMessage = (*env)->GetStringUTFChars(env, message, NULL);
    printf("C received: %s\n", nativeMessage);

    // Release the Java string
    (*env)->ReleaseStringUTFChars(env, message, nativeMessage);

    // Call back a static Java method
    jclass mainClass = (*env)->FindClass(env, "com/example/jni/MainApp");
    jmethodID callbackMethod = (*env)->GetStaticMethodID(env, mainClass, "callbackFromNative", "(Ljava/lang/String;)V");

    if (callbackMethod == NULL) {
        printf("Could not find callback method.\n");
        return;
    }

    jstring response = (*env)->NewStringUTF(env, "Hello from C!");
    (*env)->CallStaticVoidMethod(env, mainClass, callbackMethod, response);
}
