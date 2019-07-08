#ifndef NODO_NUM_H
#define NODO_NUM_H
#include "b_node.h"

class Nodo_num : public B_node
{
    public:
        Nodo_num();

        Nodo_num(double);

        void set_valor(double);
        double get_valor();
    private:
        double valor;


};

#endif // NODO_NUM_H
