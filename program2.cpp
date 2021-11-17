/**
 *  @autores: joel, misael, edgar
 *  @descripcion: Programa para analizar y comparar el costo computacional de la función de busqueda en fuerza bruta y kd-tree.
 *  @version: 1.0
*/

#include <bits/stdc++.h>

#include "csv-parser/csv.h"
#include "bruteforce.hpp"
#include "kdtree.hpp"

using namespace std;

const int ms = 1000000;

void searchBruteforce(){
    ofstream outInsert1;
    outInsert1.open("./docs/outSearchFB.txt");
    int max_cant = 11;

    int cant[11] = {100, 500, 1000, 5000, 10000, 20000, 100000, 200000, 350000, 500000, 1000000};
    vector<string> nameFiles(max_cant);
    for(int i=0; i<max_cant; i++) nameFiles[i] = "data/test" + to_string(cant[i]) + ".csv";

    vector<vector<long double>> points(ms);

    for(int i=0; i<max_cant; i++){
        
        io::CSVReader<4> in(nameFiles[i]);
        in.read_header(io::ignore_extra_column,"", "x", "y", "z");
        int pos; long double x, y, z;
        while(in.read_row(pos, x, y, z)){
            points[pos] = {x, y, z};
        }

        Bruteforce<long double> bf(cant[i], 3);

        for(int j=0; j<cant[i]; j++){
            bf.insert(points[j]);
        }
        
        //pick some elements to search
        int randPos = rand() % cant[i];
        vector<long double> query = points[randPos];

        //start timer here
        auto start = chrono::high_resolution_clock::now();
        bf.search(query);
        //end timer here
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        outInsert1 << cant[i] << " " << duration.count() << endl;

    }

    outInsert1.close();
}


void searchKdTree(){
    ofstream outInsert2;
    outInsert2.open("./docs/outSearchKD.txt");
    int max_cant = 11;

    int cant[11] = {100, 500, 1000, 5000, 10000, 20000, 100000, 200000, 350000, 500000, 1000000};
    vector<string> nameFiles(max_cant);
    for(int i=0; i<max_cant; i++) nameFiles[i] = "data/test" + to_string(cant[i]) + ".csv";


    for(int i=0; i<max_cant; i++){
        array<long double, 3> *points = new array<long double, 3>[cant[i]];

        io::CSVReader<4> in(nameFiles[i]);
        in.read_header(io::ignore_extra_column,"", "x", "y", "z");
        int pos; long double x, y, z;
        while(in.read_row(pos, x, y, z)){
            points[pos] = {x,y,z};
        }

        KDTree<long double> kd;
        
        for(int j=0; j<cant[i]; j++){
            kd.insert(points[j]);
        }
        
        //pick some elements to search
        int randPos = rand() % cant[i];
        array<long double,3> query = points[randPos];

        //start timer here
        auto start = chrono::high_resolution_clock::now();
        kd.search(query);
        //end timer here
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        outInsert2 << cant[i] << " " << duration.count() << endl;

        delete[] points;

    }

    outInsert2.close();
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    cout << "Searching force brute ...\n";
    searchBruteforce();

    cout << "Searching kd-tree ...\n";
    searchKdTree();
    return 0;
}
