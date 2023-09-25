#include "header/deep_first_search.h"

deep_fsearch::deep_fsearch(graph *g) : search(g) {
    this->pe = new int[N];
    this->ps = new int[N];
    for (int i = 0; i < N; i++) {
        pe[i] = 0;
        ps[i] = 0;
    }
    this->time = 0;
}

deep_fsearch::~deep_fsearch() {
    delete[] pe;
    delete[] ps;
}

void deep_fsearch::start(const int vertice) {
    time += 1;
    pe[vertice] = time; //tempo de entrada marcado
    
    std::list<int> *l = &gph->get_op_ngbhood(vertice);
    std::list<int>::iterator neighbor = l->begin();

    while (neighbor != l->end()) {

        if (pe[*neighbor] == 0) { //ainda não visitado
            paint_edge(vertice, *neighbor, BLUE);
            parent[*neighbor] = vertice;
            start(*neighbor);
        }   
        else if (ps[*neighbor] == 0 && *neighbor != parent[vertice]) {
            paint_edge(vertice, *neighbor, RED);
        }
        ++neighbor;
    }
    time += 1;
    ps[vertice] = time; //tempo de saida marcado
}
