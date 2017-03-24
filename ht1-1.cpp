//
//  main.cpp
//  sphere
//
//  Created by Максим on 25.02.16.
//  Copyright © 2016 Максим. All rights reserved.
//

/*На вход подаётся строка состоящая из букв a и b. Необходимо проверить одинаковое ли количество букв a и b в этой строке. Задачу необходимо решить, используя только стек и булевы переменные. Счётчики можно использовать только при чтении строки. Можете использовать как стек, написанный самостоятельно, так и стек из стандартной библиотеки.*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

//char-stack
class Stack {
    int size;
    char* top;
    char* s;
public:
    Stack(int sz) {
        top = s = new char[size = sz];
    }
    ~Stack() { delete[] s; }
    bool push(char c) {
        if (c != 'a' && c != 'b') {
            return false;
        }
        *top++ = c;
        return true;
    }
    char pop() {
        return *--top;
    }
    bool empty(){
        return s == top;
    }
};

int main(int argc, const char * argv[]) {
    
    Stack stack(PATH_MAX);
    while (stack.push(getchar())) {
        if (stack.pop() == 'a') {
            if (!stack.empty()) {
                if (stack.pop() == 'a') {
                    stack.push('a');
                    stack.push('a');
                }
            } else {
                stack.push('a');
            }
        } else {
            if (!stack.empty()) {
                if (stack.pop() == 'b') {
                    stack.push('b');
                    stack.push('b');
                }
            } else {
                stack.push('b');
            }
        }
    }
    if (stack.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
