//
//  kr3-12.cpp
//  sphere
//
//  Created by Максим on 17.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int> > graph;

vector<int> visited;
bool possible = true;

void dfs(long v,int c) { // v - вершина, c-цвет
    
    visited[v] = c; //красим вершину
    
    for(int j = 0; j < graph[v].size();j++) {
        
        if(visited[graph[v][j]] == 0) //если вершина не покрашена
        {
            int new_colour;
            if(c == 1) { //меняем цвет

                new_colour = 2;
            }
            else {
                new_colour = 1;
            }
            dfs(graph[v][j], new_colour); //идем в другую вершину
        }
        if(visited[graph[v][j]]==c) //ребро соединяет вершины одинакового цвета
        {
            possible=false;
        }
    }
}



int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    visited.assign(n, 0);
    graph.resize(n);

    for(int i = 0; i < m; i++) {
        int p,q;
        cin >> p >> q; 
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    for(int i = 0;i < n;i++) {
        if(visited[i] == 0) {   // Если мы еще не посетили вершину
            dfs(i, 1);          // Идем ее красить
        }
    }
    if(!possible) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    
    return 0;
}