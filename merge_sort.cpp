//
//  merge_sort.cpp
//  sphere
//
//  Created by Максим on 07.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;


int* merge(int* arr1, int size1, int* arr2, int size2) {
    
    int i = 0, j = 0, k = 0;
    int *res;
    
    res = new int[size1 + size2];
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            res[k] = arr1[i++];
        } else {
            res[k] = arr2[j++];
        }
        k++;
    }
    
    while (i < size1) {
        res[k++] = arr1[i++];
    }
    while (j < size2) {
        res[k++] = arr2[j++];
    }
    
    cout << "k = " << k << endl;
    return res;
}

void cube(int &x) {
    
}

int main(void) {
    
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int* arr;
    int* arr2;
    
    arr = new int[N];
    arr2 = new int[M];

    for (int i = 0; i < N; i++) {
        //arr[i] = arc4random() % 2 ? (arc4random() % 100) : -(arc4random() % 100);
        //printf("%d ", arr[i]);
        cin >> arr[i];
    }
    
    for (int i = 0; i < M; i++) {
        //arr2[i] = arc4random() % 2 ? (arc4random() % 100) : -(arc4random() % 100);
       // printf("%d ", arr2[i]);
        cin >> arr2[i];
    }
    
    int* res = merge(arr, N, arr2, M);
    
    for (int i = 0; i < N + M; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    return 0;
}
