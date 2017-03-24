//
//  kr4-3.cpp
//  sphere
//
//  Created by Максим on 21.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    
    for (int i = 1; i < g[v].size(); ++i) {
        if ((g[v][i] != 0) && !used[i]) {
            dfs(i);
        }
    }
}

bool check(int N, int M) {
    used.assign(N + 1, false);
    dfs(M);
    bool f = true;
    for(int i = 1; i <= N; i++) {
        if(used[i] == false) {
            f = false;
            break;
        }
    }
    return f;
}


int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    g.resize(N + 1, vector<int>(N + 1));

    while(1) {
        int v1, v2;
        cin >> v1;
        if (v1 == 0) {
            break;
        }
        cin >> v2;
        if(v2 == M) {
            cout << "YES" << endl;
            return 0;
        }
        g[v1][v2] = 1;
    }
    
    if (check(N, M)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
