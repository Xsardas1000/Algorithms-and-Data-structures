//
//  universe2.c
//  sphere
//
//  Created by Максим on 12.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>

int find(int a[], int begin, int end, int key) {
    
    
    if (begin == end) {
        return end;
    }
    int middle = (begin + end) / 2;
    if (key < a[middle]) {
        end = middle;
    }
    else {
        begin = middle;
    }
    
    return find(a, begin, end, key);
}

int main(){
    
    int a[] = {2,2,5,6,6,10,13,13};
    
    printf("%d", find(a, 0, 7, 6));
    
    
    return 0;
}
