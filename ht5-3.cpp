//
//  ht5-3.cpp
//  sphere
//
//  Created by Максим on 23.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

/*Подстроки
 Входной файл состоит из одной строки I, содержащей малые буквы английского алфавита.
 Назовём подстрокой длиной L с началом S множество непрерывно следующих символов строки.
 Например, строка
 
 abcab
 содержит подстроки
 
 длины 1: a, b, c, a, b
 длины 2: ab, bc, ca, ab
 длины 3: abc, bca, cab
 длины 4: abca, bcab
 длины 5: abcab
 
 В строках длины 1 есть два повторяющихся элемента - a и b. Назовём весом подстрок длины L произведение максимального количества повторяющихся подстрок этой длины на длину L.
 В нашем случае вес длины 1 есть 2 (2·1), длины 2 есть 4 (2·2), длины 3 - 3 (1·3), длины 4 - 4 и длины 5 - 5.
 Требуется найти наибольший из всех весов различных длин.*/

using namespace:: std;

int main(int argc, const char * argv[]) {
    
    string s;
    int maxWeight = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        map<string, int> m;
        for (int j = 0; j < s.size() - i; j++) {
            m[s.substr(j, i + 1)] += 1;
        }
        int maxNum = 0;
        for (auto obj: m) {
            if (obj.second > maxNum) {
                maxNum = obj.second;
            }
        }
        int weight = maxNum * (i + 1);
        if (weight > maxWeight) {
            maxWeight = weight;
        }
        
    }
    
    cout << maxWeight << endl;
    return 0;
}