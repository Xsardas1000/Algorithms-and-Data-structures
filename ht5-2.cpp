//
//  ht5-2.cpp
//  sphere
//
//  Created by Максим on 23.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

/*Турнирная таблица индивидуалов
 В индивидуальном первенстве по Дартс, участникам необходимо было набрать максимальное число очков за попытку. Количество попыток не ограничивалось. В протокол комиссии попадало имя участника и результат за проделанную попытку. Итоговым результатом участника считалась лучшая попытка. Если результаты совпадают, первым считается игрок показавший данный результат раньше. Помогите организаторам выстроить участников по убыванию.
 Input format
 Сначало задано число участников M (1 ≤ M ≤ 1000), затем число попыток всех участников N (1 ≤ N ≤ 100000). Далее идёт N строк вида
 Имя очки
 Участник не может набрать больше миллиарда очков за одну попытку.
 Output format
 M строк с именами участников в порядке убывания занятых мест.
 
 Notes
 В случае решения задачи без структур данных, задача оценивается в половину стоимости; в случае использовании одной из двух структур данных: АВЛ-дерево/хэш и куча, задача оценивается стандартно, в случае использовании двух структур данных — куча и либо АВЛ, либо хэш — задача оценивается в удвоенную стоимость.*/

using namespace std;

struct TreeNode {
    int freq;
    int prior;
    string name;
    TreeNode *left, *right;
    TreeNode(int f = 0, TreeNode *l = NULL, TreeNode *r = NULL) : freq(f), left(l), right(r) {};
};

struct binary_heap {
    TreeNode *body;
    int bodysize;
    int numnodes;
    binary_heap(int maxsize);
    ~binary_heap();
    void swap(int a, int b);
    TreeNode extractMin();
    int insert(TreeNode node);
    void heapify(int index);
    int increasePriority(int index, int shot, int score);
};

binary_heap::binary_heap(int maxsize) {
    body = new TreeNode[maxsize + 1];
    bodysize = maxsize;
    numnodes = 0;
}

binary_heap::~binary_heap() {
}

void binary_heap::swap(int a, int b) {
    TreeNode tmp = body[a];
    body[a] = body[b];
    body[b] = tmp;
}

TreeNode binary_heap::extractMin() {
    if (numnodes == 0) return body[0];
    TreeNode p = body[1];
    body[1] = body[numnodes--];
    heapify(1);
    return p;
}

int binary_heap::insert(TreeNode node) {
    if (numnodes > bodysize) {
        return -1;
    }
    body[++numnodes] = node;
    for (int i = numnodes; i > 1 && body[i].freq < body[i/2].freq; i /= 2) {
        swap(i, i/2);
    }
    return numnodes;
}

void binary_heap::heapify(int index) {
    for (;;) {
        int left = index + index; int right = left + 1;
        int largest = index;
        if (left <= numnodes &&
            body[left].freq < body[index].freq)
            largest = left;
        if (right <= numnodes && body[right].freq < body[largest].freq)
            largest = right;
        if (largest == index) break;
        swap(index, largest);
        index = largest;
    }
}



unsigned hash_sedgwick(string s, unsigned HASHSIZE) {
    unsigned h, i, a = 31415, b = 27183;
    for (h = 0, i = 0; i < s.size(); i++, a = a * b % (HASHSIZE - 1)) {
        h = (a * h + b * h) % HASHSIZE;
    }
    return h;
}


int main(int argc, const char * argv[]) {
    int M, N;
    cin >> M >> N;
    
    vector<pair<string, pair<int, int> > > vec(N);
    vector<string> hash_table(M);
    binary_heap heap(N);
    
    //binary_heap creation
    for (int i = 0; i < N; ++i) {
        TreeNode node;
        int score;
        string name;
        
        cin >> name >> score;
        node.freq = score;
        node.name = name;
        node.prior = i;
        heap.insert(node);
    }
    
    //heapsort
    for (int i = 0; i < vec.size(); i++) {
        TreeNode node = heap.extractMin();
        
        vec[vec.size() - 1 - i].second.first = node.freq;
        vec[vec.size() - 1 - i].second.second = node.prior;
        vec[vec.size() - 1 - i].first = node.name;
        heap.heapify(0);
    }
    
    //recovery stability
    bool stable = false;
    while (!stable) {
        stable = true;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i].second.first == vec[i + 1].second.first && vec[i].second.second > vec[i + 1].second.second) {
                swap(vec[i], vec[i + 1]);
                stable = false;
            }
        }
    }
    
    /*
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << " " << vec[i].second << " ";
    }
    cout << endl;
    */
    
    cout << endl;
    
    //hash_calculating
    for (int i = 0; i < vec.size(); i++) {
        string name = vec[i].first;
        int index = hash_sedgwick(name, M);      //M = HASHSIZE
        while (hash_table[index] != name) {
            if (hash_table[index] == "") {
                hash_table[index] = name;
                cout << name << endl;
                break;
            } else {
                index = (index + 1) % M;
            }
        }

    }
    
    
    
    return 0;
}