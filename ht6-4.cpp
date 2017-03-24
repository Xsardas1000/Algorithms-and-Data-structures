//
//  ht6-4.cpp
//  sphere
//
//  Created by Максим on 13.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Счастливые билеты
 Билет состоит из чётного числа N цифр в M-ричной системе счисления. Счастливым билетом называется билет, сумма первой половины цифр которого равна сумме второй половины цифр.
 Найти количество счастливых билетов. Так как их число может быть велико, вывести остаток от деления результата на MOD.
 Input format
 N M MOD
 2 ≤ N ≤ 150
 N mod 2 = 0
 2 ≤ M ≤ 30
 2 ≤ MOD ≤ 1000000000
 Output format
 Result%MOD */

using namespace:: std;


long long int tickets(int n, int m, int left, int MOD, vector<vector<long long int> > &tab) {
    if (left < 0) return 0;
    if (n == 1) {
        return left <= (m - 1);
    }
    long long int sum = tab[n][left];
    if (sum < 0) {
        sum = 0;
        for (int i = 0; i <= (m - 1); i++) {
            sum += tickets(n - 1, m, left - i, MOD, tab);
            sum %= MOD;
        }
        tab[n][left] = sum;
    }
    return sum;
}




int main(int argc, const char * argv[]) {
    
    int N, M, MOD;
    cin >> N >> M >> MOD;
    int left = (M - 1) * N / 2;
    vector<vector<long long int> > tab(N + 2, vector<long long int>(left + 2));

    
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < left + 2; j++) {
            tab[i][j] = -1;
        }
    }
    
    long long int res = tickets(N, M, left, MOD, tab);
    
    cout << res << endl;
    
    return 0;
}