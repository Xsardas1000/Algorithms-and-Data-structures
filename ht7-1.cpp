//
//  ht7-1.cpp
//  sphere
//
//  Created by Максим on 13.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Компоненты сильной связности
 На вход подаётся описание ориентированного графа — необходимо найти число его компонент сильной связности. Компонентой сильной связности называется максимальное по включению множество вершин, каждые две вершины которого достижимы друг из друга.
 Input format
 N ≤ 1000 – число вершин
 N строк вида
 ai, 1 ai, 2 ... ai, N, где ai, j = 1, если в графе есть ребро из вершины i в вершину j.
 Output format
 M – число компонент сильной связности*/

using namespace ::std;

vector<vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    //cout << "V: " << v << endl;

    for (int i = 0; i < g[v].size(); ++i) {  //запускаем для непосещённых соседей вершины v поиск в глубину
        if ((g[v][i] > 0) && !used[i]){
            dfs1(i);
        }
    }
    //cout << "V: " << v << endl;
    order.push_back(v);  //добавляем время выхода из вершины v в массив
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < gr[v].size(); ++i) {
        if ((gr[v][i] > 0) && !used[i]) {
            dfs2(i);
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    g.resize(N, vector<int>(N));
    gr.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            gr[j][i] = g[i][j];
        }
    }
    
    //Запустить серию обходов в глубину графа G, которая возвращает вершины в порядке увеличения времени выхода tout,
    //т.е. некоторый список order.
    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    
    int count = 0;
    
    /*cout << "Order: ";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    cout << endl;*/
    
    //Построить транспонированный граф G^T. Запустить серию обходов в глубину этого графа в порядке, определяемом списком
    //order (а именно, в обратном порядке, т.е. в порядке уменьшения времени выхода).
    //Каждое множество вершин, достигнутое в результате очередного запуска обхода, и будет очередной компонентой сильной связности.
    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        int v = order[N - 1 - i];
        if (!used[v]) {
            dfs2(v);
            /*cout << endl;
            for (int i = 0; i < component.size(); i++) {
                cout << component[i] << " ";
            }*/
            count++;
            component.clear();
        }
    }

    //cout << endl;
    cout << count << endl;
    
    return 0;
}
