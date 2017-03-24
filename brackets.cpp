//
//  sem1.cpp
//  sphere
//
//  Created by Максим on 01.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

//статический массив (фиксированный размер)
//проблемы - нет проверок, ограниченная память
class Stack{
    //const int size; //
    enum{SIZE = 100};
    int body[SIZE];
    int head;
public:
    Stack(){
        head = 0;
    }
    ~Stack(){}
    void push(int val){
        body[head++] = val;
    }
    int pop() {
        return body[--head];
    }
    bool empty(){
        return head == 0;
    }
};

int main(int argc, const char * argv[]) {
    int x, f = 1;
    Stack stack;
    
    while (cin >> x) {
        if (x == 1 || x == 3) {
            stack.push(x);
        } else {
            if (x == 2) {
                if (stack.empty() || stack.pop() == 1) {
                    f = 0;
                }
            } else if (x == 0) {
                if (stack.empty() || stack.pop() == 3) {
                    f = 0;
                }
            }
        }
    }
    
    if (!f || !stack.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}