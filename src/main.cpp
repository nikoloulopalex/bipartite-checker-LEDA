#include "LEDA/graph/graph.h"
#include "LEDA/graph/ugraph.h"
#include <LEDA/graph/graph_gen.h>
#include "LEDA/graph/graph_alg.h"
#include "LEDA/system/timer.h"
#include "bipartite.h"
#include "graph_gen.h"
#include <iostream>
using namespace leda;

int main()
{
    ugraph U;
    list<edge> L;
    list<node> A;
    list<node> B;
    list<node> V1;
    list<node> V2;
    list<node> V1L;
    list<node> V2L;
    timer my_bipar;
    timer led_bipar;

    // First family of graphs( Nested Squares)
    // First test (10000,19996)
    int n = 10000;
    int m = 19996;
    std::cout << "First Family of Graphs with " << n << "nodes"
              << "\n";
    U = nested_squares(n, m);
    my_bipar.start();
    my_bipar_checker(U, V1, V2) ? std::cout << "Mine Yes it is /n"
                                            << "\n"
                                : std::cout << " Mine No it is not"
                                            << "\n";
    my_bipar.stop();
    std::cout << "My time " << my_bipar.elapsed_time() << "\n";
    U.make_directed();
    led_bipar.start();
    Is_Bipartite(U, V1L, V2L) ? std::cout << "LEDA Yes it is " : std::cout << " LEDA No it is not";
    led_bipar.stop();
    std::cout << "Leda time " << led_bipar.elapsed_time() << "\n";
    std::cout << "/////////////////////////////////////////////////"
              << "\n";

    // Second family of graphs(Ring Graphs)
    //         First test(10001, 10001)
    n = 10001;
    m = 10001;
    std::cout
        << "Second Family of Graphs with " << n << "nodes"
        << "\n";
    V1.clear();
    V2.clear();
    V1L.clear();
    V2L.clear();
    U = ring_graph(n, m);
    my_bipar.start();
    my_bipar_checker(U, V1, V2) ? std::cout << "Mine Yes it is /n"
                                            << "\n"
                                : std::cout << " Mine No it is not"
                                            << "\n";
    my_bipar.stop();
    std::cout << "My time " << my_bipar.elapsed_time() << "\n";

    U.make_directed();
    led_bipar.start();
    Is_Bipartite(U, V1L, V2L) ? std::cout << "LEDA Yes it is " : std::cout << " LEDA No it is not";
    led_bipar.stop();
    std::cout << "Leda time " << led_bipar.elapsed_time() << "\n";
    std::cout << "/////////////////////////////////////////////////"
              << "\n";

    // // Third family of graphs( Synthetic Graphs)
    // // First test (500)
    n = 500;
    std::cout << "Third Family of Graphs with " << n << "nodes"
              << "\n";
    V1.clear();
    V2.clear();
    V1L.clear();
    V2L.clear();
    U = synth_graph(n);
    my_bipar.start();
    my_bipar_checker(U, V1, V2) ? std::cout << "Mine Yes it is /n"
                                            << "\n"
                                : std::cout << " Mine No it is not"
                                            << "\n";
    my_bipar.stop();
    std::cout << "My time " << my_bipar.elapsed_time() << "\n";
    U.make_directed();
    led_bipar.start();
    Is_Bipartite(U, V1L, V2L) ? std::cout << "LEDA Yes it is " : std::cout << " LEDA No it is not";
    led_bipar.stop();
    std::cout << "Leda time " << led_bipar.elapsed_time() << "\n";
    std::cout << "/////////////////////////////////////////////////"
              << "\n";
}