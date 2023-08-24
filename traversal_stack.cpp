#include <iostream>       
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct node {
    int data;
    node* left, * right;
};

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preOrder(node* root) {
    if (root == nullptr) return;
    stack <node*>h;
    h.push(root);
    while (!h.empty()) {
        node* t = h.top();
        h.pop();
        cout << t->data << " ";
        if (t->right != nullptr) h.push(t->right);
        if (t->left != nullptr) h.push(t->left);
    }
}

void postOrder(node* root) {
    if (root == nullptr) return;

    stack<node*>stk;
    stack<node*>io_stk;
    stk.push(root);
    while (!stk.empty()) {
        node* current = stk.top();
        stk.pop();
        io_stk.push(current);
        if (current->left != nullptr) stk.push(current->left);
        if (current->right != nullptr) stk.push(current->right);
    }
    while (!io_stk.empty()) {
        cout << io_stk.top()->data << " ";
        io_stk.pop();
    }
}


void levelOrder(node* root) {
    if (root == nullptr) return;
    queue <node*> h;
    h.push(root);
    while (!h.empty()) {
        node* t = h.front();
        cout << t->data << " ";
        h.pop();
        if (t->left != nullptr) h.push(t->left);
        if (t->right != nullptr) h.push(t->right);
    }
}
