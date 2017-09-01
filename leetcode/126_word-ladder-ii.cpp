//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//        Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log","cog"]
//Return
//    [
//        ["hit","hot","dot","dog","cog"],
//        ["hit","hot","lot","log","cog"]
//    ]
//
//Note:
//    Return an empty list if there is no such transformation sequence.
//    All words have the same length.
//    All words contain only lowercase alphabetic characters.
//    You may assume no duplicates in the word list.
//    You may assume beginWord and endWord are non-empty and are not the same.
//UPDATE (2017/1/20):
//The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution_126 {
public:
    // 1. BFS   2. DFS
    // Exp: https://discuss.leetcode.com/topic/27504/my-concise-java-solution-based-on-bfs-and-dfs
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        if (wordList.empty()) return result;
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> neighbors;
        int distance = getDistance(beginWord, endWord, words, neighbors);
        if (!distance) return result;
        vector<string> path;
        path.push_back(beginWord);
        unordered_set<string> visited;
        words.insert(endWord);
        helper(endWord, distance, words, neighbors, path, result);
        return result;
    }


    int getDistance(
            string& beginWord,
            string& endWord,
            unordered_set<string>& words,
            unordered_map<string, unordered_set<string>>& neighbors
    ) {
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;
        int distance = 0;
        bool found = false;

        while (!que.empty()) {
            int num = que.size();
            distance++;
            for (int n = 0; n < num; n++) {
                string& word = que.front();
                string key = word;
                que.pop();
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (int k = 0; k < 26; k++) {
                        word[i] = 'a' + k;
                        if (word == endWord) {
                            found = true;
                            neighbors[key].insert(word);
                        }
                        if (words.count(word) && !visited.count(word)) {
                            que.push(word);
                            visited.insert(word);
                            neighbors[key].insert(word);
                        }
                    }
                    word[i] = c;
                }
            }
            if (found)
                return distance;
        }
        return 0;
    }

    void helper(
            string& endWord,
            int distance,
            unordered_set<string>& words,
            unordered_map<string, unordered_set<string>>& neighbors,
            vector<string>& path,
            vector<vector<string>>& result
    ) {
        if (!distance)
            return;
        string& word = path.back();
        for (const string& neighbor : neighbors[word]) {
            path.push_back(neighbor);
            if (neighbor == endWord) result.push_back(path);
            helper(endWord, distance - 1, words, neighbors, path, result);
            path.pop_back();
        }
    }
};


//int main() {
//    Solution_126 sol;
////    string beginWord = "hit";
////    string endWord = "cog";
////    vector<string> wordList({"hot","dot","dog","lot","log","cog"});
//    string beginWord = "cet";
//    string endWord = "ism";
//    vector<string> wordList({"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"});
//    vector<vector<string>> result(sol.findLadders(beginWord, endWord, wordList));
//    for (auto&& path : result) {
//        for (auto& word : path)
//            cout << word << "\t";
//        cout << endl;
//    }
//}