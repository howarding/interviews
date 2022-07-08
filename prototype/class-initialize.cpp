#include <iostream>
#include <utility>

using namespace std;

class IntPair {
public:
    IntPair(string name, int a, int b): name(move(name)), first(a), second(b) {};
//    IntPair() = default;
    IntPair(): name("no name"), first(-1), second(-1) {};
    friend void print(IntPair&);
protected:
    string name;
    int first = 0;
    int second = 0;
};

void print(IntPair &intPair) {
    cout << intPair.name << "\tFirst: " << intPair.first << "\tSecond: " << intPair.second << endl;
}


//int main() {
//    IntPair intPair;
//    print(intPair);
//    IntPair intPair1("intPair1", 1, 5);
//    print(intPair1);
//    // IntPair intPair2();
//    IntPair intPair2{};
//    print(intPair2);
//    IntPair intPair3{"intPair3", 3, 5};
//    print(intPair3);
//    IntPair intPair4 = {"intPair4", 4, 5};
//    print(intPair4);
//    IntPair intPair5 = IntPair("intPair5", 5, 5);
//    print(intPair5);
//    auto *intPair6 = new IntPair("intPair6", 6, 5);
//    print(*intPair6);
//    IntPair intPair7 = IntPair{"intPair7", 7, 5};
//    print(intPair7);
//}
