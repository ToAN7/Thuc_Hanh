#include <iostream>
#include <vector>

using namespace std;

long long fib1(int x) {
    if (x <= 2) return 1;
    else return fib1(x-1) + fib1(x-2);
}

long long fib2(int x) {
    vector<long long> f;
    f.push_back(0);
    f.push_back(1);
    for (int i = 2; i <= x; i++) {
        f.push_back(f[i-1] + f[i-2]);
    }

    return f[x];
}

int main() {
    cout << fib2(45) << endl;
    cout << fib1(45) << endl;
}