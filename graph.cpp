#include "header/graph.h"

graph::graph(const std::string path) {
    this->load_data(path);
}

graph::~graph() {
    for (int k = 0; k < N; k++) {
        delete list[k];
    }
    delete[] list;

    for (int k = 0; k < N; k++) {
        delete[] matrix[k];
    }
    delete[] matrix;
}

void graph::load_data(const std::string path) {
    std::ifstream input;
    input.open(path);
    if (!input.is_open()) {
        std::cout << "file not open";
        exit(-1);
    }
    
    std::string str;
    std::getline(input, str);
    this->N = std::stoi(str);

    this->matrix = new bool*[N];
    for (int i = 0; i < N; i++) {
        this->matrix[i] = new bool[N]; 
    }

    char data;
    int i = 0, j = 0;
    while (input.get(data)) {

        if (data == '1') {

            this->matrix[i][j] = true;
            j = (j+1) % N;
            if (j == 0) {
                i++;
            }
        }
        if (data == '0') {

            this->matrix[i][j] = false;
            j = (j+1) % N;
            if (j == 0) {
                i++;
            }
        }
    }
    input.close();

    this->list = new std::list<int>*[N];
    for (int k = 0; k < N; k++) {
        this->list[k] = new std::list<int>();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (matrix[i][j] == true) {
                list[i]->push_back(j);
            }

        }
    }
}

int graph::get_N() {
    return N;
}

std::list<int>& graph::get_op_ngbhood(int vertice) {
    return *list[vertice];
}

void graph::print_v1() {
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void graph::print_v2() {
    std::list<int>::iterator it;
    for (int i = 0; i < N; i++) {

        it = list[i]->begin();
        std::cout << "[" << i << "] ";
        while (it != list[i]->end()) {
            std::cout << *it << "-> ";
            ++it;
        }
        std::cout << std::endl;
    }
}
