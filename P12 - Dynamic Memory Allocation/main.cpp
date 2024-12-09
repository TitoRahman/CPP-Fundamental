#include <iostream>
#include <vector>

using namespace std;
class A {
    public:
        int a;
        A(int a){
            this->a = a;
        }
};

// void addA(int *a){
//     *a = *a + 1;
// }

// int addA(int a){
//     return a + 1;
// }

int main() {
    vector<A> list;
    list.push_back(A(1));
    list.push_back(A(2));
    list[0].a;
    // int *c;
    // int a = 10;
    // int b = 10;
    // c = &a;
    // c += 4;
    // addA(&a);
    // b = addA(b);
    // cout << a << endl;
    // cout << b << endl;
    // addA(&a);
    // b = addA(b);
    // cout << a << endl;
    // cout << b << endl;
    // addA(&a);
    // b = addA(b);
    // cout << a << endl;
    // cout << b << endl;
    // addA(&a);
    // b = addA(b);
    // cout << a << endl;
    // cout << b << endl;
    return 0;
}