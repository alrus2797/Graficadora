#include "arbol.h"

#include <string>
#include <vector>
#include <sstream>


using namespace std;


double s_to_doa(string a)
{
    double t =0.0;
    stringstream ss;
    ss<<a;
    ss>>t;
    return t;
}



Arbol::Arbol()
{
    pri["sqt"]=5;
        pri["^"]=5;
        pri["*"]=4;
        pri["/"]=4;
        pri["%"]=4;
        pri["+"]=3;
        pri["-"]=3;
        pri[")"]=2;
        pri["("]=1;
        pri["log"]=6;
        pri["ln"]=6;
        pri["log2"]=6;

        pri["abs"]=6;
        pri["sen"]=6;
        pri["cos"]=6;
        pri["tg"]=6;
        pri["ctg"]=6;
        pri["sec"]=6;
        pri["csc"]=6;

}

Arbol::Arbol(Nodo_op* raiz)
{
    //ctor
    this->raiz=raiz;
}



Arbol::Arbol(vector<string> asd)
{

    this->exp=asd;
}

void Arbol::vec_assign(bool xoy,double valor)
{
    if(xoy)
    {
        for(auto i:this->xs)
        {
            i->set_valor(valor);
        }
    }
    else
        for(auto i: this->ys)
        {
            i->set_valor(valor);
        }
}

void Arbol::set_exp(vector<string> a)
{
    this->exp=a;
}


void Arbol::recorrer()
{
    vector<B_node*> pila;
    int i=0;
    string d;
    while (i<this->exp.size())
    {
        if (isdigit(this->exp[i][0])||(this->exp[i][0]=='-' && this->exp[i].size()>1 && isdigit(this->exp[i][1])))
        {
            //qDebug()<<"isdigit"<<QString::fromStdString(this->exp[i]);
            B_node* aux = new Nodo_num(s_to_doa(this->exp[i]));
            pila.push_back(aux);
        }


        else if (this->exp[i]=="x"|| this->exp[i]=="y"||this->exp[i]=="-x"|| this->exp[i]=="-y")
        {
         Nodo_num*temo=new Nodo_num;
            //qDebug()<<"llego a var"<<QString::fromStdString(this->exp[i])<<endl;
         if(this->exp[i][0]=='-')
         {
             B_node* neg=new Nodo_op(temo,new Nodo_num(-1),this->mapa->f_binaria["*"]);
             pila.push_back(neg);
         }
         else
            pila.push_back(temo);

         if(this->exp[i]=="x" || this->exp[i]=="-x")
         {
             this->xs.push_back(temo);
             this->varx=true;
         }
         else
         {
             this->ys.push_back(temo);
             this->vary=true;
         }
        }
        else
        {

            Nodo_op *sem;
            //qDebug()<<"llego"<<QString::fromStdString(this->exp[i])<<endl;
            int contaux=0;
            int contpar=0;
            //vector<B_node*>pilaux;
            //while(isdigit(this->exp[i][contaux])||this->exp[i][contaux]=="x"||this->exp[i][contaux])

            if(this->mapa->binouna(this->exp[i]))
            {
                B_node* der= pila.back();
                pila.pop_back();
                B_node* iz= pila.back();
                pila.pop_back();
                sem=new Nodo_op(iz,der,this->mapa->f_binaria[this->exp[i]]);
            }
            else
            {
                B_node* iz=pila.back();
                pila.pop_back();
                sem=new Nodo_op(iz,this->mapa->f_unaria[this->exp[i]]);
            //    cout<<"Por ahora: "<<sem->get_valor()<<endl;

            }
            pila.push_back(sem);
        }
        //cout<<"Ingreso: "<<der->valor<<"-"<<iz->valor<<endl;
        i=i+1;
    }
    this->raiz=new Nodo_op;
    this->raiz=pila.at(0);
}

bool Arbol::is3d()
{
    if (this->varx && this->vary)
        return true;
    else if(this->varx)
        return false;
}

vector<QVector<double> > Arbol::get_puntos(double x, double y)
{
    //this->recorrer();
    vector<QVector<double> > res;
    QVector<double> aux;
    if (this->varx)
    {
        if(!this->vary)
        {
            for (double i=x;i<=y;i=i+0.5)
            {
                for (auto j:this->xs)
                {
                    j->set_valor(i);
                }
                //this->vec_assign(true,i);
                aux.push_back(i);
                //qDebug()<<"res: "<<i<<this->ejec();
                aux.push_back(this->ejec());

                res.push_back(aux);
                aux.clear();
            }
        }

        else
        {
            for(double i=x;i<=y;i=i+0.2)
            {
                this->vec_assign(true,i);
                for(double j=x;j<=y;j=j+0.2)
                {
                    this->vec_assign(false,j);
                    aux.push_back(i);
                    aux.push_back(j);
                    aux.push_back(this->ejec());
                    res.push_back(aux);
                    aux.clear();
                }
            }
        }


    }
    else
    {
        double t=this->ejec();
        for (double i=x;i<y;i=i+1)
        {
            aux.push_back(i);
            aux.push_back(t);
            res.push_back(aux);
            aux.clear();
            //aux.push_back(i);
            //aux1.push_back(t);
        }
        //res.push_back(aux);
        //res.push_back(aux1);

    }
    this->varx=false;
    this->vary=false;
    return res;
}


double Arbol::ejec()
{
        return this->raiz->get_valor();
}
Arbol::~Arbol()
{
    //dtor
}
//x+4*x
//x4*x+
//senx
//x sen
//sensensenx+4
//x4+sensensen

