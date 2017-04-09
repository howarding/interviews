//
// Created by Howard Ding on 11/25/16.
//

#include <iostream>
#include <typeinfo>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

//int main() {
//    vector<int> a({1, 2, 2, 1, 5, 3});
////    list<int> c = a;
//    auto b = typeid(a).name();
//    int d = 10;
//    cout << b << endl;
////    cout << typeid(c).name() << endl;
//    cout << typeid(d).name() << endl;
//    for (auto i : a) {// access by value
//        cout << i << "\t";
//        i++;
//    }
//    cout << endl;
//    for (int& i : a) {// access by reference
//        cout << i << "\t";
//        i++;
//    }
//    cout << endl;
//    for (auto& i : a) {// access by reference
//        cout << i << "\t";
//        i++;
//    }
//    cout << endl;
//    for (const auto& i : a) {// access by const reference
//        cout << i << "\t";
////        i++; // i is a const, not assignable
//    }
//    cout << endl;
//
//
//
//    map<int, int> e;
//    for (int i = 0; i < 6; i++)
//        e[i]++;
//    for (auto && ele : e)
//        cout << ele.first << "\t" << ele.second << endl;
//}