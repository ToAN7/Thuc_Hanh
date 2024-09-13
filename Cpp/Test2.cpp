#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

struct SLLNode {
    string mon;
    SLLNode *next;
    SLLNode(string m = "", SLLNode*n = 0) {
        mon = m;
        next = n;
    }
};

struct queue {
    SLLNode* head = 0;
    int size = 0;

    void push(string m) {
        SLLNode* cur = head;
        SLLNode* pre = 0;

        while (cur != 0) {
            pre = cur;
            cur = cur->next;
        }

        if (pre != 0) {
            pre->next = new SLLNode(m);
        }
        else {
            head = new SLLNode(m);
        }
        size++;
    }

    string pop() {
        string m = head->mon;
        SLLNode* cur = head;
        head = head->next;

        delete cur;
        size--;
        return m;
    }
};

struct stack {
    SLLNode* head;
    int size = 0;

    void push(string m) {
        head = new SLLNode(m,head);
        size++;
    }

    string pop() {
        if(!size) return "";
        string m = head->mon;
        SLLNode*temp = head;
        head = head->next;
        delete temp;
        size--;
        return m;
    }
};

int arr[10] = {10, 210, 41, 61, 62, 21, 5, 6, 9, 11};

int linearSearch(int x) {
    auto start = chrono::high_resolution_clock::now();
    int i = 0;
    for (i; i < 10; i++) {
        if (arr[i] == x) return i;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Thoi gian thuc thi: " << duration.count() << " ms" << endl;
    return -1;
}

int binarySearch(int x) { 
    int left = 0;
    int right = 10-1;
    int mid = 0;
    sort(arr, (arr+9));// Mang truoc khi vao binarySearch phai duoc sap xep nen ham sort chi la phu
    auto start = chrono::high_resolution_clock::now();
    while (left <= right) {
        mid = (right - left) / 2;

        if (x == arr[mid]) return mid;
        else if (x < arr[mid]) right = mid;
        else left = mid + 1;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Thoi gian thuc thi: " << duration.count() << " ms" << endl;
    return -1;
}

int main() {
    int x;
    cout << "---------------------------\n";
    cout << "1. Tim kiem tuan tu\n";
    cout << "2. Tim kiem nhi phan\n";
    cout << "---------------------------\n";
    cin >> x;
    cout << "1. Tim kiem tuan tu: " << linearSearch(x) << endl;
    cout << "2. Tim kiem nhi phan: " << binarySearch(x) << endl;
    return 0;
}