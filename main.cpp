#include "header/deep_first_search.h"
#include "header/breadth_first_search.h"

#define QTD_GRAPH 20

int main() {
    double R, D, V;
    for (int i = 1; i <= QTD_GRAPH; i++) {
        std::string path = "IO\\Input\\";
        std::string name = "graph_" + std::to_string(i);

        path = path + name;
        graph *g = new graph(path);

        deep_fsearch *d = new deep_fsearch(g);
        d->start(0,0);
        d->print(name + "_dfs.gdf");

        bread_fsearch *b = new bread_fsearch(g);
        b->start(0);
        b->print(name + "_bfs.gdf");

        b->eccentricity(&R, &D);
        b->average_dis(&V);
        std::cout << std::endl << "current: " << name << std::endl;
        std::cout << "radius = " << R << " ; diameter = " << D << " ; average distance = " << V << std::endl;

        delete g; delete b; delete d;
    }
}