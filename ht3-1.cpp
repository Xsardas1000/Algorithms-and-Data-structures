//
//  sort.cpp
//  sphere
//
//  Created by Максим on 29.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

/*Submit a solution for A-Подсчёт частот
 Time limit:	15 s
 Real time limit:	30 s
 Memory limit:	64M
 Подсчёт частот
 На вход подаётся строка, состоящая из букв A-Z. Необходимо вывести все буквы, которые встречаются в строке в порядке убывания частот вместе с частотой. В случае равенства частот первой должна идти буква, которая встречается в алфавите раньше.
 Input format
 Строка из букв A-Z
 Output format
 L1 N1
 L2 N2
 ...
 Lk Nk
 где Li - буква, а Ni — число вхождений буквы в строку*/

using namespace:: std;

enum{
    N = 26 // number of letters
};

class Elem {
public:
    int freq;
    int code;
    Elem(int x) {
        freq = 0;
        code = x;
    }
};


int main(int argc, const char * argv[]) {
    
    char c;
    vector<Elem> codes;
    for (int i = 0; i < N; i++) {
        codes.push_back(Elem(i + 'A'));
    }
    
    
    while((c = getchar())) {
        if (c == '\0' || c == '\n') {
            break;
        }
        codes[c - 'A'].freq++;
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (codes[j].freq < codes[j + 1].freq) {
                swap(codes[j], codes[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!codes[i].freq) break;
        char c = codes[i].code;
        cout << c << ' ' << codes[i].freq << endl;
    }
    
    
    
    return 0;
}