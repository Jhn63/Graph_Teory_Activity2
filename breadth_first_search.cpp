#include "header/breadth_first_search.h"

bread_fsearch::bread_fsearch(graph *g) : search(g) {
    this->level = new int[N];
    this->visited = new int[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    this->fifo = new std::queue<int>();
}

bread_fsearch::~bread_fsearch() {
    delete[] level;
    delete[] visited;
}

void bread_fsearch::start() {
    int time = 0;
    while (true) {
        int i;
        bool hasv = false;
        for (i = 0; i < N; i++) {
            if (visited[i] == 0) { hasv = true; break; }
        }

        if (hasv) {
            level[i] = 0;
            visited[i] = ++time;
            fifo->push(i);
            bsearch(&time);
        } else { break; }
    }
}

void bread_fsearch::bsearch(int *time) {
    while (!fifo->empty()) {
        int v = fifo->front();
        fifo->pop();

        std::list<int> *l = &gph->get_op_ngbhood(v);
        std::list<int>::iterator it = l->begin();
        while (it != l->end()) {

            if (visited[*it] == 0) {
                paint_edge(v, *it, BLUE);
                parent[*it] = v;
                level[*it] = level[v] +1;
                visited[*it] = ++*time;
                
                fifo->push(*it);
            }
            else if (level[*it] == level[v]) {
                if (parent[*it] == parent[v]) {
                    paint_edge(v, *it, RED);
                } else {
                    paint_edge(v, *it, YELLOW);
                }
            }
            else if (level[*it] == level[v]+1) {
                paint_edge(v, *it, GREEN);
            }
            ++it;
        }
    }
}
