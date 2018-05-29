javah -d "生成头文件的位置" "类全限定名称"

javap -s 查看签名信息

注意：
JNIEnv 不能在底层多线程间共享
jobject 指针不能在多个线程中共享

jni中引用的java对象的生命周期：
Java对象做为引用被传递到本地方法中，所有这些Java对象的引用都有一个共同的父类型jobject(相当于java中的 Object类是所有类的父类一样)。 这些对象引用都有其生命周期。在JNI中对Java对象的引用根据生命周期分为:全局引用，局部引用、弱全局引用
1、Local Reference 本地引用，
函数调用时传入jobject或者jni函数创建的jobejct，都是本地引用.
其特点就是一旦JNI层函数返回，jobject就被垃圾回收掉，所以需要注意其生命周期。可以强制调用DeleteLocalRef进行立即回收。
jstring pathStr = env->NewStringUTF(path)
env->DeleteLocalRef(pathStr);

2、Global Reference 全局引用 ，这种对象如不主动释放，它永远都不会被垃圾回收
创建： env->NewGlobalRef(obj);
释放： env->DeleteGlobalRef(obj)
若要在某个 Native 代码返回后，还希望能继续使用 JVM 提供的参数, 或者是过程中调用 JNI 函数的返回值（比如 g_mid）， 则将该对象设为 global reference，以后只能使用这个 global reference；若不是一个 jobject，则无需这么做。

3、Weak Global Reference 弱全局引用
一种特殊的 Global Reference ,在运行过程中可能被垃圾回收掉，所以使用时请务必注意其生命周期及随时可能被垃圾回收掉,比如内存不足时。
使用前可以利用JNIEnv的 IsSameObject 进行判定它是否被回收
env->IsSameObject(obj1,obj2)