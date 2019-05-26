#include <iostream>
#include <bitset>

using namespace std;

template <class T>
string to_binary_string(T num) {
    bitset<sizeof(T) * CHAR_BIT> bits(num);
    return bits.to_string();
}

//int main() {
//    int a = 3;
//    cout << to_binary_string(a) << endl;
//    cout << to_binary_string(3.45) << endl;
//    cout << to_binary_string('a') << endl;
//}