package com.example.jni;

public class MainApp {
    static {
        // Load the native library
        System.loadLibrary("HelloJNI");
    }

    // Native method declaration
    private native static void sayHello(Runnable runner);

    public static void main(String[] args) {
        System.out.println("Calling native method from Java...");

        // Pass a Runnable to the native method
        sayHello(() -> {
            System.out.println("Hello from Java Runner!");
        });
    }

    // Called back by C
    public static void callbackFromNative(Runnable runnable) {
        System.out.println("Callback from C to Java completed!");
        System.out.println("Manually invoking the Runnable's run() method:");
        runnable.run(); // Manually call the run() method
    }
}
