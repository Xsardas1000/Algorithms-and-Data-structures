//
//  ht4-5.cpp
//  sphere
//
//  Created by Максим on 18.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

/*Сотовая связь
 В городе имеется несколько операторов мобильной связи, каждый из которых располагает несколькими вышками. У каждой вышки свои координаты и своя зона уверенного приёма. Абонент находится в точке с заданными координатами. Требуется определить количество операторов мобильной связи в городе и определить, для скольких вышек у абонента, находящегося в данной точке, имеется устойчивая связь.
 В первой строке входного файла содержится целое число N(1 ≤ N ≤ 10000 — количество базовых станций.
 Далее следует N пар строк, в первой строке содержится имя оператора, во второй — два целых числа с координатами станции Xi и Yi ( - 10000 ≤ Xi, YI ≤ 10000), за которыми следует целочисленный радиус уверенного приёма Ri(1 ≤ Ri ≤ 10000).
 В последней строке — координаты абонента Xa и Ya.
 Названия операторов — строки, не содержащие пробелов и состоящие из букв латинского алфавита и цифр.
 В первой строке выходного файла нужно вывести количество операторов K, K ≤ 1000.
 В следующих K строках требуется вывести название оператора ( в порядке их появления во входном файле) и через пробел количество базовых станций, доступных для абонента.
 Input format
 N
 name1
 X1 Y1 R1
 ...
 namen
 Xn Yn Zn
 Xa Ya
 Output format
 K
 name1 c1
 name2 c2
 ...
 nameK cK
 Examples*/

using namespace:: std;

class Tower {
public:
    string name;
    int x, y, r;
    Tower() {}
};

int main(int argc, const char * argv[]) {
    
    int N, xa, ya;
    cin >> N;
    map<string, int> companies;
    vector<Tower> towers;
    vector<string> names;
    
    for (int i = 0; i < N; i++) {
        string name;
        int x, y, r;
        cin >> name >> x >> y >> r;
        Tower tower;
        tower.name = name; tower.x = x; tower.y = y, tower.r = r;
        towers.push_back(tower);
    }
    cin >> xa >> ya;
    
    
    for (int i = 0; i < N; i++) {
        if ((xa - towers[i].x) * (xa - towers[i].x) + (ya - towers[i].y) * (ya - towers[i].y) <=
            towers[i].r * towers[i].r) {
            companies[towers[i].name]++;
        }
        if (find(names.begin(), names.end(), towers[i].name) == names.end()) {
            names.push_back(towers[i].name);
        }
    }
    
    cout << names.size() << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << companies[names[i]] << endl;
    }
    
    /*
    for (auto obj :companies) {
        cout << obj.first << " " << obj.second << endl;
    }*/
    
    return 0;
}