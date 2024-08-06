#include <iostream>
#include <string>

using namespace std;

struct book {
    string id;
    string title;
    string content;
    int rating;
    book(string i = "", string t = "", string ctn = "", int ra = 0) {
        id = i;
        title = t;
        content = ctn;
        rating = ra;
    }
};

struct node {
    book oneBook;
    node* left;
    node* right;
    node(book data, node*l = NULL, node*r = NULL) {
        oneBook = data;
        left = l;
        right = r;
    }
};

struct lib {
    node *r = 0;

    void insert(book a, node *& p) {
        if (p == 0) p = new node(a);
        else {
            if (p->oneBook.id < a.id) insert(a, p->right);
            else if (p->oneBook.id > a.id) insert(a, p->left);
            else return;
        }
    }

    void delByMerging(book a) {
        node* tmp,* node,* p = r,* pre = NULL;
        while (p != NULL && p->oneBook.id != a.id) {
            pre = p;
            if (p->oneBook.id < a.id) p = p->right;
            else p = p->left;
        }
        node = p;
        if (p != NULL && p->oneBook.id == a.id) {
            if (node->right == NULL) node = node->left;
            else if (node->left == NULL) node = node->right;
            else {
                tmp = node->left;
                while(tmp->right != NULL) tmp = tmp->right;
                tmp->right = node->right;
                node = node->left;
            }
            if (p == r) r = node;
            else if (pre->left == p) pre->left = node;
            else pre->right = node;
            delete p;
        }
        else if (r != NULL) cout << "Found nothing beside NeggaTon\n";
        else cout << "THIS IS EMPTY NEGGATON!!!!!!\n";
    }
};

int main() {
    lib nihahaha;
    //book a("he","hi","ha", 10);
    //nihahaha.insert(a , nihahaha.r);
    //book b("hN","hu","ha", 10);
    //nihahaha.insert(b , nihahaha.r);
    book c("hr","he","ha", 10);
    //nihahaha.insert(c , nihahaha.r);
    //book d("hy","ho","ha", 10);
    //nihahaha.insert(d , nihahaha.r);

    nihahaha.delByMerging(c);

    cout << "Hello NeggaTon\n";
}