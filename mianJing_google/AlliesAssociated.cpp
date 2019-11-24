//给定一些String代表players，再给一个list，叫allies，存储了两两player那两个是盟友，然后让完成两个function，一个叫isAllies，
//输入两个player，返回是否是allies；另一个叫isAssociated，输入两个player，返回是否属于一个阵营（属于一个阵营的定义是有共同盟友
//或者本身这两个就是盟友）
//  player：A，B and C;
//  allies:{[A,B] , [B,C]};
//此时
//    isAllies（A，B） == true;
//    isAllies(A , C) == false;
//    isAssociated（A，C）== true;
//    因为都有盟友B

#include <iostream>
#include <vector>

using namespace std;

class AlliesAssociated {
public:
    AlliesAssociated (vector<string>& players, vector<vector<string>>& allies) {

    }

    bool isAllies(const string& a, const string& b) {

    }

    bool isAssociated(const string& a, const string& b) {

    }
};