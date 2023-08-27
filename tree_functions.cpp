#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T>
struct node {
	T data;
	node* left, * right;
	node(T val) : data(val), left(nullptr), right(nullptr) {};
	void preorder(node<T>* root) {
		if (root == nullptr) return;
		cout << root->data << " ";
		preorder(root->right);
		preorder(root->left);
	}
	void inorder(node<T>* root) {
		if (root == nullptr) return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	void postorder(node<T>* root) {
		if (root == nullptr) return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	int height(node<T>* root) {
		if (root == nullptr) return -1;

		int lheight = height(root->left), rheight = height(root->right);
		return max(lheight, rheight) + 1;
	}
	int depth(node<T>* root, T value) {
		if (root == nullptr) return -1;
		int dist = -1;
		if (root->data == value || dist = depth(root->left) >= 0 || dist = depth(root->right) {
			return dist + 1;
		}
		return dist;
	}
};

template <typename T>
void insertNode(node<T>* root, T value) {
	node<T>* New = new node<T>(value);

	stack<node<T>*>q;
	q.push(root);
	while (!q.empty()) {
		node<T>* temp = q.top();
		q.pop();
		if (temp->right == nullptr) {
			temp->right = New;
			break;
		}
		else q.push(temp->right);

		if (temp->left == nullptr) {
			temp->left = New;
			break;
		}
		else q.push(temp->left);
	}
}
