#include "LEDA/graph/graph.h"
#include <LEDA/graph/graph_gen.h>
#include "LEDA/graph/graph_alg.h"
#include "LEDA/system/timer.h"
#include "bipartite.h"
#include <iostream>
#include <queue>
unsigned int counter = 1;
using namespace leda;

// A struct to keep information about nodes
struct NodeInfo
{
    bool visited;
    unsigned int arrival;
    string color;
};

// BFS algorithm  with coloring implementation for nodes
list<node> my_BFS(const graph &G, node s, node_array<NodeInfo> &info, node_array<int> &dist, node_array<edge> &pred)
{
    // info for 1st node
    info[s].visited = true;
    info[s].color = "green";
    info[s].arrival = counter;
    dist[s] = 0;
    node v;
    edge e;
    // the list used for the route that BFS followed
    list<node> node_list;
    // The queue used for BFS
    queue<node> q;
    q.push(s);
    node_list.push(s);
    // Run while there are vertices
    while (!q.empty())
    {
        node u = q.pop();
        forall_adj_edges(e, u)
        {
            // Node v is the node connected to node u by edge e
            v = G.opposite(e, u);
            if (!info[v].visited)
            {
                info[v].visited = true;
                info[v].arrival = counter++;
                dist[v] = dist[u] + 1;
                // assign previous edge to array
                pred[v] = e;
                // color nodes accoring to the distance from s
                info[v].color = (dist[v] % 2 == 0) ? "green" : "blue";
                // push node to queue for later examination about adj edges and to node list for the route BFS followed
                q.append(v);
                node_list.push(v);
            }
        }
    }
    return node_list;
}

bool my_bipar_checker(const graph &G, list<node> &V1, list<node> &V2)
{
    // node array used for node informatione such as color
    node_array<NodeInfo> info(G);
    // node array used for distance information from source node
    node_array<int> dist(G);
    // node array used for edge predecessor
    node_array<edge> pred(G);
    node v;
    node s = G.first_node();

    // run BFS algorithm and color nodes
    list<node> BFS_nodes = my_BFS(G, s, info, dist, pred);
    edge e;
    forall_edges(e, G)
    {

        node source = G.source(e);
        node target = G.target(e);
        if (info[target].color == info[source].color)
        {
            V1.clear();
            V2.clear();
            V1.push(target);
            V1.push(source);
            node pred_target = G.opposite(pred[target], target);
            node pred_source = G.opposite(pred[source], source);
            // run BFS tree until loop is found and push the nodes of the loop in list V1
            while (pred_target != pred_source)
            {

                V1.push(pred_target);
                V1.push(pred_source);
                pred_target = G.opposite(pred[pred_target], pred_target);
                pred_source = G.opposite(pred[pred_source], pred_source);
            }
            if (pred_target == pred_source)
                V1.push(pred_target);
            return false;
        }
        // push nodes to lists V1 , V2 according to color
        (info[source].color == "green") ? V1.push(source) : V2.push(source);
    }

    // If we reach here the Graph is Bipartite
    return true;
}
