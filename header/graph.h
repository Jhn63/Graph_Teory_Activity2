#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <string>
#include <fstream>
#include <iostream>

class graph {
    private:
        int N; //number of vertices
        bool **matrix;
        std::list<int> **list;
    
        void load_data(const std::string path);
        
    public:
        graph(const std::string path);
        ~graph();

        int get_N();
        std::list<int>& get_op_ngbhood(int vertice);

        void print_v2();
        void print_v1();
};

#endif