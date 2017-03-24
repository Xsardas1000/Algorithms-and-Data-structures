//
//  dinamic1.cpp
//  sphere
//
//  Created by Максим on 04.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int> > graph;
int N;

/*
int count_paths(int start, int end) {
    if (end == start) {
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (graph[i][end]) {
            sum += count_paths(start, i);
        }
    }
    return sum;
}*/


int count_paths(int start, int end, vector<int> cashe) {
    if (end == start) {
        return cashe[end] = 1;
    }
    if (cashe[end] != 0) {
        return cashe[end];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (graph[i][end]) {
            sum += count_paths(start, i, cashe);
        }
    }
    return cashe[end] = sum;
}



int main(int argc, const char * argv[]) {
    
    cin >> N;
    graph.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    
    int start, end;

    cin >> start;
    cin >> end;
    
    //дополнительный массив чтобы хранить кэш
    vector<int> cashe(N);
    for (int i = 0; i < N; i++) {
        cashe[i] = 0;
    }
    cout << count_paths(start, end, cashe) << endl;;
    
    
    return 0;
}
