//
//  ht1-4.cpp
//  sphere
//
//  Created by Максим on 03.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void find_min_solution(long long int a, long long int b, long long int n);
bool find_any_solution (long long int a, long long int b, long long int n, long long int & x0, long long int & y0, long long int & g);
void test();

long long int gcd (long long int a, long long int b, long long int & x, long long int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long int x1, y1;
    long long int d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (long long int a, long long int b, long long int n, long long int & x0, long long int & y0, long long int & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (n % g != 0)
        return false;
    x0 *= n / g;
    y0 *= n / g;
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    return true;
}

void test() {
    for (long long int a = -100; a < 100; a++) {
        for (long long int b = -100; b < 100; b++) {
            for (long long int n = -100; n < 100; n++) {
                find_min_solution(a, b, n);
            }
        }
    }
}

void find_min_solution(long long int a, long long int b, long long int n) {
    long long int x0, y0, g;
    
    if (a == 0 && b == 0 && n == 0) {      //бесконечно много решений
        x0 = 1;                            //x0-любой,берем минимальный положительный,y0-любой
        cout << x0 << endl;
        return;
    } else if (a == 0 && b != 0 && n == 0) {  //бесконечно много решений
        x0 = 1; y0 = 0;                       //x0 - любой, y0 = 0;
        cout << x0 << " " << y0 << endl;
        return;
    } else if (a != 0 && n == 0) {     //бесконечно много решиний, x0 = 0, y0 = 0 (или y0 - любой)
        cout << "No" << endl;
        return;
    } else if (a == 0 && b == 0 && n != 0) {
        cout << "No" << endl;          //нет решений
        return;
    } else if (n < 0){
        n *= -1; a *= -1; b *= -1;
    }
    
    
    if (find_any_solution(a, b, n, x0, y0, g)) {
        
        if (x0 <= 0 && b / g == 0) {
            cout << "No" << endl;
            return;
        } else if (x0 > 0 && b / g == 0) {
            cout << x0 << " " << y0 << endl;
            return;
        }
        
        if (x0 <= 0 && b / g > 0) {
            while (x0 <= 0) {
                x0 += b / g;
                y0 -= a / g;
            }
        } else if (x0 <= 0 && b / g < 0) {
            while (x0 <= 0) {
                x0 -= b / g;
                y0 += a / g;
            }
        } else if (x0 > 0 && b / g > 0){
            long long int new_x0 = x0, new_y0 = y0;
            while (x0 > 0) {
                new_x0 = x0;
                new_y0 = y0;
                x0 -= b / g;
                y0 += a / g;
            }
            x0 = new_x0;
            y0 = new_y0;
        } else if (x0 > 0 && b / g < 0) {
            long long int new_x0 = x0, new_y0 = y0;
            while (x0 > 0) {
                new_x0 = x0;
                new_y0 = y0;
                x0 += b / g;
                y0 -= a / g;
            }
            x0 = new_x0;
            y0 = new_y0;
        }
        cout << x0 << " " << y0 << endl;
        
        if (x0 * a + y0 * b != n) {
            cout << "error" << endl;
        }
    } else {
        cout << "No" << endl;
    }

}

int main(int argc, const char * argv[]) {
    
    long long int a, b, n;
    cin >> a >> b >> n;
    find_min_solution(a, b, n);
    //test();
    return 0;
}