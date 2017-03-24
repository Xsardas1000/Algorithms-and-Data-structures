//
//  kr-1.cpp
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
    
    int N, max3 = -1, max5 = -1, max15 = -1, max = -1;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x % 15 == 0) {
            if (x > max15) {
                if (max15 > max5) {
                    if ((max5 > max3) && (max5 % 3 == 0)) {
                        max3 = max5;
                    }
                    max5 = max15;
                } else if (max15 > max3) {
                    if ((max3 > max5) && (max3 % 5 == 0)) {
                        max5 = max3;
                    }
                    max3 = max15;
                }
                max15 = x;
            } else if (x > max5) {
                if ((max5 > max3) && (max5 % 3 == 0)) {
                    max3 = max5;
                }
                max5 = x;
            } else if (x > max3) {
                if ((max3 > max5) && (max3 % 5 == 0)) {
                    max5 = max3;
                }
                max3 = x;
            }
        } else if ((x % 5 == 0) && (x > max5)) {
            if ((max5 > max3) && (max5 % 3 == 0)) {
                max3 = max5;
            }
            max5 = x;
        } else if ((x % 3 == 0) && (x > max3)) {
            if ((max3 > max5) && (max3 % 5 == 0)) {
                max5 = max3;
            }
            max3 = x;
        } else if (x > max) {
            max = x;
        }
    }
    
    vector<long long int> res;
    
    if (max3 > 0 && max5 > 0) {
        res.push_back(max3 * max5);
    }
    if (max3 > 0 && max15 > 0) {
        res.push_back(max3 * max15);
    }
    if (max5 > 0 && max15 > 0) {
        res.push_back(max5 * max15);
    }
    if (max15 > 0 && max > 0) {
        res.push_back(max * max15);
    }
    if (max15 > 0) {
        res.push_back(max15);
    }
    
    if (res.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long int m;
    m = res[0];
    for (int i = 1; i < res.size(); i++) {
        if (res[i] > m) {
            m = res[i];
        }
    }
    
    cout << m << endl;
    
    return 0;
}
