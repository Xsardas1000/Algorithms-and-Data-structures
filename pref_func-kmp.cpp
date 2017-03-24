//
//  sem3.cpp
//  sphere
//
//  Created by Максим on 15.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace:: std;


void prefix(string s, vector<int> &pref) {
    pref[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int k = pref[i - 1];
        while (k > 0 && s[k] != s[i]) { //уменьшаем суффикс
            k = pref[k - 1];
        }
        if (s[i] == s[k]) {
            k = k + 1;
        }
        pref[i] = k;
    }
}

int kmp(string s, string t) {
    int index = -1;
    vector<int> pref(s.size());
    prefix(s, pref);
    int k = 0;
    for (int i = 0; i < t.size(); i++) {
        while (k > 0 && s[k] != t[i]) {
            k = pref[k - 1];
        }
        if (s[k] ==  t[i]) {
            k = k + 1;
        }
        if (k == s.size()) {
            index = i - (int)s.size() + 1;
            break;
        }
    }
    return index;
}

int main(int argc, const char * argv[]) {
    
    string t;
    cin >> t;
    
    vector<int> pref(t.length());
    prefix(t, pref);
    
    /*
    for (int i = 0; i < pref.size(); i++) {
        cout << pref[i] << ' ';
    }
    cout << endl;*/
    
    //s - подстрока
    string s;
    cin >> s;
    int index = kmp(s, t);
    if (index) {
        cout << index << endl;
        cout << t.substr(index, s.size()) << endl;
    }
    
    return 0;
}