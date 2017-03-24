//
//  kr-2.cpp
//  sphere
//
//  Created by Максим on 22.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace:: std;

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d", &N);
    vector<int> vec1(N), vec2(N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        vec1[i] = x;
    }
    
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        vec2[i] = x;
    }
    
    int i = 0, j = 0;
    int sum = 0;
    int k = 1;
    while (k <= 2 * N) {
        if (i < N && j < N) {
            if (vec1[i] <= vec2[j]) {
                if (k % 2 == 1) {
                    sum += vec1[i];
                    sum = sum % 1000000000;
                }
                i++;
            } else {
                if (k % 2 == 1) {
                    sum += vec2[j];
                    sum = sum % 1000000000;
                }
                j++;
            }
        } else if (i < N) {
            if (k % 2 == 1) {
                sum += vec1[i];
                sum = sum % 1000000000;
                
            }
            i++;
        } else if (j < N) {
            if (k % 2 == 1) {
                sum += vec2[j];
                sum = sum % 1000000000;
            }
            j++;
        }
        k++;
    }
    cout << sum<< endl;
    
    
    return 0;
}

