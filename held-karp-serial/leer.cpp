#include <iostream>
#include <fstream>
#include "leer.h"
#include <vector>
#include <utility> 
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;


vector <vector<double> >  leer(){
    vector <vector<double> > pesos;
    vector<pair<double,double> > nodos;
    int n;
    string x;
    ifstream fe("tc2c320s24cf0.txt");
    fe >> x;
    fe >> x;
    fe >> x;
    n = atoi(x.c_str());
    nodos = getnodos(fe,n);
    pair <double,double> nodoact = nodos.at(0);
    //cout << nodoact.first << endl;
    llenar(pesos,nodos);
    //cout << pesos.size() << endl;
    fe.close();
    return pesos;
}

void llenar(vector <vector<double> > &pesos, vector<pair<double,double> > &nodos){
    for(int i =0; i < nodos.size(); i++){
        vector <double> aux;
        pair <double,double> nodoact = nodos.at(i);
        for(int j = 0; j < nodos.size(); j++){
            pair <double,double> nododest = nodos.at(j);
            if (i == j){
                aux.push_back(32767);
            }else{
                double x = nododest.first - nodoact.first;
                double y = nododest.second - nodoact.second;
                double distancia = sqrt((x*x)+(y*y));
                aux.push_back(distancia);
            }
        }
        pesos.push_back(aux);
    }
}

vector<pair<double,double> > getnodos(ifstream &fe, int n){
    string lectura;
    vector <pair<double,double> > nodos;
    double x,y;
    fe >> lectura;
    for(int i =0; i < n; ++i){
        fe >> lectura;
        fe >> lectura;
        double x = atof(lectura.c_str());
        fe >> lectura;
        double y = atof(lectura.c_str());
        fe >> lectura;
        fe >> lectura;
        pair <double,double> aux;
        aux.first = x;
        aux.second = y;
        nodos.push_back(aux);
    }
    return nodos;
}
