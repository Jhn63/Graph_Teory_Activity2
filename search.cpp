#include "header/search.h"

search::search(graph *g) {
    this->N = g->get_N();
    this->gph = g; 

    this->parent = new int[N];
    for (int i = 0; i < N; i++) {
        parent[i] = 0;
    }

    this->edges = new std::string*[N];
    for (int i = 0; i < N; i++) {
        this->edges[i] = new std::string[N];
    }
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            edges[k][l] = "";
        }   
    }
}

search::~search() {
    delete[] parent;
    for (int k = 0; k < N; k++) {
        delete[] edges[k];
    }
    delete[] edges;
}

void search::paint_edge(int v, int w, const std::string color) {
    (v < w) ? edges[v][w] = color : edges[w][v] = color;
}

void search::print(std::string file_name) {
    std::ofstream file("IO\\Output\\"+file_name);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo" << std::endl;
        exit(-1); 
    }

    file << "nodedef>name VARCHAR,label VARCHAR" << std::endl;
    for (int i = 0; i < N; i++) {
        file << i+1 << "," << i+1 << std::endl;
    }

    file << "edgedef>node1 VARCHAR,node2 VARCHAR,directed BOOLEAN,color VARCHAR" << std::endl;   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ( !edges[i][j].empty() ) {
                file << i+1 << "," << j+1 << ",false,";
                file << "'" << edges[i][j] << "'" << std::endl;
            }
        }       
    }
    file.close();
}