package mem;

import org.openjdk.jol.info.ClassLayout;

public class NewComplexTeller {
    public static void main(String[] args) {
        Object obj = new D();
        ((D)obj).aObj = new E();
        System.out.println(ClassLayout.parseInstance(obj).toPrintable());
    }
}

class B {
    byte aByte;
    Object aObj;
    int method1() { return 1; }
}

class C extends B {
    byte aByte;
    String aString;
    void method2() {System.out.println("hello world");}
}

class D extends C {
    short aShort;
    int aInt;
    long aLong;
    char aChar;
    float aFloat;
    double aDouble;
    boolean aBoolean;
    E  aObj;
    String  aString = "abcdefg";
    int method1() { return 2; }
    void method3() {System.out.println("hi world");}
}

class E {
    byte i;
    int method4() { return 4; }
}