#include "dijkstras.h"

class myComparator
{
public:
    int operator() (const pair<int,int> & p1, const pair<int, int>& p2)
    {
            return p1.second > p2.second;
    }
};


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector <bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;
    priority_queue<pair<int,int>> minHeap;
    //std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, myComparator> minHeap;
    minHeap.push({source,0});
    while(!minHeap.empty()){
        //int u = extract_shortest_path(distances, previous, minHeap.first)[minHeap.first];
        int u = minHeap.top().first;
        //minHeap.extract_shortest_path().first;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for (Edge edge: G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
    //return extract_shortest_path(distances, previous, )
}


vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> shortest;
    int distance = distances[destination];
    int j = -1;
    for(int i = 0; j != destination; ++i)
    {
        if(previous[i] == j){
            shortest.push_back(i);
            j = i;
            i = 0;
        }
    }
    return shortest;
}



void print_path(const vector<int>& v, int total){
    //total = 0;
    for (auto i: v){
        cout << i << " "; 
        //total += i;
    }
    std::cout << "\nTotal cost is " << total << "\n";
    
}