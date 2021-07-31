#include <iostream>

using namespace std;

int f() {
    return 1;
}

const int i = f();

int main(void) {
    cout << i << endl;
    return 0;
}