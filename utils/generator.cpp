#include <bits/stdc++.h>
#include "../csv-parser/csv.h"

using namespace std;

void generatePointsFile(){
    int cant[11] = {100, 500, 1000, 5000, 10000, 20000, 100000, 200000, 350000, 500000, 1000000};
    vector<string> inNameFiles(11);
    vector<string> outNameFiles(11);

    for(int i = 0; i < 11; i++){
        
        string inName = "../data/test" + to_string(cant[i]) + ".csv";
        string outName = "../data/data" + to_string(cant[i]) + ".pts";

        fstream outFile;
        outFile.open(outName, ios::out);

        io::CSVReader<4> in(inName);
        in.read_header(io::ignore_extra_column,"", "x", "y", "z");
        int pos; long double x, y, z;
        while(in.read_row(pos, x, y, z)){
            outFile << setprecision(12) <<  x << "\t" << y << "\t" << z << endl;
        }
        outFile.close();
    }
}

void generateQueryPoints(){
    int cant[11] = {100, 500, 1000, 5000, 10000, 20000, 100000, 200000, 350000, 500000, 1000000};
    vector<string> inNameFiles(11);
    vector<string> outNameFiles(11);

    for(int i = 0; i < 11; i++){
        
        int cantQueries = 20;

        string inName = "../data/test" + to_string(cant[i]) + ".csv";
        string outName = "../data/query" + to_string(cant[i]) + ".pts";

        fstream outFile;
        outFile.open(outName, ios::out);

        io::CSVReader<4> in(inName);
        in.read_header(io::ignore_extra_column,"", "x", "y", "z");
        int pos; long double x, y, z;
        while(in.read_row(pos, x, y, z)){
            if (cantQueries == 0) break;
            if (rand() % 4 <= 3)
                outFile << setprecision(12) <<  x << "\t" << y << "\t" << z << endl;
            cantQueries--;
        }
        outFile.close();
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    cout << "Generating points file ...\n";
    //generatePointsFile();
    cout << "Successfully generated ...\n";

    cout << "Generating query points file ...\n";
    generateQueryPoints();
    cout << "Successfully query generated ...\n";

    return 0;
}
