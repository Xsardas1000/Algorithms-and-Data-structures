//
//  kr3-2.cpp
//  sphere
//
//  Created by Максим on 17.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, k;
    cin >> n >> k;
    
    vector<long long int> d(n + 1), d0(n + 1);
    
    d[1] = k-1;
    d0[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        d[i] = (d[i-1] + d0[i-1]) * (k - 1);
        d0[i] = d[i-1];
    }

    cout << d[n]+d0[n] << endl;
    
    return 0;
}