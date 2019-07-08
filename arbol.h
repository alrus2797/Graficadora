#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <vector>
#include "nodo_op.h"
#include "nodo_num.h"
#include <QVector>
#include <QDebug>
using namespace std;

class Arbol
{
    public:
        Arbol();
        Arbol(Nodo_op*);
        Arbol(vector<string>);
        void set_exp(vector<string>);
        void set_exps(string);
        void recorrer();
        //vector<vector<double> > get_puntos(double=0,double=10);
        vector<QVector<double> > get_puntos(double=0,double=10);
        map<string,int> pri;
        double ejec();
        bool is3d();
        void vec_assign(bool,double);
        virtual ~Arbol();
    protected:
    private:
        bool varx=false;
        bool vary=false;
        vector<Nodo_num*> xs;
        vector<Nodo_num*> ys;
        vector<string> exp;
        B_node *raiz;
        Mapa* mapa=new Mapa;
};

#endif // ARBOL_H
