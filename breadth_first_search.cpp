#include "header/breadth_first_search.h"

bread_fsearch::bread_fsearch(graph *g) : search(g) {
    this->level = new int[N];
    this->visited = new int[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        level[i] = 0;
    }

    this->fifo = new std::queue<int>();
}

bread_fsearch::~bread_fsearch() {
    delete[] level;
    delete[] visited;
}

void bread_fsearch::start(const int vertice) {
    int time = 0;
    while (true) {
        int i = vertice;
        bool hasv = false;
        do { //verifica se tem vertice a ser visitado
            if (visited[i] == 0) { hasv = true; break; }
            i = (i+1) % N;
        } while (i != vertice);

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

            if (visited[*it] == 0) { //não foi visitado
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

void bread_fsearch::reset() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        parent[i] = 0;
        level[i] = 0;

        for (int j = 0; j < N; j++) {
           edges[i][j].clear();
        }
    }
}

void bread_fsearch::average_dis(double *average) {
    *average = 0;
    for (int i = 0; i < N; i++) {
        double accum = 0;

        this->reset();
        this->start(i);
        for (int k = 0; k < N; k++) {
            accum += level[k];
        }
        accum = accum / (N-1);

        *average += accum;
    }
    *average = *average / N;
}

void bread_fsearch::eccentricity(double *radius, double *diameter) {
    this->reset();
    this->start(0);
    *radius = *std::max_element(level, level + N);
    *diameter = *std::max_element(level, level + N);
    
    for (int i = 1; i < N; i++) {
        this->reset();
        this->start(i);
        double current_eccy = *std::max_element(level, level + N);
      
        if (*radius > current_eccy)   { *radius = current_eccy; }
        if (*diameter < current_eccy) { *diameter = current_eccy; }
    }
}