//
//  wires.cpp
//  sphere
//
//  Created by Максим on 22.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

/*Провода
 На складе есть провода различной целочисленной длины. Их можно разрезать на части. Необходимо получить K кусочков одинаковой целочисленной и как можно большей длины. Найти максимальную длину M.
 Input format
 В первой строке — количество проводов на складе N и необходимое количество кусочков K. В следующих K строках — длины проводов.
 1 ≤ N ≤ 100000
 1 ≤ K ≤ 100000
 Output format
 M — максимальная длина, на которую можно разрезать все провода так, чтобы получилось не менее K кусочков.*/

using namespace:: std;

bool comp (int x, int y) {
    return x >= y;
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    long long int sum = 0;
    
    cin >> N >> K;
    vector<int> wires(N);
    
    for (int i = 0; i < N; i++) {
        cin >> wires[i];
        sum += wires[i];
    }
    
    sort(wires.begin(), wires.end(), comp);
    
    int size = (int)(sum / K);
    
    int num = 0;
    while (num < K) {
        
        num = 0;
        for (int i = 0; i < N && wires[i] >= size; i++) {
            num += wires[i] / size;
        }
        size--;
    }
    cout << size + 1 << endl;;
    
    return 0;
}
