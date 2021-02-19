class A {
	int x = 0;
	int y = 0;

	void bar() { x += 2; }
	void foo() { y += 10; }
}

class B extends A {
	void bar() { x += 100; }
	void woo() { y += 10000; }
}

class C extends B {
	int step;
	C(int step) { this.step = step; }
	void bar() {
		x += step;
		super.bar();
	}
}

public class JavaPolymorph {
	static void polymorphOn(A a, int expectX, int expectY) {
		a.bar();
		a.foo();

		System.out.printf("Verify: expect x = %3d; y = %2d%n", expectX, expectY);
		System.out.printf("        actual x = %3d; y = %2d  ==> [%s]%n", 
				a.x, a.y, a.x == expectX && a.y == expectY ? "OK" : "ERROR");
	}

	public static void main(String[] args) {
		polymorphOn( new A(), 2, 10 );
		polymorphOn( new B(), 100, 10 );
		polymorphOn( new C(500), 600, 10 );
	}
}

