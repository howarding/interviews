//Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth
// characters and is fully (left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces
// ' ' when necessary so that each line has exactly maxWidth characters.
//
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not
// divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left-justified, and no extra space is inserted between words.
//
//Note:
//
//A word is defined as a character sequence consisting of non-space characters only.
//Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//The input array words contains at least one word.
//
//
//Example 1:
//
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
//Output:
//[
//"This    is    an",
//"example  of text",
//"justification.  "
//]
//Example 2:
//
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
//Output:
//[
//"What   must   be",
//"acknowledgment  ",
//"shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be
// left-justified instead of fully-justified.
//Note that the second line is also left-justified because it contains only one word.
//Example 3:
//
//Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art",
// "is","everything","else","we","do"], maxWidth = 20
//Output:
//[
//"Science  is  what we",
//"understand      well",
//"enough to explain to",
//"a  computer.  Art is",
//"everything  else  we",
//"do                  "
//]
//
//
//Constraints:
//
//1 <= words.length <= 300
//1 <= words[i].length <= 20
//words[i] consists of only English letters and symbols.
//1 <= maxWidth <= 100
//words[i].length <= maxWidth

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution_069 {
public:
    // Exp: https://discuss.leetcode.com/topic/4189/share-my-concise-c-solution-less-than-20-lines
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        vector<string> inline_words;
        int start = 0;
        while (start < words.size()) {
            inline_words.clear();
            inline_words.push_back(words[start]);
            int line_length = words[start].size();
            int i = start + 1;
            for (; i < words.size(); i++) {
                if (line_length + words[i].size() + 1 > maxWidth)
                    break;
                line_length += words[i].size() + 1;
                inline_words.push_back(words[i]);
            }
            // Last line
            if (i == words.size()) {
                string line = "";
                for (int j = 0; j < inline_words.size(); j++) {
                    line.append(j == 0 ? inline_words[j] : " " + inline_words[j]);
                }
                line.append(maxWidth - line.size(), ' ');
                result.push_back(line);
                return result;
            }

            // Not last line
            int word_length = accumulate(
                    inline_words.begin(),
                    inline_words.end(),
                    0,
                    [](int length, const string& word) { return length + word.size();}
                    );
            int space_num = maxWidth - word_length;
            int slot_num = inline_words.size() - 1;
            string line = inline_words[0];
            // Only 1 word in line
            if (slot_num == 0) {
              line.append(space_num, ' ');
            } else {
              int space = space_num % slot_num ? (space_num / slot_num + 1) : (space_num / slot_num);
              int remain = space_num;
              int short_space = space_num / slot_num;
              int long_space = space_num % slot_num ? short_space + 1 : short_space;
              for (int j = 1; j < inline_words.size(); j++) {
                string space_str = j <= space_num % slot_num ? string(long_space, ' ') : string(short_space, ' ');
                line.append(space_str + inline_words[j]);
                remain -= space;
              }
            }
            result.push_back(line);
            start = i;
        }
        return result;
    }
};