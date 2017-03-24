//
//  kr4-2.cpp
//  sphere
//
//  Created by Максим on 21.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {

    string s;
    cin >> s;
    vector<char> w(s.length());
    
    for(int i = 0; i < s.length(); i++) {
        w[i] = s[i];
    }

    int k;
    vector<char>::iterator t = w.end();
    
    for(k = (int)w.size() - 1; k >= 0; k--) {
        if (w[k] > w[k - 1]) {
            break;
        }
        t--;
    }
    
    char c = 'z';
    int m = 0;
    t--;
    for(int i = k; i < w.size(); i++) {
        if(w[i] > w[k - 1] && w[i] < c) {
            c = w[i];
            m = i;
        }
    }
    swap(w[m], w[k - 1]);
    
    sort(t, w.end());
    for(int i = 0; i < w.size(); i++) {
        cout << w[i];

    }
    cout << endl;
    
    
}