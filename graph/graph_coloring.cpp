/*
 * =====================================================================================
 *
 *       Filename:  graph_coloring.cpp
 *
 *    Description:  Color a graph with no two adjacent node should get same color. 
 *    This is using greedy Algorithm. 
 *    https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
 *
 *
 *        Version:  1.0
 *        Created:  10/26/2018 11:34:02 PM
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

using namespace std;

class Graph {
    int V;
    list <int> *adj;
    public:
    Graph(int v) : V(v) {adj = new list <int>[v];}
    ~Graph() {delete [] adj;}
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void GreedyColoring();

};


void Graph::GreedyColoring(void) {
    /*  array to store color for all vetices */
    int result[V];
    /*  Assign first color to first node and mark rest of them as -1 for not assigned */
    result[0] = 0;

    for (int u=1; u<V; u++) {
        result[u] = -1;
    }
    /*  Available colors for holding temporary*/
    bool Available[V];
    /*  now assign color to each of the other vertices */
    for (int u =1; u < V; u++) {

        /*  initially mark all color as available  */

        for ( int c=0; c< V; c++) {
            Available[c] = true;
        }
        /*  for each of the adjacent mark the color as not available  */
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if (result[*it] != -1) {
                Available[result[*it]] = false;
            }
        }
        /*  now get the first available color and assign for u */
        for (int i=0; i < V; i++) {
            if (Available[i]) {
                result[u] = i;
                break;
            }
        }
        /*  Again mark all Colors as available */
    }
    for ( int u =0; u < V; u++) {
        cout << "color for " << u << " is " << result[u] << endl;
    }
}

int main(void) {
    Graph g1(6);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(2,5);
    g1.addEdge(3,4);
    g1.addEdge(3,5);
    g1.addEdge(4,5);
    g1.addEdge(3,1);
    g1.GreedyColoring();

    Graph g2(5); 
    g2.addEdge(0, 1); 
    g2.addEdge(0, 2); 
    g2.addEdge(1, 2); 
    g2.addEdge(1, 4); 
    g2.addEdge(2, 4); 
    g2.addEdge(4, 3);
    /*   */
    cout << " next graph " << endl;
    g1.GreedyColoring();
    return 1;

}


