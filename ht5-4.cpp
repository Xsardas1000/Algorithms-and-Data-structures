//
//  ht5-4.cpp
//  sphere
//
//  Created by Максим on 23.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace:: std;

int main(int argc, const char * argv[]) {
    
    string s;
    int maxWeight = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        map<string, int> m;
        for (int j = 0; j < s.size() - i; j++) {
            m[s.substr(j, i + 1)] += 1;
        }
        int maxNum = 0;
        for (auto obj: m) {
            if (obj.second > maxNum) {
                maxNum = obj.second;
            }
        }
        int weight = maxNum * (i + 1);
        if (weight > maxWeight) {
            maxWeight = weight;
        }
        
    }
    
    cout << maxWeight << endl;
    return 0;
}