//
//  deikstra_source.cpp
//  sphere
//
//  Created by Максим on 10.05.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <stdio.h>

struct bhnode {
    int priority;
    double value;
};

class priority_queue {
public:
    priority_queue(int MAX) {
        body = new bhnode[maxsize = MAX+1];
        numnodes = 0;
    }
    
    ~priority_queue() {
        delete [] body;
    }
    
    void heapify(int index) {
        for (;;) {
            int left = index + index; int right = left + 1;
            // Кто больше, [index], [left], [right]?
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
    
    void swap(int n1, int n2) {
        bhnode t = body[n1];
        body[n1] = body[n2];
        body[n2] = t;
    }
    
    int insert(bhnode const &node) {
        if (numnodes > maxsize) {
            return -1; // или расширяем.
        }
        body[++numnodes] = node;
        for (int i = numnodes; i > 1 &&
             body[i].priority > body[i/2].priority;
             i /= 2) {
            swap(i, i/2);
        }
        return 0;
    }
    
    bhnode *fetchMin() {
        return numnodes == 0? NULL : body + 1;
    }
    
    int removeMin() {
        if (numnodes == 0) return -1;
        body[0] = body[numnodes--];
        heapify(0);
        return 0;
    }
    
    int increasePriority(int index, int priority) {
        if (body[index].priority >= priority)
            return -1;
        for (body[index].priority = priority;
             index > 1 && body[index].priority > body[index/2].priority;
             index /= 2) {
            swap(index, index/2);
        }
        return index;
    }
    
    void print() {
        printf("max=%d size=%d elems={ ", maxsize, numnodes);
        for (int i = 0; i < numnodes; i++) {
            printf("%d ", body[i].priority);
        }
        printf("}\n");
    }
private:
    bhnode *body;
    int numnodes;
    int maxsize;
};


int main() {
    int arr[] = {8, 4, 9, 1, 5, 7, 14, 23, 32};
    priority_queue q(20);
    for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
        bhnode n;
        n.priority = arr[i];
        q.insert(n);
    }
    q.print();
    for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
        printf("%d ", q.fetchMin()->priority);
        q.removeMin();
    }
}

