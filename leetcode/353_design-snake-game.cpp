//Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
//
//The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
//
//You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
//
//Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
//
//When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
//
//Example:
//    Given width = 3, height = 2, and food = [[1,2],[0,1]].
//
//    Snake snake = new Snake(width, height, food);
//
//    Initially the snake appears at position (0,0) and the food at (1,2).
//
//    |S| | |
//    | | |F|
//
//    snake.move("R"); -> Returns 0
//
//    | |S| |
//    | | |F|
//
//    snake.move("D"); -> Returns 0
//
//    | | | |
//    | |S|F|
//
//    snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
//
//    | |F| |
//    | |S|S|
//
//    snake.move("U"); -> Returns 1
//
//    | |F|S|
//    | | |S|
//
//    snake.move("L"); -> Returns 2 (Snake eats the second food)
//
//    | |S|S|
//    | | |S|
//
//    snake.move("U"); -> Returns -1 (Game over because snake collides with border)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/47385/c-straightforward-solution
// Time:	O(1)
// Space:	O(n)
class SnakeGame {
    queue<pair<int, int>> path;
    unordered_set<int> body;
    int m, n, count = 0;
    queue<pair<int, int>> food_que;
    pair<int, int> current_food;
    unordered_map<string, pair<int, int>> steps = {
        {"R", {0,  1}},
        {"L", {0,  -1}},
        {"U", {-1, 0}},
        {"D", {1,  0}}
    };
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        path.push({0, 0});
        body.insert(hashValue(pair<int, int>(0, 0)));
        m = height;
        n = width;
        for (auto ele : food)
            food_que.push(ele);
        if (!food.empty()) {
            current_food = food_que.front();
            food_que.pop();
        } else
            current_food = pair<int, int>(-1, -1);
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto &head = path.back();
        auto step = steps[direction];
        auto ahead = pair<int, int>(head.first + step.first, head.second + step.second);
        int ahead_hash = hashValue(ahead);
        if (ahead.first < 0 || ahead.first == m || ahead.second < 0 || ahead.second == n
            || (body.find(ahead_hash) != body.end() && ahead != path.front()))
            return -1;
        if (ahead == current_food) {
            if (!food_que.empty()) {
                current_food = food_que.front();
                food_que.pop();
            } else
                current_food == pair<int, int>(-1, -1);
            count++;
        } else {
            body.erase(hashValue(path.back()));
            path.pop();
        }
        path.push(ahead);
        return count;
    }

    int hashValue(pair<int, int> ele) {
        return n * ele.first + ele.second;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */


//int main() {
//    vector<pair<int, int>> food = {{2,0},{0,0},{0,2},{0,1},{2,2},{0,1}};
//    vector<string> directions = {"D", "D", "R", "U", "U", "L", "D", "R", "R", "U", "L", "L", "D", "R", "U"};
//    int width = 3, height = 3;
//    SnakeGame obj(width, height, food);
//    for (string direction : directions)
//        cout << obj.move(direction) << endl;
//}