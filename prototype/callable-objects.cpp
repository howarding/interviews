#include <iostream>
#include <vector>
using namespace std;

/**
 * Function-object CLASS
 */
class ClassShorter {
public:
    bool operator() (const string& a, const string& b) {
        return a.size() < b.size();
    }
};

/**
 * Function
 * Binary Predicate
 * @param a
 * @param b
 * @return bool
 */
static bool isShorter(const string& a, const string& b) {
    return a.size() < b.size();
}


/**
 * Lambda Expr.
 */
auto lambdaShorter = [](const string& a, const string& b) {
    return a.size() < b.size();
};


/**
 * Function pointer Define
 * @return
 */
static bool (*pointerShorter) (const string&, const string&);


void print(vector<string>& vec) {
    for (const auto &ele: vec) {
        cout << ele << " ";
    }
    cout << endl;
}

//int main() {
//    vector<string> sentence{"which", "provide", "a", "way", "to", "pass", "around", "instructions", "on", "how", "to", "perform", "an", "operation"};
//
//    vector<string> s1 = sentence;
//    cout << "Sentence:" << endl;
//    print(s1);
//    /** Object of a function-obj class */
//    sort(s1.begin(), s1.end(), ClassShorter());
//    cout << "After sort with ClassShorter:" << endl;
//    print(s1);
//
//    vector<string> s2 = sentence;
//    cout << endl << "Sentence:" << endl;
//    print(s2);
//    /** Function converted to a function pointer */
//    sort(s2.begin(), s2.end(), isShorter);
//    cout << "After sort with isShorter:" << endl;
//    print(s2);
//
//    vector<string> s3 = sentence;
//    cout << endl << "Sentence:" << endl;
//    print(s3);
//    /** Lambda expr. */
//    sort(s3.begin(), s3.end(), lambdaShorter);
//    cout << "After sort with isShorter:" << endl;
//    print(s3);
//
//    pointerShorter = isShorter;
//    vector<string> s4 = sentence;
//    cout << endl << "Sentence:" << endl;
//    print(s4);
//    /** Function pointer */
//    sort(s4.begin(), s4.end(), pointerShorter);
//    cout << "After sort with isShorter:" << endl;
//    print(s4);
//
//}