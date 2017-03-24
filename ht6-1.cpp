//
//  zip.cpp
//  sphere
//
//  Created by Максим on 26.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

/*Кузнечик
 Имеется лестница, в которой N ступенек. Кузнечик находится перед лестницей. Он прыгает только вверх и способен прыгнуть вверх не более, чем на M ступенек.
 Определить, сколькими способами кузнечик может допрыгать да самой верхней ступеньки.
 1 ≤ M ≤ N ≤ 30
 Для N = 5 и M = 2 имеется 8 маршрутов: (1,2,3,4,5)
 (1,2,3,5)
 (1,2,4,5)
 (1,3,4,5)
 (1,3,5)
 (2,3,4,5)
 (2,3,5)
 (2,4,5)
 Input format
 N M - количество ступенек в лестнице и наибольший размер прыжка кузнечика.
 Output format
 R - число способов, которыми кузнечик может допрыгать до самой верхней ступеньки.*/

using namespace:: std;

int f(int N, int M, int* cache) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    if (cache[N] >= 0) return cache[N];
    int sum = 0;
    for (int i = 1; i <= M; i++) {
        sum += f(N - i, M, cache);
    }
    return cache[N] = sum;
}

enum {
    K = 1000
};

int main(int argc, const char * argv[]) {
    
    int N, M, cache[K];
    cin >> N >> M;
    
    for (int i = 0; i < K; i++) {
        cache[i] = -1;
    }
    int res = f(N, M, cache);
    
    cout << res << endl;
    
    return 0;
}