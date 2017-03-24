//
//  sem1.cpp
//  sphere
//
//  Created by Максим on 01.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

/*На вход подаётся число N ≤ 1000000, далее следует N строк, в каждой из которых записано число от 0 до 10000000. Необходимо найти второй максимум среди этих чисел. Т.е. число, которое стоит вторым в отсортированной последовательности – если максимум встречается дважды, то второй максимум оказывается равным первому.*/

#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, max1, max2;
    
    cin >> n;
    //если есть хотя бы 2 эл-та
    if (n > 1) {
        cin >> max1;
        cin >> max2;
        if (max2 > max1) {
            int tmp = max1;
            max1 = max2;
            max2 = tmp;
        }
        n -= 2;
    } else {
        cerr << "There is less than 2 elements" << endl;
        return 1;
    }
    
    while (n--) {
        int x;
        cin >> x;
        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }
    }
    cout << max2 << endl;
    
    return 0;
}