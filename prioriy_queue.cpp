#include <iostream> 
#include <vector>      
using namespace std;
struct node {
    int data;
    node* left, * right;
};
template <typename T>
class PQ {
private:
    vector <T> heap;
    int parent(int i) {
        return (i - 1) / 2;
    }
    int leftchild(int i) {
        return 2 * i + 1;
    }
    int rightchild(int i) {
        return 2 * i + 2;
    }

    void siftup(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
        }
    }
    void siftdown(int i) {
        int minindex = i,left = leftchild(i), right = rightchild(i);
    }
};