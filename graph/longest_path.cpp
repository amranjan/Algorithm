/*
 * =====================================================================================
 *
 *       Filename:  shortest_path.cpp
 *
 *    Description:  longest Path between any pair of vertices
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
#include <stack>
#include <limits.h>
#define INF INT_MAX

using namespace std;


typedef struct AdjListNode {
    int v;
    int weight;
        AdjListNode(int _v, int _w) {v = _v; weight = _w;}
} AdjListNode;

class GRAPH {
    int V;

    /*  Array of pointers to the adjacency lists */
    list <AdjListNode> *adj;
    public:
    GRAPH(int v) {
        V = v;
        adj = new list<AdjListNode>[v];
    };
    void addEdge(int u, int v, int weight);
    void topologicalSortingUtils(int v, stack <int>  &s, int visited[]);
    void topologicalSorting(void);
    void shortestPath(int s);


};


void GRAPH::addEdge (int u, int v, int w) {
    AdjListNode edge(v,w);
    adj[u].push_back(edge); // Add w in the list of v's Edge
}

void GRAPH::topologicalSortingUtils(int v, stack <int>  &s, int visited[]) {

    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if (!visited[it->v]) {
            topologicalSortingUtils(it->v, s, visited);
        }
    }
    s.push(v);
    visited[v] = true;
}
void GRAPH::topologicalSorting(void) {
    int visited[V];
    stack <int> s;
    for ( int i =0;i< V;i++) {
        visited[i] = false;
    }
    for (int i=0; i< V; i++) {
        if (!visited[i]) {
            topologicalSortingUtils(i, s, visited);
        }
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
int min(int v, int u) { return (( v < u) ? v : u); }
void GRAPH::shortestPath(int s) {
    /*  init shortest path array for each vertex */
    /*   */
    /*  Arrange all vertex in topological order  */
    /*  For each vertices in topological order, calculate the shortest path 
     *  for each adjacent vertex v of u 
     *  shortestPath(v) = min(shortestPath(v), shortestPath(u)+weight(u,v) */

    int visited[V];
    int shortest[V];
    stack <int> Stack;
    for ( int i =0;i< V;i++) {
        visited[i] = false;
    }
    for (int i=0; i< V; i++) {
        if (!visited[i]) {
            topologicalSortingUtils(i, Stack, visited);
        }
    }
    for ( int i = 0; i< V; i++) {
        shortest[i] = INF;
    }
    shortest[s] = 0;

    while (!Stack.empty()) {
        int cur = Stack.top();
        Stack.pop();
        if (shortest[cur] == INF) {
            continue;
        }
        for (auto it = adj[cur].begin(); it != adj[cur].end();it++) {
            if (shortest[it->v] > (it->weight +  shortest[cur])) {
                shortest[it->v] = shortest[cur] + it->weight;
            }
        }
    }
    for (int i=0; i<V;i++) {
        cout <<" shortest path for " << i << " " << shortest[i] << endl;
    }
}

int main(void) {

     // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    GRAPH g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<" n";
    g.shortestPath(s);


    cout << endl;
    cout << endl;

    return 0;


}
