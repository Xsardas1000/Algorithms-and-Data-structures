//
//  ht5-2.cpp
//  sphere
//
//  Created by Максим on 22.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct TreeNode {
    int freq;
    TreeNode *left, *right;
    TreeNode(int f = 0, TreeNode *l = NULL, TreeNode *r = NULL) : freq(f), left(l), right(r) {};
};

struct binary_heap {
    TreeNode *body;
    int bodysize;
    int numnodes;
    binary_heap(int maxsize);
    ~binary_heap();
    void swap(int a, int b);
    TreeNode extractMin();
    int insert(TreeNode node);
    void heapify(int index);
    int increasePriority(int index, int shot, int score);
    
};

binary_heap::binary_heap(int maxsize) {
    body = new TreeNode[maxsize + 1];
    bodysize = maxsize;
    numnodes = 0;
}

binary_heap::~binary_heap() {
}

void binary_heap::swap(int a, int b) {
    TreeNode tmp = body[a];
    body[a] = body[b];
    body[b] = tmp;
}

TreeNode binary_heap::extractMin() {
    if (numnodes == 0) return body[0];
    TreeNode p = body[1];
    body[1] = body[numnodes--];
    heapify(1);
    return p;
}

int binary_heap::insert(TreeNode node) {
    if (numnodes > bodysize) {
        return -1;
    }
    body[++numnodes] = node;
    for (int i = numnodes; i > 1 && body[i].freq < body[i/2].freq; i /= 2) {
        swap(i, i/2);
    }
    return numnodes;
}

void binary_heap::heapify(int index) {
    for (;;) {
        int left = index + index; int right = left + 1;
        int largest = index;
        if (left <= numnodes &&
            body[left].freq < body[index].freq)
            largest = left;
        if (right <= numnodes && body[right].freq < body[largest].freq)
            largest = right;
        if (largest == index) break;
        swap(index, largest);
        index = largest;
    }
}

void print(TreeNode *tree, string str = "") {
    if (tree->left != NULL) {print(tree->left,str+"0");}
    if (tree->right != NULL) {print(tree->right,str+"1");}
    if (tree->left == NULL && tree->right == NULL) cout << str << " " << tree->freq << endl;
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    binary_heap heap(N);
    for (int i = 0; i < N; ++i) {
        int freq;
        cin >> freq;
        heap.insert(freq);
    }
    for (int i = 0; i < N - 1; ++i) {
        TreeNode *n1 = new TreeNode;
        TreeNode *n2 = new TreeNode, *tmp;
        *n1 = heap.extractMin();
        *n2 = heap.extractMin();
        if (n1->freq > n2->freq) { tmp = n1; n1 = n2; n2 = tmp; }
        TreeNode newNode = TreeNode(n1->freq+n2->freq, n1, n2);
        heap.insert(newNode);
    }
    TreeNode tree = heap.extractMin();
    print(&tree);
    return 0;
}
