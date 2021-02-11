class A {
	void bar() { JavaPolymorph.x += 2; }
	void foo() { JavaPolymorph.y += 10; }
}

class B extends A {
	void bar() { JavaPolymorph.x += 100; }
	void woo() { JavaPolymorph.y += 10000; }
}

class C extends B {
	int step;
	C(int step) { this.step = step; }
	void bar() {
		JavaPolymorph.x += step;
		super.bar();
	}
}

public class JavaPolymorph {
	static int x; 
	static int y;

	static void resetValue() { x = 8; y = 8; }

	static void dispatchOn(A a) {
		a.bar();
		a.foo();
	}
	public static void main(String[] args) {
		resetValue();
		dispatchOn( new A() );
		System.out.printf("expect: x = %3d; y = %3d%n", 10, 18);
		System.out.printf("actual: x = %3d; y = %3d  ==> [%s]%n", JavaPolymorph.x, JavaPolymorph.y, JavaPolymorph.x == 10 && JavaPolymorph.y == 18 ? "OK" : "ERROR");
		resetValue();
		dispatchOn( new B() );
		System.out.printf("expect: x = %3d; y = %3d%n", 108, 18);
		System.out.printf("actual: x = %3d; y = %3d  ==> [%s]%n", JavaPolymorph.x, JavaPolymorph.y, JavaPolymorph.x == 108 && JavaPolymorph.y == 18 ? "OK" : "ERROR");
		resetValue();
		dispatchOn( new C(500) );
		System.out.printf("expect: x = %3d; y = %3d%n", 608, 18);
		System.out.printf("actual: x = %3d; y = %3d  ==> [%s]%n", JavaPolymorph.x, JavaPolymorph.y, JavaPolymorph.x == 608 && JavaPolymorph.y == 18 ? "OK" : "ERROR");
	}
}

