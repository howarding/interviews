//Generate a copy of a given graph

#include <vector>
#include <unordered_map>

using namespace std;

class Vertex {
public:
    int val;
    vector<Vertex*> neighbors;

    Vertex(int v): val(v) {};
};


class Graph {
public:
    vector<Vertex*> vertices;
    Graph() {};

    // HashMap, Iterative
    // Time:    O(m + n)    m: num of vertices  n: num of edges
    // Space:   O(m)
    Graph* cloneGraph(Graph& g) {
        Graph* g2;
        unordered_map<Vertex*, Vertex*> dict;
        for (Vertex* vertex: vertices) {
            if (dict.find(vertex) == dict.end()) {
                dict[vertex] = new Vertex(vertex->val);
                g2->vertices.push_back(dict[vertex]);
            }

            for (Vertex* neighbor: vertex->neighbors) {
                if (dict.find(neighbor) == dict.end()) {
                    dict[neighbor] = new Vertex(neighbor->val);
                    g2->vertices.push_back(dict[neighbor]);
                }
                dict[vertex]->neighbors.push_back(dict[neighbor]);
            }
        }
        return g2;
    }
};