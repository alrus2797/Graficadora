#include "nodo_op.h"
#include <QDebug>
Nodo_op::Nodo_op()
{

}

Nodo_op::Nodo_op(B_node *iz, B_node *de,double(*pfb)(double,double))
{
    this->izq=iz;
    this->der=de;
    this->is_bin=true;
    this->pfbin=pfb;
}

Nodo_op::Nodo_op(B_node *iz, double (*pfu)(double))
{
    this->izq=iz;
    this->is_bin=false;
    this->pfun=pfu;
}

double Nodo_op::get_valor()
{
    double iz=this->izq->get_valor();
    //qDebug()<<"llegoa get_valor";
    if (this->is_bin)
    {
        double de=this->der->get_valor();
        //qDebug()<<"rep bin: "<< this->pfbin(iz,de);

        return this->pfbin(iz,de);
    }
    else
    {
        //qDebug()<<"rep bin: "<< this->pfun(iz);
        return this->pfun(iz);
    }
}
