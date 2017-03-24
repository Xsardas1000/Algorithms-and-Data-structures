//
//  ht4-3-stl.cpp
//  sphere
//
//  Created by Максим on 15.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <map>
#include <vector>

/*Телефонная книга
 Необходимо разработать программу, которая является промежуточным звеном в реализации телефонной книги. На вход подаётся N ≤ 1000 команд вида
 ADD User Number
 DELETE User
 EDITPHONE User Number
 PRINT User
 Согласно этим командам нужно соответственно добавить пользователя в телефонную книгу, удалить пользователя, изменить его номер и вывести на экран его данные. В случае невозможности выполнить действие, необходимо вывести ERROR. Добавлять пользователя, уже существующего в телефонной книге нельзя.
 Необходимо вывести протокол работы телефонной книге
 Input format
 Output format
 В случае невозможности выполнения действия
 ERROR
 В случае команды PRINT User
 User Number*/

using namespace std;

int main(int argc, const char * argv[]) {
    
    map<string, string> users;
    vector<string> protocol;
    int N;
    cin >> N;
    string command;
    
    for(int i = 0; i < N; i++) {
        cin >> command;
        
        string name, phone;
        
        if (command == "ADD") {
            cin >> name >> phone;
            if (users.find(name) == users.end()) {
                users[name] = phone;
            } else {
                protocol.push_back("ERROR");
            }
        } else if (command == "DELETE") {
            cin >> name;
            if (users.find(name) == users.end()) {
                protocol.push_back("ERROR");
            } else {
                users.erase(name);
            }
        } else if (command == "EDITPHONE") {
            cin >> name >> phone;
            if (users.find(name) == users.end()) {
                protocol.push_back("ERROR");
            } else {
                users[name] = phone;
            }
        } else if (command == "PRINT") {
            cin >> name;
            if (users.find(name) == users.end()) {
                protocol.push_back("ERROR");
            } else {
                protocol.push_back(name + " " + users[name]);
            }
        }
    }
        
    for (int i = 0; i < protocol.size(); i++) {
        cout << protocol[i] << endl;
    }
    
    return 0;
}
