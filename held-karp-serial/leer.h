#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <utility> 
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;


vector <vector<double> >  leer(int n_nodes);
vector<pair<double,double> > getnodos(ifstream &fe, int n);
void llenar(vector <vector<double> > &pesos, vector<pair<double,double> > &nodos);