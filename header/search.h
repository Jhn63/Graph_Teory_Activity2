#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <fstream>
#include "graph.h"

#define RED "255,0,0"
#define BLUE "0,0,255"
#define GREEN "0,255,0"
#define YELLOW "255,255,0"

class search {
    protected:
        int N;
        graph *gph;

        int *parent;
        std::string **edges;

        void paint_edge(int v, int w, const std::string color);
    public:
        search(graph *g);
        ~search();

        void print(std::string file_name);
    
};

#endif