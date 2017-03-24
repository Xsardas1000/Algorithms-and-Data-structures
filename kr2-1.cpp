//
//  kr2-1.cpp
//  sphere
//
//  Created by Максим on 12.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int a[N][N];
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    int x;
    cin >> x;
    
    for (int i = 0; i < N; i++) {
        int l = 0, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[i][mid] > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (a[i][l] == x) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}