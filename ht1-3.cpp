//
//  ht-2.cpp
//  sphere
//
//  Created by Максим on 03.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector<string> grey_code(int n) {
    vector<string> code(pow(2, n));
    if (n == 1) {
        code[0] = "0"; code[1] = "1";    //push_back() не работало
        return code;
    }
    vector<string> tmp = grey_code(n - 1);
    int k = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        code[k++] = "0" + tmp[i];
    }
    for (int i = (int)tmp.size() - 1; i >= 0; --i) {
        code[k++] = "1" + tmp[i];
    }
    return code;
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    if (!n) {
        return 0;
    }

    vector<string> result = grey_code(n);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    
    return 0;
}