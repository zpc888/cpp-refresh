class A {
    x: number = 0;
    y: number = 0;
    bar(): void { this.x += 2; }
    foo(): void { this.y += 10; }
}

class B extends A {
    bar(): void { this.x += 100; }
    woo(): void { this.y += 10000; }
}

class C extends B {
	constructor(private step: number) {super();}

    bar(): void { 
		this.x += this.step; 
		super.bar(); 
	}
}

const polymorphOn = (a: A, expectX: number, expectY: number) => {
	a.bar();
	a.foo();
	console.log(`verify: expect x = ${expectX}; y = ${expectY}`);
	console.log(`        actual x = ${a.x}; y = ${a.y}  ==> [${a.x === expectX && a.y === expectY ? 'OK': 'ERROR'}]`);
}

polymorphOn( new A, 2, 10 );
polymorphOn( new B, 100, 10 );
polymorphOn( new C(500), 600, 10 );
