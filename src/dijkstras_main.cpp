#include "dijkstras.h"
#include <iostream>

using namespace std;

int main(){
    Graph g;
    file_to_graph("src/small.txt", g);

    for (auto edges: g)
        for(auto edge: edges)
            cout << edge;
    vector<int> prev;
    prev.resize(g.size());

    vector<int> dsp = dijkstra_shortest_path(g, 0, prev);
    std::cout << endl;
    for (auto i: dsp)
        cout << i << endl; 
    return 0;
}