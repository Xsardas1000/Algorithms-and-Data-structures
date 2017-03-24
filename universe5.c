//
//  universe5.c
//  sphere
//
//  Created by Максим on 12.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 8
int permutation[MAX_N];
int cnt = 0;
void print(int n) {
    
    cnt++;
}

int check(int p, int n) {
    for (int i = 0; i < p; i++) {
        if (permutation[i] == permutation[p]) {
            return 0;
        }
        if (abs(i - p) == abs(permutation[i] - permutation[p])) {
            return 0;
        }
    }
    return 1;
}

void gen(int i, int n) {
    if (i == n) {
        print(n);
    }
    for (int j = 0; j < n; j++) {
        permutation[i] = j;
        if (check(i, n)) {
            gen(i + 1, n);
        }
        
    }
}

int main(void) {
    for (int i = 1; i <= 6; i++) {
        gen(0, i);
    }
    printf("%d\n", cnt);
}
