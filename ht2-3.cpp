//
//  ht2-3.cpp
//  sphere
//
//  Created by Максим on 12.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Даны два упорядоченных по неубыванию массива. Требуется найти количество таких элементов, который имеются в обоих массивах. Например, в массивах (0, 0, 1, 1, 2, 3) и (0, 1, 1, 2) имеются общих четыре элемента - (0, 1, 1, 2).
 Первая строка содержит размеры массивов N1 и N2. В следующих N1 строках содержатся элементы первого массива, в следующих за ними N2 строках - элементы второго массива.
 Программа должна вывести ровно одно число — количество общих элементов. */

using namespace :: std;

int main(int argc, const char * argv[]) {
    
    int n1, n2, num = 0;
    cin >> n1 >> n2;
    vector<int> v1(n1), v2(n2);

    for (int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    
    for (int i = 0; i < n2; i++) {
        cin >> v2[i];
    }
    
    for (int i = 0, k = 0; i < n1; i++) {
        while ((k < v2.size()) && (v2[k] < v1[i])) {
            k++;
        }
        if (k >= v2.size()) {
            break;
        }
        if (v2[k] == v1[i]) {
            num++; k++;
        }
    }
    cout << num << endl;
    
    
    return 0;
}