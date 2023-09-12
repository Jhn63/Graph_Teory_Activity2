#ifndef _DEEP_FSEARCH_H_
#define _DEEP_FSEARCH_H_

#include "search.h"
#include "graph.h"

class deep_fsearch : public search {
    private :
        int *pe;    // profundidade de entradada
        int *ps;    // profundidade de saida
        
    public :
        deep_fsearch(graph *g);
        ~deep_fsearch();

        void start(int vertice, int time);
};

#endif