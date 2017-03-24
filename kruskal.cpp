//
//  ht7-3.cpp
//  sphere
//
//  Created by Максим on 20.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

/*
 Сеть городов
 В некой стране имеется N городов, соединённых между собой дорогами, причём каждый город соединён с каждым дорогой с движением в обе стороны, которая не проходит через другие города. Дорога из города i в город j имеет стоимость Aij.
 Требуется оставить только те дороги, которые
 а) связывают все города, то есть, можно будет проехать из любого города в любой другой (разумеется, проезжая через другие города); б) имеют наименьшую суммарную стоимость из всех возможных вариантов.
 Input format
 N
 A11 A12 ... A1N
 A21 A22 ... A2N
 ...
 AN1 AN2 ... ANN
 Output format
 TotalCost*/

using namespace ::std;

bool comp(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b) {
    return (a.first <= b.first);
}


int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<pair<int, pair<int,int> > > g; // вес - вершина 1 - вершина 2
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int weight;
            cin >> weight;
            if (i < j) {
                g.push_back(make_pair(weight, make_pair(i, j)));
            }
        }
    }
    
    int cost = 0;
    vector<pair<int,int> > res;
    //все рёбра сортируются по весу (в порядке неубывания)
    
    sort(g.begin(), g.end());
    /*for (int i = 0; i < g.size(); i++) {
        cout << g[i].first << " " << g[i].second.first << " " << g[i].second.second << endl;
    }
    cout << endl;*/
    
    vector<int> tree_id(N); //в нём для каждой вершины хранится номер дерева, которому она принадлежит
    
    //Алгоритм Крускала изначально помещает каждую вершину в своё дерево, а затем постепенно объединяет эти деревья,
    //объединяя на каждой итерации два некоторых дерева некоторым ребром.
    for (int i = 0; i < N; ++i){
         tree_id[i] = i;
    }
    
    int m = (int)g.size(); //кол-во ребер
    
    for (int i = 0; i < m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (tree_id[a] != tree_id[b]) {
            
            cost += l;
            res.push_back(make_pair(a, b));
            int old_id = tree_id[b],  new_id = tree_id[a];
            
            for(int j = 0; j < N; ++j) {
                if (tree_id[j] == old_id) {
                    tree_id[j] = new_id;
                }
            }
        }
    }
    
    /*for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    cout << endl;*/
    
    cout << cost << endl;
    
    return 0;
}