#include "header/deep_first_search.h"
#include "header/breadth_first_search.h"

#define QTD_GRAPH 20

int main() {
    for (int i = 1; i <= QTD_GRAPH; i++) {
        std::string path = "IO\\Input\\";
        std::string name = "graph_" + std::to_string(i);

        path = path + name;
        graph *g = new graph(path);

        bread_fsearch *b = new bread_fsearch(g);
        b->start();
        b->print(name + "_bfs.gdf");

        deep_fsearch *d = new deep_fsearch(g);
        d->start(0,0);
        d->print(name + "_dfs.gdf");

        delete g; delete b; delete d;
    }
}