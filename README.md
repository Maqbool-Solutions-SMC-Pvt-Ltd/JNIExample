# JNIExample
JNI Examples using Java 

# [Commands to test sample in Linux](commands.txt)

```
mkdir JNIExample

cd JNIExample
mkdir -p src/main/java/com/example/jni
mkdir -p src/main/c
mkdir libs
mkdir build

javac -d ./build -h src/main/c src/main/java/com/example/jni/MainApp.java

javac -d ./build src/main/java/com/example/jni/*.java
gcc -shared -fPIC -o libs/libHelloJNI.so -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" src/main/c/HelloJNI.c

java -Djava.library.path=libs -cp build com.example.jni.MainApp
```