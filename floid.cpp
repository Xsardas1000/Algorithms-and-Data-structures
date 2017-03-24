//
//  ht7-2.cpp
//  sphere
//
//  Created by Максим on 18.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Наибольшее расстояние
 Имеется ориентированный взвешенный граф из N вершин, представленный матрицей смежности C[N][N], положительные элементы которой Cij представляют веса связей i-й и j-й вершин.
 Найти наибольшее из кратчайших расстояний между всеми достижимыми парами вершин.
 Гарантируется, что ответ не превышает 109.
 Input format
 N
 C11 C12 ... C1N
 C21 C22 ... C2N
 ...
 CN1 CN2 ... CNN
 Output format
 MaximumShortestPath*/

using namespace ::std;

enum{
    INF = 2000000000
};

void floid(vector<vector<int> > &g, vector<vector<int> > &m, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                for (int k = 0; k < N; ++k) {
                    
                    if (g[i][k] != 0 && g[k][j] != 0) {
                    int s = g[i][k] + g[k][j];
                    if (s < m[i][j] || m[i][j] == 0) m[i][j] = s;
                    }
                    
                    /*if (g[i][k] < INF && g[k][j] < INF && g[i][k] != 0 && g[k][j] != 0){
                        
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }*/
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<vector<int> > g, m;
    g.resize(N, vector<int>(N));
    
    
    //считываем матрицу смежности орграфа
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }
    
    m = g;
    for (int i = 1; i < N; ++i) {
        floid(g, m, N);
        g = m;
    }
    
    int max = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (g[i][j] > max) max = g[i][j];
        }
    }
    cout << max << endl;
    


    
    return 0;
}


