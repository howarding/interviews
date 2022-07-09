#include <iostream>
#include <vector>

using namespace std;

/**
 * Class has explicit default constructor
 */
class SizeGreater {
public:
    /** Default Constructor */
    SizeGreater(): sz(3) {};
    explicit SizeGreater(size_t n): sz(n) {};
    bool operator() (const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;
};

/**
 * Class has NO defined constructor
 * synthesized default constructor
 */
class SizeLess {
public:
    bool operator() (const string &s) const {
        return s.size() <= sz + 4;
    }
private:
    size_t sz;
};

class Strings {
public:
    static bool compare_less(const string& a, const string& b) {
        return a.size() < b.size();
    }

    static bool compare_greater(const string& a, const string& b) {
        return a.size() > b.size();
    }

    template <typename T>
    void print(typename vector<T>::iterator start, typename vector<T>::iterator end) {
        for (auto iter = start; iter != end; iter++)
            cout << *iter << " ";
        cout << endl;
    }
};

//int main() {
//    // Default Initialization
//    SizeGreater sizeGreater;
//    SizeLess sizeLess;
//
//    vector<string> sentence1{"which", "provide", "a", "way", "to", "pass", "around", "instructions", "on", "how", "to", "perform", "an", "operation"};
//    vector<string> sentence2{"But", "function", "pointers", "are", "limited", "because", "functions", "must", "be", "fully", "specified", "at", "compile", "time"};
//    vector<string> sentence3{"You", "could", "create", "different", "functions", "that", "differ", "only", "by", "the", "field", "of", "the", "message", "on", "which", "the", "comparison", "occurs"};
//    vector<string> sentence4{"It's", "also", "going", "to", "lead", "to", "a", "lot", "of", "if-then-else", "blocks", "that", "differ", "only", "by", "the", "function", "passed", "into", "the", "sort", "routine"};
//
//    // Default Initialization
//    Strings strings;
//    vector<string> sen;
//
//    cout << "Sentence 1:" << endl;
//    sen = sentence1;
//    cout << "\tBefore sorting:" << endl;
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tAfter sorting:" << endl;
//    /** Function pointer */
//    sort(sen.begin(), sen.end(), Strings::compare_less);
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tFind greater:" << endl;
//    /** Function object */
//    auto iter = find_if(sen.begin(), sen.end(), sizeGreater);
//    strings.print<string>(iter, sen.end());
//
//    cout << endl << endl << "Sentence 2:" << endl;
//    sen = sentence2;
//    cout << "\tBefore sorting:" << endl;
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tAfter sorting:" << endl;
//    /** Function pointer */
//    sort(sen.begin(), sen.end(), Strings::compare_greater);
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tFind less:" << endl;
//    /** Function object */
//    iter = find_if(sen.begin(), sen.end(), sizeLess);
//    strings.print<string>(iter, sen.end());
//
//    cout << endl << endl << "Sentence 3:" << endl;
//    sen = sentence3;
//    cout << "\tBefore sorting:" << endl;
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tAfter sorting:" << endl;
//    /** Function pointer */
//    sort(sen.begin(), sen.end(), Strings::compare_less);
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tFind greater:" << endl;
//    /** Value Function object */
//    iter = find_if(sen.begin(), sen.end(), SizeGreater());
//    strings.print<string>(iter, sen.end());
//
//    cout << endl << endl << "Sentence 4:" << endl;
//    sen = sentence4;
//    cout << "\tBefore sorting:" << endl;
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tAfter sorting:" << endl;
//    /** Function pointer */
//    sort(sen.begin(), sen.end(), Strings::compare_greater);
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tFind less:" << endl;
//    iter = find_if(sen.begin(), sen.end(), SizeLess());
//    strings.print<string>(iter, sen.end());
//
//    cout << endl << endl << "Sentence 5:" << endl;
//    sen = sentence3;
//    cout << "\tBefore sorting:" << endl;
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tAfter sorting:" << endl;
//    /** Function pointer */
//    sort(sen.begin(), sen.end(), Strings::compare_less);
//    strings.print<string>(sen.begin(), sen.end());
//    cout << "\tFind greater:" << endl;
//    /** Value Function object */
//    iter = find_if(sen.begin(), sen.end(), SizeGreater(5));
//    strings.print<string>(iter, sen.end());
//
//}