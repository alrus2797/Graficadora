#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <map>
#include "QString"
#include "typedef.h"
#include <vector>
using namespace std;

class Mapa
{
    public:
        /**
         * @brief Mapa Constructor de la clase Mapa
         */
        Mapa();
        /**
         * @brief Valor Se encarga de obtener el string ingresado por el
         * label y lo analiza para retornar un resultado entero
         * @return
         */
        map < string , double(*)(double,double) > f_binaria;
        map < string, double(*)(double) > f_unaria;
        //bool is_operator(char);
        bool binouna(string);
        double res(double,double,string);
        int ingetfop(int,bool);
        int ingetop(int);
        void ejec();

        double Valor(string);


    protected:
    private:
        double fop;
        double sop;
        //string operador="+_-_*_/_^_sqrt_sen_cos_tg_ctg_sec_csc_abs";
        string operador="+-*/^sqrtsencostgctgseccscabs";
        string op;
        vector<char> exp;

};

#endif // MAPA_H
