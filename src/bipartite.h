#ifndef BIPARTITE_H // To make sure you don't declare the function more than once by including the header multiple times.
#define BIPARTITE_H
#include "LEDA/graph/graph.h"
#include <iostream>
using namespace leda;

bool my_bipar_checker(const graph &G, list<node> &V1, list<node> &V2);

#endif