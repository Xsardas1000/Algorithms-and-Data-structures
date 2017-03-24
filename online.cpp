//
//  starlinux.cpp
//  sphere
//
//  Created by Максим on 03.02.17.
//  Copyright © 2017 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;


class MyClass {
public:
    MyClass() {
        cout << "construct ";
    }
    MyClass (const MyClass  &c) {
        cout << "copy ";
    }
    ~MyClass () {
        cout << "delete ";
    }
    MyClass &operator = (const MyClass &c) {
        cout << "assign ";
        return *this;
    }
};

MyClass buildClass() {
    MyClass c;
    return c;
}

int main(int argc, const char * argv[]) {
    
    MyClass c = buildClass();
    c = buildClass();
    
    return 0;
}
