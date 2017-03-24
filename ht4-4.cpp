//
//  ht4-4.cpp
//  sphere
//
//  Created by Максим on 12.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstring>

/*Обход раскрашенного дерева
 На вход задачи подаётся дерево, каждый узел которого покрашен в белый, чёрный или серый цвет. Необходимо найти сколько вершин на путях от корня к листьям имеют белый цвет, при условии что до попадания в белую вершину путь прошёл через чёрную.
 Input format
 Деревья закодированы скобочными выражениями. После открывающей скобки идёт цвет вершины b, w или g и если у узла есть потомки, то потомки перечислены через запятую. Длина описания дерева не превосходит 10000 символов.
 Output format
 N – число искомых вершин*/

using namespace std;

int main(int argc, const char * argv[]) {
    string str_tree;
    cin >> str_tree;

    int level = 0;
    int res = 0;
    
    for (int i = 0; i < str_tree.size(); ++i) {
        if (level == 0 && str_tree[i] == 'b') {
            level++;
        }
        else if (level > 0) {
            if (str_tree[i] == 'w') ++res;
            if (str_tree[i] == ')') --level;
            if (str_tree[i] == '(') ++level;
        }
    }
    cout << res << endl;
    return 0;
}


