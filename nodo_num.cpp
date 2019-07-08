#include "nodo_num.h"

Nodo_num::Nodo_num()
{

}

Nodo_num::Nodo_num(double a)
{
    this->valor=a;
}

void Nodo_num::set_valor(double a)
{
    this->valor=a;
}
double Nodo_num::get_valor()
{
    return this->valor;
}
