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
#include <map>

using namespace ::std;

vector<vector<int> > g;
vector<bool> used;
vector<int> comp;
map<int, int> m;

int num = 0;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps(int N) {
    for (int i = 0; i < N; ++i) {
        used[i] = false;
    }
    for (int i = 0; i < N; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
        
            /*cout << "Component:";
            for (int j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl;*/
            num++;
        }
}


int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    g.resize(N);
    used.assign(N, false);
    
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        m[v1]++;
        m[v2]++;
        g[v1 - 1].push_back(v2 - 1);
    }
    
    find_comps(N);
    //cout << num << endl;
    
    int f = 1;
    map<int,int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        if ((*it).second % 2) {
            f = 0;
            break;
        }
    }
    
    if (!f || num != 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
        
    return 0;
}