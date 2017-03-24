//
//  ht6-2.cpp
//  sphere
//
//  Created by Максим on 07.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*У покупателя имеется набор N монет A1 ≤ A2 ≤ ... ≤ AN, каждой монеты ровно по одной штуке.
 Найти наименьшую стоимость предмета, который нельзя купить, используя только эти монеты.*/

using namespace:: std;


int find_min_value(int index,vector<int> &values, vector<int> &coins) {

    if (index < coins.size()) {
        
        int a = coins[index];
        int n = (int)values.size();
        for (int i = 0; i < n; i++) {
            
            values.push_back(values[i] + a);
            //if (values[values.size() - 1] - values[values.size() - 2] > 1) {
           //     return values[values.size() - 2] + 1;
           // }
        }
        if (values[n] - values[n - 1] > 1) {
            return values[n - 1] + 1;
        } else {
            return find_min_value(index + 1, values, coins);
        }
    }
    return values[values.size() - 1] + 1;
}


int main(int argc, const char * argv[]) {
   
    vector<int> values;
    int N;
    cin >> N;
    vector<int> coins(N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
        max += coins[i];
    }
    
    values.push_back(0);
    
    int index = 0;
    int res = find_min_value(index, values, coins);
    
    cout << res << endl;
    
    return 0;
}