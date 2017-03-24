//
//  ht2-1.cpp
//  sphere
//
//  Created by Максим on 11.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Имеется последовательность натуральных чисел, длина которой больше 8. Признаком конца последовательности является отрицательное число, не входящее в последовательность. Найти максимальное произведение двух элементов последовательности, отстоящих друг от друга не менее, чем на 8. Гарантируется, что ответ меньше 2000000000.*/

using namespace :: std;

int main(int argc, const char * argv[]) {
    
    int x, k = 9, m = 0, maxProd, max;
    vector<int> numbers;
    
    for (int i = 0; i < k; i++) {
        cin >> x;
        numbers.push_back(x);
    }
    
    maxProd = numbers[k - 1] * numbers[m];
    max = numbers[m];
    m++;
    
    cin >> x;
    numbers.push_back(x);
    k++;
    
    while (x >= 0) {
        if (numbers[m] > max) {
            max = numbers[m];
        }
        //можно исп-ть фиксированный размер вектора (вместо первых двух оставлять max(a1, a2))
        if (max * numbers[k - 1] > maxProd) {
            maxProd = max * numbers[k - 1];
        }
    
        cin >> x;
        numbers.push_back(x);
        k++; m++;
    }
    
    
    cout << maxProd << endl;
    
    
    return 0;
}