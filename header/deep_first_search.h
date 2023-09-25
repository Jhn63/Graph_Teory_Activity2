#ifndef _DEEP_FSEARCH_H_
#define _DEEP_FSEARCH_H_

#include "search.h"
#include "graph.h"

class deep_fsearch : public search {
    private :
        int *pe;    // profundidade de entradadas
        int *ps;    // profundidade de saida
        int time;
    public :
        deep_fsearch(graph *g);
        ~deep_fsearch();

        void start(const int vertice);
};

#endif