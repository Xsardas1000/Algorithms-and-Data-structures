//
//  universe3.c
//  sphere
//
//  Created by Максим on 12.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>

#define MAX_N 10
char sequence[MAX_N];
void print(int n) {
    
    for (int i = 0; i < n; ++i) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

void gen(int i, int n, int k) {
    if (i == n) {
        print(n);
        return;
    }
    sequence[i] = '(';
    if (n - i >= k + 1) {
        gen(i + 1, n, k + 1);
    }
    
    sequence[i] = ')';
    if (k > 0) {
        gen(i + 1, n, k - 1);
    }
}

int main (void) {
    gen(0, 8, 0);
    return 0;
}
