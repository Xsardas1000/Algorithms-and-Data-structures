//
//  ht4-2.cpp
//  sphere
//
//  Created by Максим on 09.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

/*Унимодальный массив
 На вход подаётся число N ≤ 1000 и унимодальный массив a размера N: элементы a расположены таким образом, что
 a[1] < a[2]
 a[2] < a[3]
 ...
 a[k - 1] <  a[k]  > a[k + 1]
 a[k + 1] > a[k + 2]
 a[k + 2] > a[k + 3]
 ...
 a[N - 1] > a[N].
 Требуется найти a[k]
 Input format
 N
 a[1] a[2] ... a[N]
 Output format
 a[k]*/

using namespace:: std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    vector<int> a(N);
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int left = 0, right = N - 1, res;
    while (left <= right) {
        if (left == right) {
            res = a[left];
            break;
        }
        int mid = (left + right) / 2;
        if ((mid == 0 && a[mid] > a[mid + 1]) || (mid == N - 1 && a[mid] > a[mid - 1])) {
            res = a[mid];
            break;
        }
        if (a[mid] < a[mid + 1] && a[mid - 1] < a[mid]) {
            left = mid + 1;
        } else if (a[mid] > a[mid + 1] && a[mid] < a[mid - 1]) {
            right = mid - 1;
        } else if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]){
            res = a[mid];
            break;
        }
    }
    
    cout << res << endl;
    
    return 0;
}