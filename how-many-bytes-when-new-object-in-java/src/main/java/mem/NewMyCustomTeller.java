package mem;

import org.openjdk.jol.info.ClassLayout;

public class NewMyCustomTeller {
    public static void main(String[] args) {
        Object obj = new A();
        System.out.println(ClassLayout.parseInstance(obj).toPrintable());
    }
}

class A {
    byte i;
}