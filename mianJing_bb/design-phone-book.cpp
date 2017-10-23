//Given a list of contacts which exist in a phone directory. The task is to implement search query for the phone
//directory. The search query on a string ‘str’ displays all the contacts which prefix as ‘str’.
//Example:
//
//Input : contacts [] = {“gforgeeks” , “geeksquiz” }
//        Query String = “gekk”
//
//Output : Suggestions based on "g" are
//        geeksquiz
//        gforgeeks
//
//        Suggestions based on "ge" are
//        geeksquiz
//
//        No Results Found for "gek"
//
//        No Results Found for "gekk"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define N 26

struct TrieNode {
    bool isEnd;
    string contact;
    vector<TrieNode *> child;

    TrieNode(int n) : isEnd(false), child(n) {}
};


class phoneBook {
    TrieNode* trie;
public:
    phoneBook(vector<string>& contacts) {
        trie = new TrieNode(N);
        TrieNode* node;
        for(string& contact : contacts) {
            node = trie;
            for (char c : contact) {
                if (!node->child[c])
                    node->child[c] = new TrieNode(N);
                node = node->child[c];
            }
            node->isEnd = true;
            node->contact = contact;
        }
    }


    // BFS
    // Time:    O(26^(h - n))     h: height of trie. n: length of prefix
    vector<string> display(string& prefix) {
        vector<string> result;
        TrieNode* node = trie;
        for (char c : prefix) {
            if (!node->child[c])
                return result;
            node = node->child[c];
        }
        queue<TrieNode*> nodes;
        nodes.push(node);
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            if (node->isEnd) result.push_back(node->contact);
            for (TrieNode* child : node->child)
                if (child) nodes.push(child);
        }
        return result;
    }
};