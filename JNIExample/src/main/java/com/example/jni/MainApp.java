package com.example.jni;

public class MainApp {
    static {
        // Load the native library
        System.loadLibrary("HelloJNI");
    }

    // Native method declaration
    private native static void sayHello(String message);

    public static void main(String[] args) {
        System.out.println("Calling native method from Java...");
        sayHello("Hello from Java!");
    }

    // Called back by C
    public static void callbackFromNative(String response) {
        System.out.println("Callback from C: " + response);
    }
}
