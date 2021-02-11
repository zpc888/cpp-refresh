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

	static void polymorphOn(A a, int expectX, int expectY) {
		resetValue();
		a.bar();
		a.foo();

		System.out.printf("Verify: expect x = %3d; y = %2d%n", expectX, expectY);
		System.out.printf("        actual x = %3d; y = %2d  ==> [%s]%n", x, y, x == expectX && y == expectY ? "OK" : "ERROR");
	}

	public static void main(String[] args) {
		polymorphOn( new A(), 10, 18 );
		polymorphOn( new B(), 108, 18 );
		polymorphOn( new C(500), 608, 18 );
	}
}

