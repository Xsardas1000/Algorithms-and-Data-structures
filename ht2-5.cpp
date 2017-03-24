//
//  ht2-5.cpp
//  sphere
//
//  Created by Максим on 13.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <cmath>

using namespace :: std;

bool is_number(string s){
    if (s[0] == '*' || s[0] == '/' || s[0] == '+' || s[0] == '-') {
        return false;
    } else {
        //cout << s << endl;
        return true;
    }
}

double calc(char op, double a, double b) {
    double res;
    //cout << op << endl;
    switch (op) {
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0) {
                cerr << "Zero division" << endl;
                return 1;
            }
            res = a / b;
            break;
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        default:
            cerr << "Undefined operation" << endl;
            return 1;
            break;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    vector<string> expr;
    string s;
    
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        string buf;
        while (s[i] != ' ' && s[i] != '\0' && s[i] != '\n') {
            buf += s[i++];
        }
        if (buf.size() != 0) {
            expr.push_back(buf);
        }
    }
    
    double res = 0;
    while (expr.size() > 1) {
        for (int i = 0; i < expr.size(); i++) {
            if (!is_number(expr[i]) && is_number(expr[i + 1]) && is_number(expr[i + 2])) {
                
                res = calc(expr[i][0], atof(expr[i + 1].c_str()), atof(expr[i + 2].c_str()));
                expr[i] = to_string(res);

                expr.erase(expr.begin() + i + 1, expr.begin() + i + 3);
                break;
                
            }
            
        }

    }
    
    cout << res << endl;

    
    
    return 0;
}
