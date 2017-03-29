//Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
//
//Machine 1 (sender) has the function:
//
//    string encode(vector<string> strs) {
//        // ... your code
//        return encoded_string;
//    }
//
//Machine 2 (receiver) has the function:
//    vector<string> decode(string s) {
//        //... your code
//        return strs;
//    }
//
//So Machine 1 does:
//
//    string encoded_string = encode(strs);
//
//and Machine 2 does:
//
//    vector<string> strs2 = decode(encoded_string);
//
//strs2 in Machine 2 should be the same as strs in Machine 1.
//
//Implement the encode and decode methods.
//
//Note:
//    The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
//    Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
//    Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.

//follow up: 如果任何invalid input都要return null怎么做。 之后让写unit test
//A: decode 的时候，如果传入的string 没有@，没有长度，或者长度@出现次数不匹配等等情况都要return null。

#include <iostream>
#include <vector>

using namespace std;

class Codec {
public:
    // Exp: https://leetcode.com/problems/encode-and-decode-strings/
    // Time:	O(n)
    // Space:	O(n)
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string result;
        for (string &str : strs) {
            int len = str.size();
            result += to_string(len) + '@' + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    // Handle invalid input cases.
    vector<string> decode(string s) {
        vector<string> result;
        int head = 0;
        // No '@' chars.
        if (s.find('@') == string::npos) return {};
        while (head < s.size()) {
            int num_pos = s.find_first_of("@", head);
            // # '@' and # string don't match.
            if (num_pos == string::npos) return {};
            string num_str = s.substr(head, num_pos - head);
            // substring before '@' is not a number
            if (!is_number(num_str)) return {};
            int num = stoi(num_str);
            result.push_back(s.substr(num_pos + 1, num));
            head = num_pos + num + 1;
        }
        return result;
    }

    // Check whether a string is a number
    bool is_number(string &s) {
        for (char c : s)
            if (!isdigit(c)) return false;
        return true;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));//
// Created by Howard Ding on 2/11/17.
//

