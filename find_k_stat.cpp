//
//  find_k_stat.cpp
//  sphere
//
//  Created by Максим on 11.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace:: std;


int partition(vector<int> &mas, int l, int r) {
    if (l!=r)
    swap(mas[l + rand() % (r - l)], mas[r]);
    int x = mas[r];
    int i = l - 1;
    for (int j = l; j <= r; j++) {
        if (mas[j] <= x) swap(mas[++i], mas[j]);
    }
    return i;
}

int nth(vector<int> mas, int k) {
    int l = 0, r = (int)mas.size() - 1;
    for(;;) {
        int pos = partition(mas,l,r);
        
        if (pos < k) {
            l = pos + 1;
        } else if (pos > k) {
            r = pos - 1;
        } else {
            return mas[k];
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    
    for (int i = 0; i < N; i++) {
        vec[i] = arc4random() % 10;
        cout << vec[i] << ' ';
    }
    cout << endl;
    
    int k_stat = nth(vec, K - 1); //1 - 1st k-stat, 10 - 10th k-stat
    cout << k_stat << endl;
    
    
    
    return 0;
}