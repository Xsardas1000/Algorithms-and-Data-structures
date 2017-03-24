//
//  ht2-2.cpp
//  sphere
//
//  Created by Максим on 12.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Найти количество решений неравенства x2 + y2 < N в неотрицательных числах. Нельзя пользоваться вещественными числами! Типы данных float и double запрещены, как и использование файла math.h.
 1 ≤ N ≤ 1018
 В задаче надо использовать тип данных longlong, который вводится, например, scanf("%lld", &N) и выводится printf("%lld\n", answer);*/

using namespace :: std;

int main(int argc, const char * argv[]) {
    
    long long int N, num = 0;
    scanf("%lld",&N);
    /*
    for (long long int i = 0; i * i < N; ++i) {
        for (long long int j = i + 1; i * i + j * j < N; ++j) {
            num++;
        }
    }
    num *= 2;*/
    
    long long int sq = 0, p = 0;
    while (2 * sq * sq < N) {
        sq++;
    }
    num = sq * sq;
    p = sq;

    while (sq * sq < N) {
        sq++;
    }
    sq--; //корень
    
    long long k = 0;
    for (long long int j = sq; j >= p; j--) {
        for (long long i = k; (i < j) && (i * i + j * j < N); i++) {
            num += 2 * (j - p + 1); k++;
        }
    }
    
    /*
    for (long long int j = p; j * j < N; ++j) {
        for (long long int i = 0; (i < j) && (i * i + j * j < N); ++i) {
            num += 2;
        }
    }*/
    
    printf("%lld\n",num);
    return 0;
}