//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
//Note:
//    1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//    2. All airports are represented by three capital letters (IATA code).
//    3. You may assume all tickets form at least one valid itinerary.
//Example 1:
//tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
//Example 2:
//tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
//Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution_332 {
public:
    // DFS
    // Exp: https://www.hrwhisper.me/leetcode-reconstruct-itinerary/
    // Time:	O(n)
    // Space:	O(n)
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        if (tickets.empty()) return result;
        map<string, map<string, int>> dict;
        for (auto &&ticket : tickets)
            dict[ticket.first][ticket.second]++;
        string start = "JFK";
        result.push_back(start);
        helper(dict, start, tickets.size() + 1, result);
        return result;
    }

    bool helper(map<string, map<string, int>> &dict, string start, int total, vector<string> &result) {
        if (result.size() == total) return true;
        for (auto &&ticket : dict[start]) {
            if (!ticket.second) continue;
            result.push_back(ticket.first);
            ticket.second--;
            if (helper(dict, ticket.first, total, result)) return true;
            result.pop_back();
            ticket.second++;
        }
        return false;
    }
};


//int main() {
//    vector<pair<string, string>> tickets({{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}});
//    Solution_332 sol;
//    vector<string> result = sol.findItinerary(tickets);
//    for (string city : result)
//        cout << city << endl;
//}