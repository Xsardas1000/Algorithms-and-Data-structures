//
//  bag.cpp
//  sphere
//
//  Created by Максим on 22.03.16.
//  Copyright © 2016 Максим. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

//приближенное решение задачи о рюкзаке

using namespace:: std;

class Item {
public:
    int weight;
    int price;
    double relev;
    Item(int w, int p) {
        weight = w;
        price = p;
        relev = (double)p / w;
    }
};

vector<Item> bag(int n, vector<Item> items, int W) {
    for (int i = 0; i < n; i++) {
        double max = items[i].relev;
        int index = i;
        for (int j = i + 1; j < n; j++) {
            double cur = items[j].relev;
            if (cur > max) {
                index = j;
                max = cur;
            }
        }
        if (index != i) {
            Item tmp = items[i];
            items[i] = items[index];
            items[index] = tmp;
        }
    }
    int L = W; // оставшийся вес
    vector<Item> true_items;
    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight > L) {
            break;  //вес элемента больше оставшегося в рюкзаке
        }
        true_items.push_back(items[i]);
        L -= items[i].weight;
    }
    return true_items;
}

int main(int argc, const char * argv[]) {
    
    vector<Item> chosen_items, items;
    int n, W;
    cin >> W;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int wi, vi;
        cin >> wi >> vi;
        Item newItem(wi, vi);
        items.push_back(newItem);
    }
    chosen_items = bag(n, items, W);
    
    for (int i = 0; i < chosen_items.size(); i++) {
        cout << chosen_items[i].price << ' ' << endl;
    }
    
    return 0;
}