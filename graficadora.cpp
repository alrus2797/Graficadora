        #include "graficadora.h"
    #include "ui_graficadora.h"

    #include <vector>
    #include <iostream>
    #include <QDebug>
    #include "arbol.h"


    using namespace std;

bool encontrar(map<string,int> m,string b)
{
    auto i= m.find(b);
    if (i!=m.end())
        return true;
    return false;
}
template <class T>
void imp(vector<T> m,string n)
{
    cout<<n<<": { ";
    for(auto i:m)
    {
        cout<<i<<",";
    }
    cout<<" }"<<endl;
}



vector<string>separar(string pal,map<string,int> pri)
{
    int i=0;
    vector<string>res;
    while (pal[i])
    {
        if(isdigit(pal[i]))
        {
            int j=i;
            string aux="";
            while (isdigit(pal[j]))
            {
                aux=aux+pal[j];
                j++;
            }
            res.push_back(aux);
            i=j;
        }
        else
        {
            int k=i;
            string func="";
            bool op=true;
            if (pal[k]=='-' && (pal[k+1]=='x' ||pal[k+1]=='y'))
            {
                func="-";
                k++;
            }

            while (isalpha(pal[k]))
            {
                if (op)
                    op=false;
                func=func+pal[k];
                k++;
            }
            if (op)
            {
                func=func+pal[k];
                k++;
            }
            cout<<"funcion: "<<func<<endl;
            if (encontrar(pri,func)|| func=="x" || func=="y" || func=="-x" || func=="-y" )
            {
                res.push_back(func);
            }
            else if (func!=" ")
                res.push_back("error");
            i=k;
        }
    }
    return res;
}




vector<string> post(vector<string> exp,map<string,int> pri)
{
    vector<string>aux;
    vector<string>res;
    int i=0;
    while(i<exp.size())
    {
        if (pri[exp[i]]==1)
            aux.push_back(exp[i]);
        else if(pri[exp[i]]==4 || pri[exp[i]]==3 || pri[exp[i]]==6 ||pri[exp[i]]==5)
        {
            //cout<<"entro: "<<exp[i]<<endl;
            while(pri[aux.back()]>=pri[exp[i]] )
            {
                res.push_back(aux.back());
                aux.pop_back();
            }
            aux.push_back(exp[i]);
        }
        else if (pri[exp[i]]==2)
        {
            int j=aux.size()-1;
            while(aux.back()!="(")
            {
                res.push_back(aux.back());
                aux.pop_back();
                j--;
            }
            aux.pop_back();

            if (aux.size()>3)
            {
              //  cout<<"intento: "<<aux.back()<<endl;
                if(encontrar(pri,exp[j-1]))
                {
                    res.push_back(aux.back());
                    aux.pop_back();
                }
            }
        }
        else
        {
            res.push_back(exp[i]);
        }
        i++;
    }
    return res;
}




    Graficadora::Graficadora(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Graficadora)
    {

        ui->setupUi(this);

            this->model->setHorizontalHeaderItem(0,new QStandardItem(QString("X")));
            this->model->setHorizontalHeaderItem(1,new QStandardItem(QString("Y")));
            this->model->setHorizontalHeaderItem(2,new QStandardItem(QString("Z")));


            double origen[3]= {-3.0,9.0,0.0};
            double p0[3]= {-2.0,4.0,0.0};
            double p1[3]= {-1.0,1.0,0.0};
            double p2[3]= {-0.0,0.0,0.0};
            double p3[3]= {1.0,1.0,0.0};
            double p4[3]= {2.0,4.0,0.0};
            double p5[3]= {3.0,9.0,0.0};

            double p6[3]= {-0.5,0.25,0.0};
            double p7[3]= {0.0,0.0,0.0};
            double p8[3]= {0.5,0.25,0.0};
            double p9[3]= {1.0,1.0,0.0};
            double p10[3]= {1.5,2.25,0.0};
            double p11[3]= {2.0,4.0,0.0};
            double p12[3]= {2.5,6.25,0.0};


                prioridad["sqrt"]=5;
                prioridad["^"]=5;
                prioridad["*"]=4;
                prioridad["/"]=4;
                prioridad["%"]=4;
                prioridad["+"]=3;
                prioridad["-"]=3;
                prioridad[")"]=2;
                prioridad["("]=1;
                prioridad["log"]=6;
                prioridad["ln"]=6;
                prioridad["log2"]=6;

                prioridad["abs"]=6;
                prioridad["sen"]=6;
                prioridad["cos"]=6;
                prioridad["tg"]=6;
                prioridad["ctg"]=6;
                prioridad["sec"]=6;
                prioridad["csc"]=6;

            //double p13[3]= {3.0,9.0,0.0};
            //double p14[3]= {3.5,12.25,0.0};
           // double p15[3]= {4.0,16.0,0.0};

            /*points ->InsertNextPoint(origen);
            points ->InsertNextPoint(origen);
            points ->InsertNextPoint(p0);
            points ->InsertNextPoint(p0);
            points ->InsertNextPoint(p1);
            points ->InsertNextPoint(p1);
            points ->InsertNextPoint(p2);
            points ->InsertNextPoint(p2);
            points ->InsertNextPoint(p3);
            points ->InsertNextPoint(p3);
            points ->InsertNextPoint(p4);
            points ->InsertNextPoint(p4);
            points ->InsertNextPoint(p5);
            points ->InsertNextPoint(p5);*/

    //        points ->InsertNextPoint(p13);
    //        points ->InsertNextPoint(p14);
          //  points ->InsertNextPoint(p15);
           //

        /*
            double origen[3]= {-4.0,-4.0,-8.0};
            double p0[3]= {-4.0,-3.0,-7.0};
            double p1[3]= {-4.0,-2.0,-6.0};
            double p2[3]= {-4.0,-1.0,-5.0};
            double p3[3]= {-4.0,0.0,-4.0};
            double p4[3]= {-4.0,1.0,-3.0};
            double p5[3]= {-4.0,2.0,-2.0};
            double p6[3]= {-4.0,3.0,-1.0};
            double p7[3]= {-4.0,4.0,0.0};

            points ->InsertNextPoint(origen);
    //        points ->InsertNextPoint(origen);
            points ->InsertNextPoint(p0);
    //        points ->InsertNextPoint(p0);
            points ->InsertNextPoint(p1);
    //        points ->InsertNextPoint(p1);
            points ->InsertNextPoint(p2);
    //        points ->InsertNextPoint(p2);
            points ->InsertNextPoint(p3);
    //        points ->InsertNextPoint(p3);
            points ->InsertNextPoint(p4);
    //        points ->InsertNextPoint(p4);
            points ->InsertNextPoint(p5);
    //        points ->InsertNextPoint(p5);
            points ->InsertNextPoint(p6);
    //        points ->InsertNextPoint(p6);
            points ->InsertNextPoint(p7);
    //        points ->InsertNextPoint(p7);
            */


            //Cuando empieza en 1 solo se ingresa una vez
            //Cuando empieza en 2 se agregan dos veces

            //structuredGrid->SetDimensions(1,9,9);       // y=numero de x tabuladas, z = 1  // 9*9*1 = 81
            //structuredGrid->SetDimensions(2,7,1);       // y=numero de x tabuladas, z = 1  // 9*9*1 = 81
                                        //2,4,1)        //2*4*1  = 8




            //structuredGrid->SetPoints(points);


               geometryFilter->SetInputData(this->structuredGrid);
               geometryFilter->Update();

                mapper2->SetInputConnection(geometryFilter->GetOutputPort());

                actor2->GetProperty()->SetPointSize(4);
                actor2->GetProperty()->SetColor(255,0,0);



                actor2->GetProperty()->SetColor(0,255,0);
                actor2->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0); //(R,G,B)
                actor2->GetProperty()->EdgeVisibilityOn();  //Para que se vea la interseccion, si es que es dim:1 se ve plano

                actor2->SetMapper(mapper2);




                outlineFilter->SetInputData(this->structuredGrid);
                outlineFilter->Update();

                mapper->SetInputConnection(outlineFilter->GetOutputPort());

    //            actor->GetProperty()->SetColor(0,255,0);
    //            actor->GetProperty()->SetEdgeColor(0.0, 0.0, 1.0); //(R,G,B)
                actor1->SetMapper(mapper);


               transform->Translate(0.0, 0.0, 0.0);

               this->axess->SetUserTransform(transform);
               this->axess->SetTotalLength(5,5,5);

            // KAT

            renderWindow->AddRenderer(renderer);

            //TAMAÑO DE LOS EJES X Y Z

            axes->SetTotalLength(10.0,10.0,10.0);
            axes->SetConeRadius(0.1);

            //axes->SetUserTransform(transform);
            renderer->AddActor(axes);
            renderer->AddActor(actor);
            renderer->AddActor(actor2);


            renderer->SetBackground(.1, .1, .2);

            this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    }

    Graficadora::~Graficadora()
    {
        delete ui;
    }

    void Graficadora::on_Boton_clicked()
    {
        QString texto=ui->Input->text();
        string f=texto.toStdString();
        //vector<string> res=this->expresion->main(f);

        //imp(res,"Resultado");

        vector<string> b=separar(f,this->prioridad);
        imp(b,"separado: ");
        auto pri=b.begin();
        b.insert(pri,"(");
        b.push_back(")");
        qDebug()<<"se separo";
        vector<string> c=post(b,this->prioridad);

        imp(b,"post");


        this->arbol->set_exp(c);

        qDebug()<<"exp:"<<texto;
        this->arbol->recorrer();
        qDebug()<<"3d:"<<this->arbol->is3d();
        if(!this->arbol->is3d())
        {

            vector<QVector<double> > puntos=this->arbol->get_puntos(-10,10);
            for (auto i: puntos){
                points->InsertNextPoint(i[0],i[1],0.0);
                points->InsertNextPoint(i[0],i[1],0.0);
                //qDebug()<<"{"<<i[0]<<","<<i[1]<<","<<i[2]<<"}"<<endl;
            }
            structuredGrid->SetDimensions(2,puntos.size(),1);
            structuredGrid->SetPoints(points);
            geometryFilter->SetInputData(this->structuredGrid);
            geometryFilter->Update();
            mapper2->SetInputConnection(geometryFilter->GetOutputPort());
            actor2->SetMapper(mapper2);
            outlineFilter->SetInputData(this->structuredGrid);
            outlineFilter->Update();
        }
        else
        {

            vector<QVector<double> > puntos=this->arbol->get_puntos(-10,10);
            for (auto i: puntos){
                points->InsertNextPoint(i[0],i[1],i[2]);
                //points->InsertNextPoint(i[0],i[1],i[2]);
                //qDebug()<<"{"<<i[0]<<","<<i[1]<<","<<i[2]<<"}"<<endl;

            }

            structuredGrid->SetDimensions(1,pow(puntos.size(),1.0/2),pow(puntos.size(),1.0/2));
            structuredGrid->SetPoints(points);
            geometryFilter->SetInputData(this->structuredGrid);
            geometryFilter->Update();
            mapper2->SetInputConnection(geometryFilter->GetOutputPort());
            actor2->SetMapper(mapper2);
            outlineFilter->SetInputData(this->structuredGrid);
            outlineFilter->Update();

        }




        //ui->Output->setText(texto);



        //A->main(ecuacion);
        //A->imprimir(A->main(ecuacion));

    }
