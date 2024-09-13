#include <iostream>
#include <string>

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

    void add(string m) {
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
    }

    string pop() {

    }
};

int main() {
    return 0;
}