//
//  ppp.cpp
//  sphere
//
//  Created by Максим on 10.09.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void func(int &x) {
    x = 10;
}
int main(void) {
    int p;
    func(p);
    cout << p;
}
