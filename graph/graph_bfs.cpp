/*
 * =====================================================================================
 *
 *       Filename:  graph_bfs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2018 09:01:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <list>
#include <string>

using namespace std;


class GRAPH {
    int V;

    /*  Array of pointers to the adjacency lists */
    list <int> *adj;
    public:
    GRAPH(int v) {
        V = v;
        adj = new list<int>[v];
    };
    void addEdge(int v, int s);
    void BFS(int s);
    void DFSUtils(int s, int visited[]);
    void DFS(int s);
};


void GRAPH::addEdge (int v, int w) {
    adj[v].push_back(w); // Add w in the list of v's Edge
}
void GRAPH::BFS(int s) {
    int visited[V];
    for (int i=0; i< V; i++) {
        visited[i] = false;
    }
    list <int> queue;

    queue.push_back(s);
    while (!queue.empty()) {
        int cur = queue.front();
        cout << "Vertex is " << cur << endl;
        queue.pop_front();
        auto it = adj[cur].begin();
        for (;it != adj[cur].end();it++) {
            if (!visited[*it]) {
                queue.push_back(*it);
                visited[*it] = true;
            }
        }
    }
}
void GRAPH::DFSUtils(int v, int visited[]) {
    /*  mark the current as visited and then process it adjacent nodes. */
    visited[v] = true;
    cout << v << " ";
    for (auto it = adj[v].begin(); it != adj[v].end();it++) {
        if (!visited[*it]) {
            DFSUtils(*it, visited);
        }
    }
}
void GRAPH::DFS(int s) {
    int visited[V];
    for (int i=0; i< V; i++) {
        visited[i] = false;
    }

    DFSUtils(s, visited);
}
    
void GRAPH::DFS(void) {
    int visited[V];
    for (int i=0; i< V; i++) {
        visited[i] = false;
    }

    if (int i = 0; i < V; i++) {
        DFSUtils(i, visited);

    }
}


int main(void) {

    GRAPH g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

//    g.BFS(3);
    // g.BFS(1);
    g.DFS();

    return 0;


}
