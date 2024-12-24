package com.example.jni;

public class Target {
    public static void main(String[] args) {
        System.out.println("Target JVM running...");
        System.out.println("Runnable received: Executing...");
        Runnable task = () -> System.out.println("Runnable executed successfully in Target JVM.");
        task.run();
    }
}
