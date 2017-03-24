//
//  kr4-4.cpp
//  sphere
//
//  Created by Максим on 21.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace ::std;

enum {
    MAX = 10010
};

//подряд идущие 3 цифры образуют трехзначное простое число
bool eq(int t1, int t2, int t3) {

    bool result = false;
    if (t1 == 0) {
        return 0;
    }
    int v = 100 * t1 + 10 * t2 + t3;
    for (int i = 2; i <= floor(0.5 + sqrt(v * 1.0)); i++) {
        if (v % i == 0) {
            return 0;
        }
    }
    result = true;
    return result;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    long long int ans = 0;
    long long int a[MAX][10][10];
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                a[i][j][k] = 0;
            }
        }
    }
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            long long int temp = 0;
            for (int k = 0; k < 10; k++) {
                if (eq(k, i, j)) {
                    temp++;
                }
            }
            a[3][i][j] = a[3][i][j] + temp;
            a[3][i][j] = a[3][i][j] % 1000000009;
        }
    }
    
    for (int t = 4; t <= n; t++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int temp = 0;
                for (int k = 0; k < 10; k++) {
                    if (eq(k, i, j)) {
                        temp += a[t - 1][k][i] % 1000000009;
                    }
                }
                a[t][i][j] = temp;
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ans += a[n][i][j];
            ans = ans % 1000000009;
        }
    }
    cout << ans << endl;
    
    
    return 0;
}