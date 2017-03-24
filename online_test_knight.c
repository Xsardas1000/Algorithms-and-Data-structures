//
//  online_test_knight.c
//  sphere
//
//  Created by Максим on 06.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>

//сколькими способами конь может допрыгать из (x0, y0) в (xend, yend) прыгая 4мя видами
int jump(int curx, int cury, int destx, int desty, int N, int M) {
    
    if (curx == destx && cury == desty) {
        return 1;
    }
    
    if (curx > N - 1 || cury > M - 1 || curx < 0 || cury < 0) {
        return 0;
    }
    
    return jump(curx + 2, cury + 1, destx, desty, N, M) +
    jump(curx + 1, cury + 2, destx, desty, N, M);

}


int main(void) {
    
    int x0, y0;
    x0 = 0; y0 = 0;  //левый верхний - начало коня
    
    int N = 16, M = 16;
    
    int xend = N - 1, yend = M - 1; //правый нижний угол
    
    printf("%d\n", jump(x0, y0, xend, yend, N, M));
    
    
    
    return 0;
}
