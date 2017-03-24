//
//  universe6.c
//  sphere
//
//  Created by Максим on 12.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>

long long func(long long a, long long n) {
    if (n == 0) {
        return 0;
    }
    if (n & 1) {
        return func(a, n & -2) + a;
    } else {
        long long b = func(a, n >> 1);
        return b + b;
    }
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", func(a, b));
    return 0;
}
