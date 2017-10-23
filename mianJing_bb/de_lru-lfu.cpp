//1. Design top k recent visited websites. (LRU)
//2. 设计一个系统，需要及时看到最新更新的三只股票. (LRU)
//3. Design and implement a web browser in which you can give the top k visited websites on basis of number of
//   visits(top k most frequently visited), you can remove and undo. (LFU)

#include <iostream>
#include <unordered_map>
#include <list>
#include <time.h>

using namespace std;

// Case 1. (Case 2 is the same)
// LRU
struct Webpage {
    string url;
    Webpage(const string& str): url(str) {}
};

class History{
    int _capacity;
    unordered_map<string, list<Webpage>::iterator> dict;
    list<Webpage> cache;
public:
    History(int num) {
        _capacity = num;
    };
    void visit(const string& url) {
        Webpage webpage(url);
        if (dict.find(webpage.url) != dict.end())
            cache.erase(dict[webpage.url]);
        else if (cache.size() == _capacity) {
            dict.erase(cache.back().url);
            cache.pop_back();
        }
        cache.push_front(webpage);
        dict[webpage.url] = cache.begin();
//        dict[webpage.url] = prev(cache.end());
    }

    void remove(const string& url) {
        if (dict.find(url) != dict.end()) {
            cache.erase(dict[url]);
            dict.erase(url);
        }
    }

    void printTopK() {
        list<Webpage>::iterator iter = cache.begin();
        for (int i = 0; i < _capacity && iter != cache.end(); iter++, i++)
            cout << (*iter).url << endl;
    }
};




// Case 3.
// LFU
struct Website {
    string url;
    Website(const string& str): url(str) {}
};


class Browser {
    int _capacity;
    int num;
    int min_count;
    int max_count;
    unordered_map<string, pair<int, list<Website>::iterator>> dict;
    unordered_map<int, list<Website>> cache;
public:
    Browser(int k) {
        _capacity = k;
        num = 0;
        min_count = 0;
        max_count = 0;
    }

    void visit(const string& url) {
        Website website(url);
        int count = 0;
        if (dict.find(url) != dict.end()) {
            cache[dict[url].first].erase(dict[url].second);
            count = dict[url].first + 1;
            if (cache[min_count].empty()) min_count++;
            max_count = max(max_count, count);
        } else {
            count = min_count = 1;
            if (num++ == _capacity) {
                dict.erase(cache[min_count].back().url);
                cache[min_count].pop_back();
                num--;
                if (cache[max_count].empty()) max_count = min_count;
            }
        }
        cache[count].push_front(website);
        dict[url] = {count, cache[count].begin()};
    }

    void remove(const string& url) {
        if (dict.find(url) != dict.end()) {
            cache[dict[url].first].erase(dict[url].second);
            if (cache[dict[url].first].empty()) min_count--;
            dict.erase(url);
            num--;
        }
    }

    void printTopK() {
        int count = max_count, i = 0;
        while (i < _capacity && count >= min_count) {
            list<Website>::iterator iter = cache[count].begin();
            for (; iter != cache[count].end() && i < _capacity; iter++, i++)
                cout << count << "\t" << (*iter).url << endl;
            count--;
        }

    }
};



int main()
{
//    int k = 5;
//    History h(k);
    int k = 2;
    Browser h(k);
    cout << "before visits:\n";
    h.visit("nytimes.com");
    h.visit("guardian.co.uk");
    h.visit("www.google.com");
    h.visit("dev.ibm.com");
    h.visit("www.google.com");
    h.visit("www.google.com");
    h.visit("www.google.com");
//    h.visit("guardian.co.uk");
    cout << "after  visits:\n";
    h.printTopK();
}