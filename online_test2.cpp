//
//  online_test2.cpp
//  sphere
//
//  Created by Максим on 09.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct pool_t {
    int *data;
    int size;
    int tail;
};

void push(pool_t &pool, int value) {
    pool.tail = (pool.tail + 1) % pool.size;
    pool.data[pool.tail] = value;
    
}

int main() {
    pool_t pool = {new int[6], 6, 0};
    for (int i = 0; i < 10; ++i) {
        push(pool, i);
    }
    
    for (int i = 0; i < pool.size; ++i) {
        printf("%d ", pool.data[i]);
    }

    return 0;
}
