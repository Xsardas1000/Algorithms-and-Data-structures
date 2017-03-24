//
//  ht3-3.cpp
//  sphere
//
//  Created by Максим on 04.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include <string>

/*Ближайшие точки
 На прямой расположено N точек с целочисленными координатами. Требуется найти пару точек, расстояние между которыми минимально.
 Input format
 Первая строка входа содержит количество точек N(2 ≤ N ≤ 106). Вторая строка содержит N различных целых чисел Xi — координаты заданных точек числовой прямой. Числа в строке разделены пробелом. Значения всех координат Xii не превосходят 109 по абсолютной величине.
 Output format
 В первой строке выхода необходимо вывести минимальное расстояние между двумя точками, заданными во входном файле. Во второй строке выходного файла необходимо вывести номера точек, которым соответствует найденное расстояние. Точки нумеруются натуральными числами от 1 до n в том порядке, в котором они заданы во входном файле. Если ответов несколько, выведите тот из них, в котором точки расположены первыми на прямой слева направо. Вывести необходимо номера точек, в порядке входа: первым выводится номер точки, которая встретилась на входе раньше , далее через пробел – номер точки, которая встретилась на входе позже.
 Examples*/

using namespace std;

void ShellsSort(vector<pair<int, int> > &vec, int n) {
    
    for(int k = n / 2; k > 0; k /= 2){
        for(int i = k; i < n; i += 1) {
            pair<int, int> t = vec[i];
            int j;
            for(j = i; j >= k; j -= k) {
                if (t.first < vec[j - k].first) {
                    vec[j] = vec[j - k];
                } else {
                    break;
                }
            }
            vec[j] = t;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    vector<pair<int, int> > vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }
    
    ShellsSort(vec, N);
    
    int min_dist = vec[1].first - vec[0].first;
    int index1 = vec[0].second, index2 = vec[1].second;
    
    for (int i = 1; i < N - 1; i++) {
        int tmp = vec[i + 1].first - vec[i].first;
        if (tmp < min_dist) {
            min_dist = tmp;
            index1 = vec[i].second;
            index2 = vec[i + 1].second;
        }
    }
    
    cout << min_dist << endl;
    
    if (index1 > index2) {
        cout << index2 << ' ' << index1 << endl;;
    } else {
        cout << index1 << ' ' << index2 << endl;
    }
    
    return 0;
}
