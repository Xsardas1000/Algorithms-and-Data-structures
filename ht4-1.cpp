//
//  ht4-1-binsearch.cpp
//  sphere
//
//  Created by Максим on 09.04.16.
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

void fast_sort(vector<int> &vec) {
    if (vec.size() == 0) {
        return;
    }
    int max_elem = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max_elem) {
            max_elem = vec[i];
        }
    }
    vector<int> tmp(max_elem + 1);
    for (int i = 0; i < vec.size(); i++) {
        tmp[vec[i]]++;
    }
    
    int k = 0;
    for (int i = (int)tmp.size() - 1; i >= 0; i--) {
        for (int j = 0; j < tmp[i]; j++) {
            vec[k++] = i;
        }
    }
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
    
    fast_sort(wires);
    
    if (K <= N) {
        wires.erase(wires.begin()+ K, wires.end());
    } else {
        while (K != N) {
            wires.push_back(wires[0] / 2);
            wires[0] = wires[0] / 2;
            fast_sort(wires);
            N++;
        }
    }
    
    int left = 0, right = (int)wires.size() - 1;
    
    while (wires[left] / 2 > wires[right]) {
        wires[left] = wires[left] / 2;
        wires[right] = wires[left];
        fast_sort(wires);
    }
    
    int max_size = wires[right];
    
    cout << max_size << endl;

    /*
    for (int i = 0; i < N; i++) {
        cout << wires[i] << ' ';
    }
    cout << endl;*/
    
    return 0;
}
