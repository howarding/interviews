////Design system/data structure来存real time stock信息. 给一个list的trade info, 格式是(name，交易时间(900=09:00, 1310=13:10)，
////price，share)，并且是实时更新的:
////("GOOGLE", "900", "130.1", "120")
////("GOOGLE", "901", "130.1", "100")
////("APPLE", "901", "798.4", "400")
////("GOOGLE", "902", "130.1", "90")
////("GOOGLE", "904", "130.1", "150")
////("GOOGLE", "1310", "130.1", "300")
////有一个update(name, share) function，每当有新的transaction的时候这个function就会被call.
////1. 得到目前为止某个股票的share总量. (hashmap)
////2. 要求得到当前股票最后一次价格和第一次价格之差
////3. 要求得到股票的最新价格
////4. 求avg price 用什么 data structure
////5. 随时会传进来一个topK(int k)函数，让你返回目前为止 topK share / topK price 的股票。
////6. 要求实时返回最新价格和最初价格之差最大的k只股票 (stockStream.cpp, O(klogn))
////7. 求从一天的开盘到收盘(开盘收盘时间给定)的5分钟window内的某个股票的最大交易数量，比如上个输入的输出就是：("GOOGLE", "900", "130.1",
////"120"), ("GOOGLE", "901", "130.1", "100"), ("GOOGLE", "902", "130.1", "90"), ("GOOGLE", "904", "130.1", "150") = 120 +
////100 + 90 + 150 = 460.
////    A: 做法sliding window用queue维护5分钟区间内的该股票的 trade info ，每循环到新的trade加入queue然后从后面剔除交易时间大于五分
////        钟的，meantime更新result sum。
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//
//using namespace std;
//
//struct Trade {
//    string name;
//    int time;
//    double price;
//    int share;
//    Trade(string& n, int t, double p, int s): name(n), time(t), price(p), share(s) {};
//};
//
//
//class System {
//    unordered_map<string, int> stock_share;
//    unordered_map<string, vector<double, double>> stock_price;
//    unordered_map<string, int> slide_stock_share;
//    queue<pair<int, pair<string, int>>> window;
//    int duration;
//    struct cmp_greater {
//        bool operator() (pair<string, int> a, pair<string, int> b) {
//            return a.second > b.second;
//        }
//    };
//public:
//    System() = default;
//
//    // Time:    O(1)
//    void update(Trade trade) {
//        stock_share[trade.name] += trade.share;
//        stock_price[trade.name][0] = trade.price - stock_price[trade.name][1];
//        stock_price[trade.name][1] = trade.price;
//    }
//
//    // Time:    O(1)
//    int getShare(string& name) {
//        return stock_share[name];
//    }
//
//    // Time:    O(1)
//    double getPriceChange(string& name) {
//        return stock_price[name][0];
//    }
//
//    // Time:    O(1)
//    double getUpdatePrice(string& name) {
//        return stock_price[name][1];
//    }
//
//    // Time:    O(n*log(k))
//    vector<string> topKShare(int k) {
//        vector<string> result;
//        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp_greater> min_heap;
//        for (auto&& pair : stock_share) {
//            if (min_heap.size() < k)
//                min_heap.push(pair);
//            else if (min_heap.top().second < pair.second) {
//                min_heap.push(pair);
//                min_heap.pop();
//            }
//        }
//        while (!min_heap.empty()) {
//            string stock = min_heap.top().first;
//            min_heap.pop();
//            result.push_back(stock);
//        }
//        reverse(result.begin(), result.end());
//        return result;
//    }
//
//    System(int time) {
//        duration = time;
//    }
//
//    // Time:    O(n)
//    void newTrade(Trade trade) {
//        while (window.front().first < trade.time - duration) {
//            slide_stock_share[window.front().second.first] -= window.front().second.second;
//            window.pop();
//        }
//        window.push({trade.time, {trade.name, trade.share}});
//        slide_stock_share[trade.name] += trade.share;
//    }
//
//    // Time:    O(k)
//    string getMaxShare(int time) {
//        while (window.front().first < time - duration) {
//            slide_stock_share[window.front().second.first] -= window.front().second.second;
//            window.pop();
//        }
//        string result;
//        int maxShare = -1;
//        for (auto&& pair : slide_stock_share) {
//            if (pair.second > maxShare) {
//                maxShare = pair.second;
//                result = pair.first;
//            }
//        }
//        return result;
//    }
//
//};