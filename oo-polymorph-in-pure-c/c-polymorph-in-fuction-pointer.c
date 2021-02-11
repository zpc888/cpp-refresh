#include <stdio.h>
#include <stdlib.h>

int x = 0;
int y = 0;

// ---------------- mimic A.java 
struct A_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
};
void A_bar (void* this) { x += 2; }
void A_foo (void* this) { y += 10; }
struct A_class A_class_table = {A_bar, A_foo};

struct A {
    struct A_class* class;
};
struct A* new_A() {
    struct A* obj = malloc(sizeof (struct A));
    obj->class = & A_class_table;
    return obj;
}

// ---------------- mimic B.java 
struct B_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
    void (* woo) (void* this);
};
void B_bar (void* this) { x += 100; }
void B_woo (void* this) { y += 10000; }
struct B_class B_class_table = {B_bar, A_foo, B_woo};

struct B {
    struct B_class* class;
};
struct B* new_B() {
    struct B* obj = malloc(sizeof (struct B));
    obj->class = & B_class_table;
    return obj;
}

// ---------------- mimic C.java 
struct C_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
};
struct C {
    struct C_class* class;
    int step;
};
void C_bar (void* this) { 
    struct C* me = this;
    x += me->step; 
    B_bar(me);
}
struct C_class C_class_table = {C_bar, A_foo};

struct C* new_C(int step) {
    struct C* obj = malloc(sizeof (struct C));
    obj->class = & C_class_table;
    obj->step = step;
    return obj;
}

// ------------ main flow
void resetValue() {
    x = 8; y = 8;
}

void polymorphOn(struct A* a, int expectX, int expectY) {
    resetValue();
    a->class->bar(a);
    a->class->foo(a);
    printf("Verify: expect x=%3d; y=%2d\n", expectX, expectY);
    printf("        actual x=%3d; y=%2d ==> [%s]\n", x, y, x == expectX && y == expectY ? "OK" : "ERROR");
}

int main() {
    polymorphOn(new_A(),     10, 18);
    polymorphOn(new_B(),    108, 18);
    polymorphOn(new_C(500), 608, 18);
}
