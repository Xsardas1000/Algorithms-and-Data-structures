//
//  online_test.c
//  sphere
//
//  Created by Максим on 06.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <stdio.h>

const double EPS = 1e-8;

double foo(double L, double R, double (*f)(double)) {
    if (R - L < EPS) {
        return L;
    }
    double m1 = (2*L + R) / 3;
    double m2 = (L + 2*R) / 3;
    if (f(m2) > f(m1)) {
        return foo(m1, R, f);
    } else {
        return foo(L, m2, f);
    }
}

double func(double x) {
    return  -2*x*x*x + 15 * x * x - 36 * x + 5;
}
int main(void) {
    double L, R;
    scanf("%lf%lf", &L, &R);
    printf("%0.3lf\n", foo(L, R, func));
    
    return  0;
}
