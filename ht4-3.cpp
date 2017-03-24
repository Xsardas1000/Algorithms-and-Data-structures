//
//  ht4-3.cpp
//  sphere
//
//  Created by Максим on 12.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

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

using namespace:: std;

enum {
    MAX = 1000,
    LEN = 1000
};

string protocol[MAX];
int n = 0;

struct Users {
    string name;
    string phone;
    Users *next;
    Users *prev;
};

Users* add_user(Users *head, string user_name, int user_phone);
Users* delete_user (Users *head, string user_name);
Users* find_and_action (Users *head, string command, string user_name, string user_phone);


Users* add_user(Users *head, string user_name, string user_phone) {
    Users *saved_head = head;
    if (head == NULL) {
        Users *new_head = new Users;
        new_head -> next = NULL;
        new_head -> prev = NULL;
        new_head -> name = user_name;
        new_head -> phone = user_phone;
        return new_head;
    }
    while (head -> next != NULL && head -> name != user_name) {
        head = head -> next;
    }
    if (head -> name == user_name) {
        protocol[n++] = "ERROR";
    } else {
        Users *new_user = new Users;
        new_user -> next = NULL;
        new_user -> prev = head;
        new_user -> name = user_name;
        new_user -> phone = user_phone;
        head -> next = new_user;
    }
    return saved_head;
}

//returns false if the list already has user with the same name; returns true if added successful
Users* find_and_action (Users *head, string command, string user_name, string user_phone = "") {
    Users *saved_head = head;
    
    if (command == "DELETE") {
        return delete_user(head, user_name);
    }
    
    if (command == "ADD") {
        return add_user(head, user_name, user_phone);
    }

    while (head != NULL && head -> name != user_name) {
        head = head -> next;
    }
    
    if (head == NULL) {
        protocol[n++] = "ERROR";
        return saved_head;
    }
    
    if (command == "EDITPHONE") {
        head -> phone = user_phone;
    } else if (command == "PRINT") {
        protocol[n++] = head -> name + " " + head -> phone;

    }
    return saved_head;

}

Users* delete_user (Users *head, string user_name) {
    Users *saved_head = head;
    if (head == NULL) {
        protocol[n++] = "ERROR";
        return head;
    }
    if (head -> name == user_name && head -> next == NULL) { //if there is only one user
        delete head;
        return NULL;
    }
    
    while (head != NULL && head -> name != user_name) {
        head = head -> next;
    }
    if (head == NULL) {                 //if we have not found element
        protocol[n++] = "ERROR";
        
    } else if (head -> prev == NULL) {  //if we want to delete head element
        saved_head = head -> next;
        saved_head -> prev = NULL;
        delete head;
        
    } else if (head -> next == NULL) {  //if we want to delete last element
        head -> prev -> next = NULL;
        delete head;
        
    } else {                           //if we want to delete element between the others
        head -> prev -> next = head -> next;
        head -> next -> prev = head -> prev;
        delete head;
    }
    return saved_head;
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    Users *head = NULL;
    
    for (int i = 0; i < N; i++) {
        
        string command, name, phone;
        cin >> command;
        
        if (command == "ADD" || command == "EDITPHONE") {
            cin >> name >> phone;
            head = find_and_action(head, command, name, phone);
            
        } else if (command == "DELETE" || command == "PRINT") {
            cin >> name;
            head = find_and_action(head, command, name);

        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << protocol[i] << endl;
    }
    
    
    return 0;
}