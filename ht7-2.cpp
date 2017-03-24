//
//  ht7-2.cpp
//  sphere
//
//  Created by Максим on 20.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

/*Имеются N городов. Каждые два города соединены не более, чем одной двунаправленной дорогой, всего дорог M. Имеется C компаний, пронумерованных от 1 до C. Каждая из дорог либо принадлежит одной из компаний, либо принадлежит государству, тогда владелец равен нулю.
 Два города являются столицами — северной CN и южной CS. По законам страны на ЛЮБОМ из возможных путей между столицами должна иметься дорога, принадлежащая КАЖДОЙ из компаний.
 Нужно вывести список всех компаний, для которых между столицами существует путь, на котором у этой компании нет ни одной дороги.
 Input format
 N M C
 a1 b1 c1
 a2 b2 c2
 ...
 aN bN cN
 CN CS
 Output format
 K
 c1 c2 ... cK*/

using namespace ::std;

vector<vector<int> > g,m;
vector<int> path;
map<pair<int, int>, int> edges;
vector<bool> used;

int l = 0;

int roads(int start, int finish, int CN) {
    l++;
    //used[start] = true;

    path.push_back(start);
    
    if (start == finish) {
        //путь найден, печатаем path и возвращаемся.
        /*cout<< "PATH " << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;*/
        m.push_back(path);
        //path.clear();

        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < g[start].size(); i++) {
        if (g[start][i] != 0 && edges[make_pair(start, i)] == 0 && i != CN) {
            edges[make_pair(start, i)]++;
            edges[make_pair(i, start)]++;
            //cout << start << " " << i << endl;

            sum += roads(i, finish, CN);
            edges[make_pair(start, i)] = 0;
            edges[make_pair(i, start)] = 0;
            path.pop_back();
        }

        //path.pop_back();
    }

    
    return sum;
}


int main(int argc, const char * argv[]) {
    
    int N, M, C, CN, CS;
    cin >> N >> M >> C;
    
    g.resize(N, vector<int>(N));
    used.assign(N, false);
    
    for (int i = 0; i < N; i++) {
        g[i].assign(N, 0);
    }
    
    

    for (int i = 0; i < M; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        g[v1 - 1][v2 - 1] = c + 1;
        g[v2 - 1][v1 - 1] = c + 1;
    }
    
    /*cout<< endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << g[i][j] <<  " ";
        }
        cout << endl;
    }*/

    
    cin >> CN >> CS;
    
    int res = roads(CN - 1, CS - 1, CN - 1);
    //cout << res << endl;
    
    //cout << m.size() << endl;
    
    int num = 0;
    vector<int> ans;
    vector<int> comp(C + 1);
    
    for (int i = 0; i < m.size(); i++) {
        comp.assign(C + 1, 0);

        for (int j = 0; j < m[i].size() - 1; j++) {
            //cout << g[m[i][j]][m[i][j + 1]] - 1 << " ";
            comp[g[m[i][j]][m[i][j + 1]] - 1]++;
        }
        for (int k = 1; k < comp.size(); k++) {
            if (comp[k] == 0) {
                num++;
                ans.push_back(k);
            }
        }
        
        //cout << endl;
    }
    
    cout << num << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    cout << " count " << l<< endl;
    
    return 0;
}

