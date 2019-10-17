#include "main.h"
#include <iostream>
#include "leer.h"
#include <fstream>
#include <vector>
#include <utility> 
#include <ctime>
#include <algorithm>
#include <limits>
#include <cstdint> 
using namespace std;

int main(){
    unsigned t0, t1;
    vector <vector<double> > grafo;
    grafo = leer();
    //imprimirgrafo(grafo);
    t0=clock();
    getanswer(grafo);
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << endl;
    return 0;
}

void getanswer(vector <vector<double> > grafo){
    int N = grafo.size();
    vector< vector<double> > best( 1<<(N-1), vector<double>( N, INT8_MAX ) );
    //#pragma omp parallel for
    for (int visited = 1; visited < (1<<(N-1)); ++visited) {
        #pragma omp simd
        for (int last = 0; last < (N-1); ++last) {
 
            // last visited vertex must be one of the visited vertices
            if (!(visited & 1<<last)) continue;
 
            // try all possibilities for the previous vertex,
            // pick the best among them
            if (visited == 1 << last) {
                // previous vertex must have been N-1
                best[visited][last] = grafo[N-1][last];
            } else {
                // previous vertex was one of the other ones in "visited"
                int prev_visited = visited ^ 1<<last;
                for (int prev = 0; prev < N-1; ++prev) {
                    if (!(prev_visited & 1<<prev)) continue;
                    best[visited][last] = min( 
                        best[visited][last], 
                        grafo[last][prev] + best[prev_visited][prev]
                    );
                }
            }
        }
    }
    double answer = INT8_MAX;
    for (int last=0; last<N-1; ++last) {
        answer = min( 
            answer,
            grafo[last][N-1] + best[ (1<<(N-1))-1 ][last]
        );
    }
    cout << answer << endl;
}


void imprimirgrafo(vector <vector<double> > grafo){
    int n = grafo.size();
    for(int i =0; i < n; i++){
        cout << "    "  << i  << "    " ;
    }
    cout << "\n" ;
    for(int i = 0; i < n; i++){
        vector <double> nodoact = grafo.at(i);
        for (int j = 0 ; j < n; j++){
            cout << "  " <<  nodoact.at(j);
        }
        cout << "\n" ;
    }
}