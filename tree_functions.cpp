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

int height(node* tree) {
    if (tree == nullptr) return -1;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    return max(lheight, rheight) + 1;
}

int findDepth(node* root, int x) {
    if (root == nullptr) 
        return -1;
    int dist = -1;
    if ((root->data == x)

        || (dist = findDepth(root->left, x)) >= 0

        || (dist = findDepth(root->right, x)) >= 0) {

        return dist + 1;
    }
        return dist;
}

void inOrder(node* root) {
    if (root == nullptr) return;

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

void preOrder(node* root) {
    if (root == nullptr)return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}