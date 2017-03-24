//
//  kr2-2.cpp
//  sphere
//
//  Created by Максим on 12.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Elem {
public:
    string name;
    vector<int> values;
};
void swap_struct(Elem &elem1, Elem &elem2);

void sort_struct(vector<Elem> &structures, int index) {
    
    for (int i = 0; i < structures.size() - 1; i++) {
        for (int j = 0; j < structures.size() - i - 1; j++) {
            if (structures[j].values[index] < structures[j + 1].values[index]) {
                swap_struct(structures[j], structures[j + 1]);
            }
        }
    }
}

void swap_struct(Elem &elem1, Elem &elem2) {
    Elem tmp;
    tmp.name = elem1.name;
    tmp.values.resize(elem1.values.size());
    for (int i = 0; i < elem1.values.size(); i++) {
        tmp.values[i] = elem1.values[i];
    }
    
    elem1.name = elem2.name;
    for (int i = 0; i < elem1.values.size(); i++) {
        elem1.values[i] = elem2.values[i];
    }
    
    elem2.name = tmp.name;
    for (int i = 0; i < elem1.values.size(); i++) {
        elem2.values[i] = tmp.values[i];
    }
}

int main(int argc, const char * argv[]) {
    
    int N, K;
    cin >> N;
    cin >> K;
    
    vector<int> prior(K);
    vector<Elem> structures(N);
    
    for (int i = 0; i < K; i++) {
        cin >> prior[i];
    }
    
    for (int i = 0; i < N; i++) {
        Elem elem;
        cin >> elem.name;
        elem.values.resize(K);

        for (int j = 0; j < K; j++) {
            cin >> elem.values[j];
        }
        structures[i] = elem;
    }
    
    cout << structures.size() << endl;
    
    /*for (int i= 0; i < N; i++) {
        cout << structures[i].name;
        for (int j = 0; j < K; j++) {
           cout <<  structures[i].values[j] << " ";
        }
        cout << endl;
    }*/
    
    for (int i = 0; i < K; i++) {
        sort_struct(structures, prior[i]);
    }
    
    for (int i = 0; i < structures.size(); i++) {
        cout << structures[i].name << endl;
    }

    
    
    
    
    return 0;
}