//
//  ht7-4.cpp
//  sphere
//
//  Created by Максим on 21.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <algorithm>

/*Два игрока играют в следующую игру. На поле из N + 1 × N + 1 клетки (нумерация клеток от 0 до N) в клетке (0, 0) стоит фишка. Её разрешено разрешено двигать из клетки (x, y) в клетку с координатами (x + ai, y + bi), где пары (ai, bi) обговорены перед началом игры. Выигрывает тот игрок, который вывел фишку первым в клетку, которая находится на расстоянии не менее чем R от (0, 0). Необходимо определить кто из игроков выигрывает, при безошибочных действиях соперника. Игроки ходят по очереди, пропускать ход нельзя.
 Input format
 N ≤ 300 – граница поля
 R ≤ 300 – минимальное расстояние на которое нужно вывести фишку
 M ≤ 30 – число допустимых ходов
 a1 b1
 a2 b2
 ...
 aM bM
 0 ≤ ai, bi ≤ 1000
 Output format
 1 или 2*/

using namespace std;

vector<vector <char> > field;
vector<pair<int, int> > moves;

void f(int r, int m, int n){
    bool flag = true, check;
    
    while(field[0][0] != 'x' && field[0][0] != 'o') {
        if(flag) {
            for(int x = 0; x <= r; x++)
                for(int y = 0; y <= r; y++)
                    for(int k = 0; k < m; k++)
                        if(x + moves[k].first <= n && y + moves[k].second <= n) {
                            if(field[x + moves[k].first][y + moves[k].second] == 'o' && field[x][y] != 'o')
                                field[x][y] = 'x';
                        }
                        else {
                            field[x][y] = 'x';
                        }
        }
        else {
            for(int x = 0; x <= r; x++)
                for(int y = 0; y <= r; y++) {
                    check = true;
                    for(int k = 0; check && k < m; k++)
                        if(x + moves[k].first <= n && y + moves[k].second <= n) {
                            if(field[x + moves[k].first][y + moves[k].second] != 'x' || field[x][y] == 'x')
                                check = false;
                        }
                    if(check) {
                        field[x][y] = 'o';
                    }
                }
        }
        
        flag = !flag;
    }

}

int main(int argc, const char * argv[]) {
    
    int n, r, m;
    cin >> n >> r >> m;
    moves.resize(m);

    if (r == 0) {
        cout << 1;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    
    field.resize(n + 1, vector<char>(n + 1));
    for(int x = 0; x < n; x++) {
        for(int y = n; x * x + y * y >= r * r && y >= 0; y--) {
            field[x][y] = 'o';
        }
    }
    
    f(r, m, n);
    
    if(field[0][0] == 'x')
        cout << 1 << endl;
    else
        cout << 2 << endl;
    
    return 0;
}