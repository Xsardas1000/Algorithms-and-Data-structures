//
//  ht3-2.cpp
//  sphere
//
//  Created by Максим on 02.04.16.
//  Copyright © 2016 Максим. All rights reserved.
//

#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include <string>

/*Лексикографическая сортировка
 Натуральные числа от 1 до N упорядочены лексикографически. Например, для N=25 результат этого упорядочения будет таким: 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 3, 4, 5, 6, 7, 8, 9.
 Требуется написать программу, которая определит, на каком месте оказалось число K.
 Input format
 Вход содержит два натуральных числа N и K, записанных через пробел (1 ≤ K ≤ N ≤ 3·107).
 Output format
 Выход должен содержать одно натуральное число – номер места, на котором оказалось число K.*/

using namespace std;

template <class T>
T* merge(T arr1[], int size1, T arr2[], int size2);

template <class T>
T* merge_sort(T arr[], int n) {
    if(n < 2){return arr;}
    int mid = n/2;
    T *arr1 = merge_sort<T>(arr,mid);
    T *arr2 = merge_sort<T>(arr+mid,n-mid);
    return merge(arr1, mid, arr2, n-mid);
}

template <class T>
bool comp(T x, T y) {
    if (to_string(x) >= to_string(y)) {
        return true;
    }
    return false;
}

template <class T>
T* merge(T arr1[], int size1, T arr2[], int size2) {
    int i = 0,j = 0;
    
    T* out_array = new T[size1 + size2];
    
    while((i < size1) && (j < size2)) {
        //if(arr1[i] >= arr2[j])
        if (comp(arr1[i], arr2[j])) {
            out_array[i+j] = arr2[j];
            ++j;
        }
        else {
            out_array[i+j] = arr1[i];
            ++i;
        }
    }
    while(i < size1) {
        out_array[i+j] = arr1[i];
        i++;
    }
    while(j < size2) {
        out_array[i+j] = arr2[j];
        j++;
    }
    return out_array;
}


int main(int argc, const char * argv[]) {
    int n, m;
    //string m;
    cin >> n >> m;
    
    //string *arr_s = new string[n];
    int *arr_n = new int[n];
    
    for (int i = 0; i < n; i++) {
        arr_n[i] = i + 1;
    }
    
    arr_n = merge_sort(arr_n, n);
    for (int i = 0; i < n; i++) {
        if (m == arr_n[i]) {
            cout << i + 1 << endl;
        }
    }
    
    
    /*
    for (int i = 0; i < n; i++) {
        arr_s[i]= to_string(arr_n[i]);
    }
    
    arr_s = merge_sort(arr_s, n); 
     */
    
    /*
    for (int i = 0; i < n; i++) {
        if (m == arr_s[i]) {
            cout << i + 1 << endl;;
            return 0;
        }
    }*/
    return 0;
}


