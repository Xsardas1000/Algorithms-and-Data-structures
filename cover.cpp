//
//  sem2.cpp
//  sphere
//
//  Created by Максим on 05.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace:: std;

struct Tree{
    Tree* c[3];
    bool end;
    Tree(){
        c[0] = c[1] = c[2] = NULL;
        end = false;
    }
    bool insert(Tree *root, string s) {  //корень главного дерева и строку, которую вставляем
        for(auto c:s) {
            if (root->c[c - 'a'] == NULL) {
                root->c[c - 'a'] = new Tree;
                root = root->c[c - 'a'];
                if (root -> end) return false;  //по пути встретили серый узел
            }
        }
        return root -> end = true;
    }
};

bool cover(Tree *root, string s) {
    Tree *r = root;
    for(auto c:s){
        r = r -> c[c - 'a'];
        if (r == NULL) {
            return false;
        }
        if (r -> end) {
            r = root;
        }
    }
    return r == root;
}

int main(int argc, const char * argv[]) {
    
    /*int a1, a2, a3, a4, x, count = 0;
    cin >> a1 >> a2 >> a3 >> a4 >> x;
    
    for (int a1 = 1; a1 <= x / 4; a1++) {
        for (int a2 = a1; a2 <= (x - a1) / 3; a2++) {
                count += (x - a1 - a2) / 2 - a2 + 1;
        }
    }*/
    
    //покрытие строки
    string s, str;
    vector<string> aStr;
    cin >> s;
    while (cin >> str) {
        aStr.push_back(str);
    }

    Tree* root;
    for (int i = 0; i < aStr.size(); i++) {
        root->insert(root,aStr[i]);
    }
    
    
    
    
    return 0;
}