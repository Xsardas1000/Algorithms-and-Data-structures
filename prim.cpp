//
//  prim.cpp
//  sphere
//
//  Created by Максим on 14.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace ::std;

vector<vector<int> > g, smt;
vector<bool> used;
vector<int> min_e, sel_e;

enum{
    MAX = 2000000000
};

void prim(int N) {
    //Алгоритм делает n шагов, на каждом из которых выбирает вершину v с наименьшей меткой min_e,
    //помечает её used, и затем просматривает все рёбра из этой вершины, пересчитывая их метки.
    for (int i = 0; i < N; ++i) {
        int v = -1;
        for (int j = 0; j < N; ++j) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        if (min_e[v] == MAX) {
            cout << "No MST!";
        }
        
        used[v] = true;
        
        
        for (int to = 0; to < N; ++to) {
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
        }
        
        /*if (sel_e[v] != -1) {
         cout << v << " " << sel_e[v] << endl;
         }*/
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    

    g.resize(N, vector<int>(N));
    smt.resize(N, vector<int>(N));
    used.assign(N, false);
    
    //флаг used[i] = true означает, что вершина i включена в остов MST
    
    
    
    min_e.assign(N, MAX);
    sel_e.assign(N, -1);
    
    //величина min_e[i] хранит вес наименьшего допустимого ребра из вершины i, f элемент sel_e[i] содержит
    //конец этого наименьшего ребра (это нужно для вывода рёбер)
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            smt[i][j] = 0;
            if (g[i][j] == 0) {
                g[i][j] = MAX;
            }
        }
    }
    
    min_e[0] = 0;
    
    prim(N);
    
    //в smt находится матрица смежности, соответствующая минимальному остовному дереву
    for (int i = 0; i < N; i++) {
        smt[i][sel_e[i]] = min_e[i];
    }
               
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << smt[j][i] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
