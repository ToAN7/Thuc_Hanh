#include <iostream>
#include <vector>

/*
Cho một mảng nguyên gồm n phần tử khác nhau
Nhập vào k để xuất ra màn hình tất cả cách để lấy k phần tử từ số nguyên đó
*/

using namespace std;

vector<int> arr;
vector<int> out;

void output() {
    for (auto x: out) {
        cout << x << ' ';
    }
    cout << endl;
}

bool ifHave(int x) {
    for(int i = 0; i < out.size(); i++) {
        if (out[i] == x) return true;
    }
    return false;
}

void process(int n, int idx = 0) {
    for (int i = idx; i < n; i++) {
        if(idx == out.size()) {
            output();
        }
        else {
            if (!ifHave(arr[i])) {
                out[idx] = arr[i];
                process(n, idx + 1);
                out[idx] = 0;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    arr.resize(n, 0);
    out.resize(k, 0);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%100;
    }

    for (auto x: arr) {
        cout << x << ' ';
    }
    cout << endl;

    process(n);

}