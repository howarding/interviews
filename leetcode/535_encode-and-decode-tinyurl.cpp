//Note: This is a companion problem to the System Design problem: Design TinyURL.
//TinyURL is a URL shortening service where you enter a URL such as
// https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
//
//Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/81637/two-solutions-and-thoughts
// Time:	O(1)
// Space:	O(1)
class Solution_535 {
    vector<string> urls;
    unordered_map<string, int> dict;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (dict.find(longUrl) == dict.end()) {
            urls.push_back(longUrl);
            dict[longUrl] = urls.size() - 1;
        }
        return "http://tinyurl.com/" + to_string(dict[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[stoi(shortUrl.substr(shortUrl.find_last_of("/") + 1))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));