#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to execute the Runnable in another JVM
JNIEXPORT void JNICALL Java_com_example_jni_Host_sendRunnable(JNIEnv *env, jclass cls, jobject runnable) {
    // Launch a new JVM process
    printf("Launching Target JVM...\n");

    char command[1024];
    snprintf(command, sizeof(command), "java -cp build com.example.jni.Target");

    FILE *fp = popen(command, "w");
    if (fp == NULL) {
        printf("Failed to launch Target JVM\n");
        return;
    }

    // Simulate sending data (Runnable is passed here)
    fprintf(fp, "Simulated transfer of Runnable\n");
    pclose(fp);

    printf("Finished communicating with Target JVM\n");
}
