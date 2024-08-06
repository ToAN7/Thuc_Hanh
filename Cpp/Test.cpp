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
        if (p == 0) {
            p = new node(a);
        }
        else {
            if (p->oneBook.id < a.id) {
                insert(a, p->right);
            }
            else if (p->oneBook.id > a.id) {
                insert(a, p->left);
            }
            else return;
        }
    }
};

int main() {
    lib nihahaha;
    book a("he","hi","ha", 10);
    nihahaha.insert(a , nihahaha.r);
    cout << "Hello Negga Ton\n";
}