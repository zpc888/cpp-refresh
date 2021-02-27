package mem;

import org.openjdk.jol.info.ClassLayout;

public class NewComplexTeller {
    public static void main(String[] args) {
        Object obj = new C();
        ((C)obj).aObj = new D();
        System.out.println(ClassLayout.parseInstance(obj).toPrintable());
    }
}

class B {
    byte aByte;
}

class C extends B {
    short aShort;
    int aInt;
    long aLong;
    char aChar;
    float aFloat;
    double aDouble;
    boolean aBoolean;
    D  aObj;
    String  aString = "abcdefg";
}

class D {
    byte i;
}