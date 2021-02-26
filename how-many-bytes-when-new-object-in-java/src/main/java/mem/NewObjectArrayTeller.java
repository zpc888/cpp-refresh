package mem;

import org.openjdk.jol.info.ClassLayout;

public class NewObjectArrayTeller {
    public static void main(String[] args) {
        int len = 10;
        if (args.length == 1) {
            try {
                len = Integer.parseInt(args[0]);
            } catch (NumberFormatException nfe) {
                len = 10;
            }
        }
        Object[] objs = new Object[len];
        System.out.printf("Array Length = %d, its class layout is: %n", len);
        System.out.println(ClassLayout.parseInstance(objs).toPrintable());
    }
}