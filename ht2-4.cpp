//
//  ht2-4.cpp
//  sphere
//
//  Created by Максим on 12.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

/*На вход подаётся N координат точек на плоскости. Необходимо найти такой треугольник максимальной площади, что одна из его сторон лежит на оси OX и при этом треугольник не имеет общих точек с осью OY.
 Входные данные
 В первой строке дано число N ≤ 106. Далее следует N строк с координатами, разделёнными пробелом. Каждая координата имеет не более двух знаков после запятой.
 
 Гарантируется, что существует такой треугольник
 */

using namespace :: std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    float max_pos_x, min_pos_x, max_neg_x, min_neg_x;
    max_pos_x = min_pos_x = -1;
    max_neg_x = min_neg_x = 1;
    
    float max1_x = 0.0f, max1_y = 0.0f, max2_x = 0.0f, max2_y = 0.0f;
    
    for (int i = 0; i < N; ++i) {
        float x, y;
        cin >> x >> y;
        if (y == 0 && x != 0) {
            if (x > 0 && x > max_pos_x) {
                max_pos_x = x;
                if (min_pos_x < 0) {
                    min_pos_x = x;
                }
            } else if (x > 0 && x < min_pos_x) {
                min_pos_x = x;
            } else if (x < 0 && x < min_neg_x) {
                min_neg_x = x;
                if (max_neg_x > 0) {
                    max_neg_x = x;
                }
            } else if (x < 0 && x > max_neg_x) {
                max_neg_x = x;
            }
        } else if (y != 0 && x != 0) {
            if (x > 0) {
                if (abs(y) > max2_y) {
                    max2_y = abs(y);
                    max2_x = x;
                }
            } else {
                if (abs(y) > max1_y) {
                    max1_y = abs(y);
                    max1_x = x;
                }
            }
        }
    }
    
    double s2 = 0, s1 = 0;
    if (max_pos_x != min_pos_x && max2_y != 0) {
    //если есть отрезок на луче (0, inf) и точка, не лежащая на оси OX
        s2 = (max_pos_x - min_pos_x) * max2_y * 0.5;
    }
    
    if (min_neg_x != max_neg_x && max1_y != 0) {
    //если есть отрезок на луче (-inf, 0) и точка, не лежащая на оси OX
        s1 = (max_neg_x - min_neg_x) * max1_y * 0.5;
    }
    
    if (s2 > s1) {
        cout << s2 << endl;
    } else {
        cout << s1 << endl;
    }

    
    
    return 0;
}
