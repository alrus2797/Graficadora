#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstring>
#include <math.h>
#include <stdlib.h>

#include "QString"
#include "typedef.h"
#include "funciones.h"

using namespace std;

class analizador
{
    public:
        analizador();
        void imprimir(vector<string>);
        string borrarE(string);
        void llenar(vector<string>,string);
        string sinPar(string);
        string solopar(string);
        bool SonPar(char,char);
        bool Parentesis(string);
        vector<string> post(string);
        bool esNum(string);
        bool esVar(string);
        vector<string> vecNumeros(vector<string>);
        vector<string> vecVariables(vector<string>);
        vector<string> vecSemFun(vector<string>); 
        string esPam(string);
        bool esFun(string);
        vector <string> Tokens (string);
        bool esFuncion(vector <string>);
        void Es(vector<string>);
        bool Sintaxis(string);
        vector<string> ClasiT(string,vector<string>);
        vector<string> ClasiO(string,vector<string>);
        vector<string> POST(vector<string>);
        vector<string> main(string);

        //Mapas
        map < string , double(*)(double,double) > f_binaria;
        map < string, double(*)(double) > f_unaria;
        map < string, int> prioridad ;

    private:
        string expresion;

};

#endif //ANALIZADOR_H
