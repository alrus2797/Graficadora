#ifndef NODO_OP_H
#define NODO_OP_H
#include "b_node.h"
#include <iostream>
#include "mapa.h"
using namespace std;


class Nodo_op : public B_node
{
    public:
        Nodo_op();
        Nodo_op(B_node*, B_node*,double (*pfb)(double,double));
        Nodo_op(B_node*,double(*pfu)(double));
        //void set_valor(string);
        double get_valor();
    private:
        //Mapa *mapa;
        //string valor;
        B_node* izq;
        B_node* der;
        bool is_bin;
        double (*pfbin)(double,double);
        double(*pfun)(double);



};

#endif // NODO_OP_H
