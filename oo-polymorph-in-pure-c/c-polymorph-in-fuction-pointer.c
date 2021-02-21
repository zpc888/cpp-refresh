#include <stdio.h>
#include <stdlib.h>

// ---------------- mimic A.java 
struct A_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
};
struct A {
    struct A_class* class;
    int x;
    int y;
};
void A_bar (void* this) { 
    struct A* me = this;
    me->x += 2; 
}
void A_foo (void* this) { 
    struct A* me = this;
    me->y += 10; 
}
struct A_class A_class_table = {A_bar, A_foo};
struct A* new_A() {
    struct A* obj = malloc(sizeof (struct A));
    obj->class = & A_class_table;
    obj->x = 0;
    obj->y = 0;
    return obj;
}

// ---------------- mimic B.java 
struct B_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
    void (* woo) (void* this);
};
struct B {
    struct B_class* class;
    int x;
    int y;
};
void B_bar (void* this) { 
    struct B* me = this;
    me->x += 100; 
 }
void B_woo (void* this) { 
    struct B* me = this;
    me->y += 10000; 
}
struct B_class B_class_table = {B_bar, A_foo, B_woo};
struct B* new_B() {
    struct B* obj = malloc(sizeof (struct B));
    obj->class = & B_class_table;
    obj->x = 0;
    obj->y = 0;
    return obj;
}

// ---------------- mimic C.java 
struct C_class {
    void (* bar) (void* this);
    void (* foo) (void* this);
};
struct C {
    struct C_class* class;
    int x;
    int y;
    int step;
};
void C_bar (void* this) { 
    struct C* me = this;
    me->x += me->step; 
    B_bar(me);
}
struct C_class C_class_table = {C_bar, A_foo};

struct C* new_C(int step) {
    struct C* obj = malloc(sizeof (struct C));
    obj->class = & C_class_table;
    obj->step = step;
    obj->x = 0;
    obj->y = 0;
    return obj;
}

// ------------ main flow
void polymorphOn(struct A* a, int expectX, int expectY) {
    a->class->bar(a);
    a->class->foo(a);
    printf("Verify: expect x=%3d; y=%2d\n", expectX, expectY);
    printf("        actual x=%3d; y=%2d ==> [%s]\n", 
            a->x, a->y, a->x == expectX && a->y == expectY ? "OK" : "ERROR");
}

int main() {
    struct A* a = new_A();
    struct B* b = new_B();
    struct C* c = new_C(500);
    polymorphOn(a,      2, 10);
    polymorphOn(b,    100, 10);
    polymorphOn(c, 600, 10);
    // valgrind to detect memory leak
    free(c);
    free(b);
    free(a);
}
