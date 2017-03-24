//
//  universe4.c
//  sphere
//
//  Created by Максим on 12.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_N 15

int main(void) {
    
    int a[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; ++i) {
        memset(a[i], 0, MAX_N * sizeof(a[i][0]));
        a[i][0] = a[i][i] = 1;
    }
    
    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j < i; ++j) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    printf("%d", a[8][5]);
}
