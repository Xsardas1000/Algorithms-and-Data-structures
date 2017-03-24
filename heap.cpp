//
//  heap.cpp
//  sphere
//
//  Created by Максим on 09.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace:: std;

struct bhnode { // Узел
    string data;
    int priority;
};

class priorityQueue {
    bhnode *body;
    int bodysize;
    int numnodes;
public:
    priorityQueue(int max) {
        body = new bhnode[max + 1];
        bodysize = max;
        numnodes = 0;
    }
    ~priorityQueue() {
        delete body;
    }
    
    void swap(int a, int b) {
        bhnode temp = body[a];
        body[a] = body[b];
        body[b] = temp;
    }
    
    int insert(bhnode node);
    bhnode* fetchMin();
    void heapify(int index);

};

bhnode* priorityQueue::fetchMin() {
    return numnodes == 0? 0 : body + 1;
}

int priorityQueue::insert(bhnode node) {
    if (numnodes > bodysize) {
        return -1; // или расширяем.
    }
    body[++numnodes] = node;
    for (int i = numnodes; i > 1 &&
         body[i].priority > body[i/2].priority;
         i /= 2) {
        swap(i, i/2);
    }
    return  0;
}


void priorityQueue::heapify(int index) {
    for (;;) {
        int left = index + index; int right = left + 1;
        int largest = index;
        if (left <= numnodes &&
            body[left].priority > body[index].priority)
        largest = left;
        if (right <= numnodes &&
            body[right].priority > body[largest].priority)
        largest = right;
        if (largest == index) break;
        swap(index, largest);
        index = largest;
    }
}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
