#include <iostream>
#include "prototype/compare.cpp"
#include <vector>

using namespace std;

typedef void (*PFT) ( char ,int );

void bar(char ch, int i)
{
    cout<<"bar "<<ch<<' '<<i<<endl;
}

class Bar2 {
public:
    void operator() (char ch, int i) {
        cout<<"bar2 "<<ch<<' '<<i<<endl;
    }
};

void foo(char ch, int i, PFT pf)
{
    pf(ch,i);
}

void foo2(char ch, int i, void (*pf)(char, int))
{
    pf(ch,i);
}

void foo3(char ch, int i, Bar2& bar2) {
    bar2(ch, i);
}


//int main() {
//    PFT pft = bar;
//    void (*p)(char, int) = bar;
//    foo('e',12,pft);
//    foo('e',12,bar);
//    foo('e',12,p);
//    foo2('e',12,bar);
//    foo2('e',12,p);
//    foo2('e',12,pft);
//
//    Bar2 bar2;
//    foo3('e', 12, bar2);
//    vector<int> a(5);
//    for (int i : a)
//        cout << i << "\t";
//    cout << endl;

//    string* a = new string(1, '2');
//    a->append(1, 'c');
//    cout << a  << "\t" << *a << endl;
//    a->push_back('d');
//    cout << a  << "\t" << *a << endl;

//    string s = to_string('a');
//    cout << s << endl;  // "97", not "a"
//    char a = 'c';
//    cout << isalnum(a) << endl;
//}