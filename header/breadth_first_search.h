#ifndef _BREADTH_FSEARCH_H_
#define _BREADTH_FSEARCH_H_

#include <queue>
#include "search.h"
#include "graph.h"

class bread_fsearch : public search {
    private:
        int *level;        
        int *visited;
        std::queue<int> *fifo;

        void bsearch(int *time);
    public:
        bread_fsearch(graph *g);
        ~bread_fsearch();

        void start();
};

#endif