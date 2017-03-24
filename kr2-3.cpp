//
//  kr2-3.cpp
//  sphere
//
//  Created by Максим on 12.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


string parse(string input, int& pos) {
    if (input[pos] == '(') {
        string result = "";
        do {
            pos += 1;
            result += parse(input, pos);
        } while (input[pos] == ',');
        pos++;
        if (pos < input.size() && input[pos] == 'R') {
            pos++;
            string reversed;
            for (int i = (int)result.size() - 1; i >= 0; i--)
            reversed.push_back(result[i]);
            return reversed;
        }
        else {
            return result;
        }
    } else {
        int start = pos;
        for (; pos < input.size() && isalpha(input[pos]); pos++) ;
        return input.substr(start, pos - start);
    }
}

int main() {
    string str;
    cin >> str;
    int pos = 0;
    cout << parse(str, pos) << endl;
    return 0;
}