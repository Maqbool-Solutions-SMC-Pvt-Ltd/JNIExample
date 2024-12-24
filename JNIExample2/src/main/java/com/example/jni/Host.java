package com.example.jni;

public class Host {
    static {
        System.loadLibrary("nativehandler"); // Load native library
    }

    // Declare the native method
    public static native void sendRunnable(Runnable runnable);

    public static void main(String[] args) {
        Runnable task = () -> System.out.println("Runnable executed in Target JVM");

        System.out.println("Passing Runnable to JNI...");
        sendRunnable(task);
    }
}

