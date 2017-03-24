//
//  sort.cpp
//  sphere
//
//  Created by Максим on 05.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
    node *left, *right;
    char op;
    double val;
    node (char myop) {
        left = right = NULL;
        op = myop;
        val = 0;
    }
    node (double myval) {
        left = right = NULL;
        op = '@';
        val = myval;
    }
};

double evaluation (node *root) {
    if (root -> left != NULL) {
        evaluation(root -> left);
    }
    if (root -> right != NULL) {
        evaluation(root -> right);
    }
    

    if (root -> op != '@') {
        double res;
        switch (root -> op) {
            case '+':
                return evaluation(root -> left) + evaluation(root -> right);
            case '-':
                return evaluation(root -> left) - evaluation(root -> right);
            case '*':
                return evaluation(root -> left) * evaluation(root -> right);
            case '/':
                return evaluation(root -> left) / evaluation(root -> right);
            default:
                break;
        }
        return res;
    } else {
        return root -> val;
    }
}

void delete_tree (node *root) {
    
    if (root -> left != NULL) {
        delete_tree(root -> left);
    }
    if (root -> right != NULL) {
        delete_tree(root -> right);
    }
    
    if (root -> op != '@') {
        cout << "Deleting" << ' ' << root -> op << endl;
    } else {
        cout << "Deleting" << ' ' << root -> val << endl;
    }
    delete root;
    
    
}


int main(int argc, const char * argv[]) {
    
    node *root = new node('+');
    root -> left = new node (5.0);
    root -> right = new node ('-');
    root -> right -> left = new node (15.0);
    node *r1 = root -> right -> right = new node ('*');
    r1 -> left = new node (4.0);
    r1 -> right = new node (5.0);

    
    double v = evaluation(root);
    delete_tree(root);
    cout << v << endl;
    
    return 0;
}