#include <iostream>
using namespace std;
class A {
protected:
    int a;
public:
    A(int x = 1) : a(x) {
        cout << "Constructor A" << endl;
    }
};
class B : public A {
protected:
    int b;
public:
    B(int x = 1, int y = 2)
        : A(x), b(y) {
        cout << "Constructor B" << endl;
    }
};
class C : public A {
protected:
    int c;
public:
    C(int x = 1, int y = 3)
        : A(x), c(y) {
        cout << "Constructor C" << endl;
    }
};
class D : public B, public C {
private:
    int d;
public:
    D(int x, int y, int z, int k)
        : B(x, y), C(x, z), d(k) {
        cout << "Constructor D" << endl;
    }
    void show() {
        cout << "B::A::a = " << B::a << endl;
        cout << "C::A::a = " << C::a << endl;
        cout << "d = " << d << endl;
    }
};
class AV {
protected:
    int a;
public:
    AV(int x = 10) : a(x) {
        cout << "Constructor AV" << endl;
    }
};
class BV : virtual public AV {
protected:
    int b;
public:
    BV(int x = 1, int y = 2)
        : AV(x), b(y) {
        cout << "Constructor BV" << endl;
    }
};
class CV : virtual public AV {
protected:
    int c;
public:
    CV(int x = 1, int y = 3)
        : AV(x), c(y) {
        cout << "Constructor CV" << endl;
    }
};
class DV : public BV, public CV {
private:
    int d;
public:
    DV(int x, int y, int z, int k)
        : AV(x), BV(x, y), CV(x, z), d(k) {
        cout << "Constructor DV" << endl;
    }
    void show() {
        cout << "a = " << a << endl;
        cout << "d = " << d << endl;
    }
};
int main() {
  cout << "===== WITHOUT VIRTUAL =====" << endl;
    D obj1(1, 2, 3, 4);
    obj1.show();
    cout << "Size A = " << sizeof(A) << endl;
    cout << "Size B = " << sizeof(B) << endl;
    cout << "Size C = " << sizeof(C) << endl;
    cout << "Size D = " << sizeof(D) << endl;
    cout << endl;
    cout << "===== WITH VIRTUAL =====" << endl;
    DV obj2(10, 20, 30, 40);
    obj2.show();
    cout << "Size AV = " << sizeof(AV) << endl;
    cout << "Size BV = " << sizeof(BV) << endl;
    cout << "Size CV = " << sizeof(CV) << endl;
    cout << "Size DV = " << sizeof(DV) << endl;
    return 0;
}
