//
//  avl.cpp
//  sphere
//
//  Created by Максим on 19.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <string>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <set>
using namespace std;

struct AVLNode {
    AVLNode *left, *right;
    string key;
    int height;
    AVLNode(string const &_key) : key(_key) {
        left = right = NULL;
        height = 1;
    }
    int getBalanceFactor() const {
        int r = right == NULL ? 0 : right->height;
        int l = left == NULL ? 0 : left->height;
        return r - l;
    }
    void fix() {
        int r = right == NULL ? 0 : right->height;
        int l = left == NULL ? 0 : left->height;
        height = (r > l ? r : l) + 1;
    }
    
    AVLNode *rotateLeft() {
        AVLNode *t = right;
        right = t->left;
        t->left = this;
        fix();
        t->fix();
        return t;
    }
    
    AVLNode *rotateRight() {
        AVLNode *t = left;
        left = t->right;
        t->right = this;
        fix();
        t->fix();
        return t;
    }

    AVLNode *balance() {
        fix();
        switch (getBalanceFactor()) {
            case -2:
                if (left->getBalanceFactor() > 0) {
                    left = left->rotateLeft();
                }
                return rotateRight();
            case 2:
                if (right->getBalanceFactor() < 0) {
                    right = right->rotateRight();
                }
                return rotateLeft();
            default:
                return this;
        }
    }

    
    AVLNode *insert(string const &_key) {
        if (_key < key)
            left = left == NULL ? new AVLNode(_key) : left->insert(_key);
        else
            right = right == NULL ? new AVLNode(_key) : right->insert(_key);
        return balance();
    }
    
    void print(int level) {
        if (right != NULL) right->print(level+1);
        for (int i = 0; i < level; i++)
            printf("       ");
        printf("%s\n", key.c_str());
        if (left != NULL) left->print(level+1);
    }
    
    /*AVLNode *findMinimum() {
        return left != NULL ? left->findMinimum() : this;
    }
    
    AVLNode *removeMinimum() {
        if (left == NULL) return right;
        left = left->removeMinimum();
        return balance();
    }
    
    static AVLNode *remove(AVLNode *p, string const &_key) {
        if (p == NULL) return NULL;
        if (_key < p->key) {
            p->left = remove(p->left, _key);
            return p->balance();
        } else if (_key > p->key) {
            p->right = remove(p->right, _key);
            return p->balance();
        } else {
            AVLNode *l = p->left;
            AVLNode *r = p->right;
            delete p;
            if (r == NULL) return l;
            AVLNode *min = r->findMinimum();
            min->right = r->removeMinimum();
            min->left = l;
            return min->balance();
        }
    }*/
};

struct AVLTree {
    AVLNode *root;
    AVLTree() {
        root = NULL;
    }
    void print() const {
        if (root != NULL) root->print(0);
    }
    
    bool insert(string const &_key) {
        if (root == NULL) root = new AVLNode(_key);
        else root = root->insert(_key);
        return true;
    }
    
    /*bool remove(string const &_key) {
        root = AVLNode::remove(root, _key);
        return true;
    }*/
};

/*
int main() {
    AVLTree t;
    t.insert("abra");
    t.insert("cadabra");
    t.insert("foo");
    t.insert("bar");
    t.print();
    printf("===================================\n");
    t.root = t.root -> rotateLeft();
    t.root = t.root -> rotateRight();
    t.print();
    
    printf("===================================\n");
    t.insert("aaa");
    t.print();
    
    printf("===================================\n");
    t.insert("bad");
    t.print();

    //t.remove("cadabra");
    //t.print();
}*/

int main() {
    AVLTree t;
    clock_t s1 = clock();
    for (int i = 0; i < 1000000; i++) {
        string s = std::to_string(i);
        t.insert(s);
    }
    clock_t e1 = clock();
    
    set<string> se1;
    clock_t s2 = clock();
    for (int i = 0; i < 1000000; i++) {
        string s = std::to_string(i);
        se1.insert(s);
    }
    clock_t e2 = clock();
    
    printf("AVL=%lld SET=%lld\n", (long long)e1 - s1, (long long)e2 - s2);
}
