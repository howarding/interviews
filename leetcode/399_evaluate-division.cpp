//Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
//Example:
//Given a / b = 2.0, b / c = 3.0.
//queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
//return [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
//
//According to the example above:
//
//    equations = [ ["a", "b"], ["b", "c"] ],
//    values = [2.0, 3.0],
//    queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
//The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution_399 {
public:
    // BFS
    // Time:	O(n)
    // Space:	O(1)
    vector<double>
    calcEquation(vector<pair<string, string>> equations, vector<double> &values, vector<pair<string, string>> queries) {
        vector<double> result;
        if (equations.empty()) return result;
        unordered_map<string, unordered_map<string, double>> dic;
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            double value = values[i];
            dic[equation.first][equation.second] = value;
            dic[equation.second][equation.first] = 1 / value;
            dic[equation.first][equation.first] = 1.0;
            dic[equation.second][equation.second] = 1.0;
        }

        for (auto query : queries) {
            if (dic.find(query.first) == dic.end() || dic.find(query.second) == dic.end()) {
                result.push_back(-1.0);
                continue;
            }
            queue<string> vars;
            unordered_set<string> visited;
            vars.push(query.first);
            visited.insert(query.first);
            double value = -1.0;
            while (!vars.empty()) {
                string &var = vars.front();
                vars.pop();
                if (dic[query.first].find(query.second) != dic[query.first].end()) {
                    value = dic[query.first][query.second];
                    break;
                }
                for (auto neighbor : dic[var]) {
                    if (visited.find(neighbor.first) != visited.end())
                        continue;
                    dic[query.first][neighbor.first] = dic[query.first][var] * dic[var][neighbor.first];
                    dic[neighbor.first][query.first] = 1 / dic[query.first][neighbor.first];
                    vars.push(neighbor.first);
                    visited.insert(neighbor.first);
                }
            }
            result.push_back(value);
        }
        return result;
    }
};


//int main() {
//    vector<pair<string, string>> equations({{"a", "b"}, {"b", "c"}});
//    vector<double> values({2.0, 3.0});
//    vector<pair<string, string>> queries({{"a", "c"}, {"b", "c"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});
//
//    Solution_399 sol;
//    vector<double> result = sol.calcEquation(equations, values, queries);
//    for (double val : result)
//        cout << val << "\t";
//}