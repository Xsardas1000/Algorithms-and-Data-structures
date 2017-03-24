//
//  ht5-1.cpp
//  sphere
//
//  Created by Максим on 21.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace:: std;

class Tower {
public:
    string name;
    int x, y, r;
    Tower() {}
};

int main(int argc, const char * argv[]) {
    
    int N, xa, ya;
    cin >> N;
    map<string, int> companies;
    vector<Tower> towers;
    vector<string> names;
    
    for (int i = 0; i < N; i++) {
        string name;
        int x, y, r;
        cin >> name >> x >> y >> r;
        Tower tower;
        tower.name = name; tower.x = x; tower.y = y, tower.r = r;
        towers.push_back(tower);
    }
    cin >> xa >> ya;
    
    
    for (int i = 0; i < N; i++) {
        if ((xa - towers[i].x) * (xa - towers[i].x) + (ya - towers[i].y) * (ya - towers[i].y) <=
            towers[i].r * towers[i].r) {
            companies[towers[i].name]++;
        }
        if (find(names.begin(), names.end(), towers[i].name) == names.end()) {
            names.push_back(towers[i].name);
        }
    }
    
    cout << names.size() << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << companies[names[i]] << endl;
    }

    return 0;
}