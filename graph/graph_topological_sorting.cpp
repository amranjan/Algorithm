/*
 * =====================================================================================
 *
 *       Filename:  graph_topological Sorting.cpp
 *
 *    Description:  Add topological Sorting of a DAC ( Directed Acyclic graph.
 *    in the case , for each edge (UV) vertex u comes before its adjacent vertex v. 
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

/*  
 *  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
 *  such that for every directed edge uv, vertex u comes before v in the ordering. 
 *  Topological Sorting for a graph is not possible if the graph is not a DAG.
 *  */
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>

using namespace std;


class GRAPH {
    int V; /*  number of vertices */

    /*  Array of pointers to the adjacency lists */
    /*  eg, Vertices are 0, 1,2,3,4,5 and adges are [0,3], [0,4], [1,2], [2,5], [2,4] , [3,5]. 
    [0]--> [3], [4];
    [1]--> [2];
    [2]--> [4],[5];
    [3]-->[5];
    */


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
    void DFS(void);
    void topologicalSortingUtils(int v, stack <int>  &s, int visited[]);
    void topologicalSorting(void);
    bool isCyclic(vector<bool> &visited, int v);
    bool isCyclic(void );
    //~GRAPH() { delete adj;}


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
        for (auto it = adj[cur].begin(); it != adj[cur].end();it++) {
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

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtils(i, visited);
        }

    }
}
/*  this utils first visits all of its adjacent vertices by walking through 
 *  its  adjacency list and then finally mark it visited */
void GRAPH::topologicalSortingUtils(int v, stack <int>  &s, int visited[]) {

    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if (!visited[*it]) {
            topologicalSortingUtils(*it, s, visited);
        }
    }
    s.push(v);
    visited[v] = true;
}
/*  Topological sorting  push all its adjacent vertices before pushing itself
 *  Finally it pops from the stack to arrange the vertices in topological sorting order */
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
/*  Check if previous node does not figure out  in the adjacency list of next nodes */
bool GRAPH::isCyclic(vector<bool> &visited, int v) {


    if (visited[v]) return true;
    visited[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(isCyclic(visited, *it)) {
            return true;
        }
    }
    visited[v] = false;
    return false;
}
bool GRAPH::isCyclic(void) {

    vector <bool> visited(V, false);
    for (int i =0; i <V; i++) {
        if (isCyclic(visited, i)) return true;
    }
    return false;
}

int main(void) {

    {
    GRAPH g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 3);


//    g.BFS(3);
    // g.BFS(1);
    cout << endl;
    cout << " Following is DFS \n";
    g.DFS();
    cout << endl;
    }
    GRAPH g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 2);
    g.addEdge(5, 2);


    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSorting();
    // Make it cyclic graph
    //g.addEdge(2, 0);
    if(g.isCyclic()) {
         
        cout << "cyclic graph";
    } else {
        cout << " non cyclic graph";

    }
    cout << endl;

    return 0;


}
