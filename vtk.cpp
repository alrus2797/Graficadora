#include "vtk.h"

vtk::vtk()
{

}

Graficadora::Graficadora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graficadora)

{

        this->model->setHorizontalHeaderItem(0,new QStandardItem(QString("X")));
        this->model->setHorizontalHeaderItem(1,new QStandardItem(QString("Y")));
        this->model->setHorizontalHeaderItem(2,new QStandardItem(QString("Z")));

        double origen[3]= {-4.0,-4.0,-8.0};
        double p0[3]= {-4.0,-3.0,-7.0};
        double p1[3]= {-4.0,-2.0,-6.0};
        double p2[3]= {-4.0,-1.0,-5.0};
        double p3[3]= {-4.0,0.0,-4.0};
        double p4[3]= {-4.0,1.0,-3.0};
        double p5[3]= {-4.0,2.0,-2.0};
        double p6[3]= {-4.0,3.0,-1.0};
        double p7[3]= {-4.0,4.0,0.0};

        double p8[3]= {-3.0,-4.0,-7.0};
        double p9[3]= {-3.0,-3.0,-6.0};
        double p10[3]= {-3.0,-2.0,-5.0};
        double p11[3]= {-3.0,-1.0,-4.0};
        double p12[3]= {-3.0,0.0,-3.0};
        double p13[3]= {-3.0,1.0,-2.0};
        double p14[3]= {-3.0,2.0,-1.0};
        double p15[3]= {-3.0,3.0,0.0};
        double p16[3]= {-3.0,4.0,1.0};

        double p17[3]= {-2.0,-4.0,-6.0};
        double p18[3]= {-2.0,-3.0,-5.0};
        double p19[3]= {-2.0,-2.0,-4.0};
        double p20[3]= {-2.0,-1.0,-3.0};
        double p21[3]= {-2.0,0.0,-2.0};
        double p22[3]= {-2.0,1.0,-1.0};
        double p23[3]= {-2.0,2.0,0.0};
        double p24[3]= {-2.0,3.0,1.0};
        double p25[3]= {-2.0,4.0,2.0};

        double p26[3]= {-1.0,-4.0,-5.0};
        double p27[3]= {-1.0,-3.0,-4.0};
        double p28[3]= {-1.0,-2.0,-3.0};
        double p29[3]= {-1.0,-1.0,-2.0};
        double p30[3]= {-1.0,0.0,-1.0};
        double p31[3]= {-1.0,1.0,0.0};
        double p32[3]= {-1.0,2.0,1.0};
        double p33[3]= {-1.0,3.0,2.0};
        double p34[3]= {-1.0,4.0,3.0};

        double p35[3]= {0.0,-4.0,-4.0};
        double p36[3]= {0.0,-3.0,-3.0};
        double p37[3]= {0.0,-2.0,-2.0};
        double p38[3]= {0.0,-1.0,-1.0};
        double p39[3]= {0.0,0.0,0.0};
        double p40[3]= {0.0,1.0,1.0};
        double p41[3]= {0.0,2.0,2.0};
        double p42[3]= {0.0,3.0,3.0};
        double p43[3]= {0.0,4.0,4.0};

        double p44[3]= {1.0,-4.0,-3.0};
        double p45[3]= {1.0,-3.0,-2.0};
        double p46[3]= {1.0,-2.0,-1.0};
        double p47[3]= {1.0,-1.0,0.0};
        double p48[3]= {1.0,0.0,1.0};
        double p49[3]= {1.0,1.0,2.0};
        double p50[3]= {1.0,2.0,3.0};
        double p51[3]= {1.0,3.0,4.0};
        double p52[3]= {1.0,4.0,5.0};

        double p53[3]= {2.0,-4.0,-2.0};
        double p54[3]= {2.0,-3.0,-1.0};
        double p55[3]= {2.0,-2.0,0.0};
        double p56[3]= {2.0,-1.0,1.0};
        double p57[3]= {2.0,0.0,2.0};
        double p58[3]= {2.0,1.0,3.0};
        double p59[3]= {2.0,2.0,4.0};
        double p60[3]= {2.0,3.0,5.0};
        double p61[3]= {2.0,4.0,6.0};

        double p62[3]= {3.0,-4.0,-1.0};
        double p63[3]= {3.0,-3.0,0.0};
        double p64[3]= {3.0,-2.0,1.0};
        double p65[3]= {3.0,-1.0,2.0};
        double p66[3]= {3.0,0.0,3.0};
        double p67[3]= {3.0,1.0,4.0};
        double p68[3]= {3.0,2.0,5.0};
        double p69[3]= {3.0,3.0,6.0};
        double p70[3]= {3.0,4.0,7.0};

        double p71[3]= {4.0,-4.0,0.0};
        double p72[3]= {4.0,-3.0,1.0};
        double p73[3]= {4.0,-2.0,2.0};
        double p74[3]= {4.0,-1.0,3.0};
        double p75[3]= {4.0,0.0,4.0};
        double p76[3]= {4.0,1.0,5.0};
        double p77[3]= {4.0,2.0,6.0};
        double p78[3]= {4.0,3.0,7.0};
        double p79[3]= {4.0,4.0,8.0};

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
        points ->InsertNextPoint(p8);
//        points ->InsertNextPoint(p8);
        points ->InsertNextPoint(p9);
//        points ->InsertNextPoint(p9);
        points ->InsertNextPoint(p10);
//        points ->InsertNextPoint(p10);
        points ->InsertNextPoint(p11);
//        points ->InsertNextPoint(p11);
        points ->InsertNextPoint(p12);
//        points ->InsertNextPoint(p12);
        points ->InsertNextPoint(p13);
//        points ->InsertNextPoint(p13);
        points ->InsertNextPoint(p14);
//        points ->InsertNextPoint(p14);
        points ->InsertNextPoint(p15);
//        points ->InsertNextPoint(p15);
        points ->InsertNextPoint(p16);
//        points ->InsertNextPoint(p16);
        points ->InsertNextPoint(p17);
//        points ->InsertNextPoint(p17);
        points ->InsertNextPoint(p18);
//        points ->InsertNextPoint(p18);
        points ->InsertNextPoint(p19);
//        points ->InsertNextPoint(p19);
        points ->InsertNextPoint(p20);
//        points ->InsertNextPoint(p20);
        points ->InsertNextPoint(p21);
//        points ->InsertNextPoint(p21);
        points ->InsertNextPoint(p22);
//        points ->InsertNextPoint(p22);
        points ->InsertNextPoint(p23);
//        points ->InsertNextPoint(p23);
        points ->InsertNextPoint(p24);
//        points ->InsertNextPoint(p24);
        points ->InsertNextPoint(p25);
//        points ->InsertNextPoint(p25);
        points ->InsertNextPoint(p26);
//        points ->InsertNextPoint(p26);
        points ->InsertNextPoint(p27);
//        points ->InsertNextPoint(p27);
        points ->InsertNextPoint(p28);
//        points ->InsertNextPoint(p28);
        points ->InsertNextPoint(p29);
//        points ->InsertNextPoint(p29);
        points ->InsertNextPoint(p30);
//        points ->InsertNextPoint(p30);
        points ->InsertNextPoint(p31);
//        points ->InsertNextPoint(p31);
        points ->InsertNextPoint(p32);
//        points ->InsertNextPoint(p32);
        points ->InsertNextPoint(p33);
//        points ->InsertNextPoint(p33);
        points ->InsertNextPoint(p34);
//        points ->InsertNextPoint(p34);
        points ->InsertNextPoint(p35);
//        points ->InsertNextPoint(p35);
        points ->InsertNextPoint(p36);
//        points ->InsertNextPoint(p36);
        points ->InsertNextPoint(p37);
//        points ->InsertNextPoint(p37);
        points ->InsertNextPoint(p38);
//        points ->InsertNextPoint(p38);
        points ->InsertNextPoint(p39);
//        points ->InsertNextPoint(p39);
        points ->InsertNextPoint(p40);
//        points ->InsertNextPoint(p40);
        points ->InsertNextPoint(p41);
//        points ->InsertNextPoint(p41);
        points ->InsertNextPoint(p42);
//        points ->InsertNextPoint(p42);
        points ->InsertNextPoint(p43);
//        points ->InsertNextPoint(p43);
        points ->InsertNextPoint(p44);
//        points ->InsertNextPoint(p44);
        points ->InsertNextPoint(p45);
//        points ->InsertNextPoint(p45);
        points ->InsertNextPoint(p46);
//        points ->InsertNextPoint(p46);
        points ->InsertNextPoint(p47);
//        points ->InsertNextPoint(p47);
        points ->InsertNextPoint(p48);
//        points ->InsertNextPoint(p48);
        points ->InsertNextPoint(p49);
//        points ->InsertNextPoint(p49);
        points ->InsertNextPoint(p50);
//        points ->InsertNextPoint(p50);
        points ->InsertNextPoint(p51);
//        points ->InsertNextPoint(p51);
        points ->InsertNextPoint(p52);
//        points ->InsertNextPoint(p52);
        points ->InsertNextPoint(p53);
//        points ->InsertNextPoint(p53);
        points ->InsertNextPoint(p54);
//        points ->InsertNextPoint(p54);
        points ->InsertNextPoint(p55);
//        points ->InsertNextPoint(p55);
        points ->InsertNextPoint(p56);
//        points ->InsertNextPoint(p56);
        points ->InsertNextPoint(p57);
//        points ->InsertNextPoint(p57);
        points ->InsertNextPoint(p58);
//        points ->InsertNextPoint(p58);
        points ->InsertNextPoint(p59);
//        points ->InsertNextPoint(p59);
        points ->InsertNextPoint(p60);
//        points ->InsertNextPoint(p60);
        points ->InsertNextPoint(p61);
//        points ->InsertNextPoint(p61);
        points ->InsertNextPoint(p62);
//        points ->InsertNextPoint(p62);
        points ->InsertNextPoint(p63);
//        points ->InsertNextPoint(p63);
        points ->InsertNextPoint(p64);
//        points ->InsertNextPoint(p64);
        points ->InsertNextPoint(p65);
//        points ->InsertNextPoint(p65);
        points ->InsertNextPoint(p66);
//        points ->InsertNextPoint(p66);
        points ->InsertNextPoint(p67);
//        points ->InsertNextPoint(p67);
        points ->InsertNextPoint(p68);
//        points ->InsertNextPoint(p68);
        points ->InsertNextPoint(p69);
//        points ->InsertNextPoint(p69);
        points ->InsertNextPoint(p70);
//        points ->InsertNextPoint(p70);
        points ->InsertNextPoint(p71);
//        points ->InsertNextPoint(p71);
        points ->InsertNextPoint(p72);
//        points ->InsertNextPoint(p72);
//        points ->InsertNextPoint(p73);
        points ->InsertNextPoint(p73);
//        points ->InsertNextPoint(p74);
        points ->InsertNextPoint(p74);
//        points ->InsertNextPoint(p75);
        points ->InsertNextPoint(p75);
//        points ->InsertNextPoint(p76);
        points ->InsertNextPoint(p76);
//        points ->InsertNextPoint(p77);
        points ->InsertNextPoint(p77);
//        points ->InsertNextPoint(p78);
        points ->InsertNextPoint(p78);
//        points ->InsertNextPoint(p79);
        points ->InsertNextPoint(p79);

        /*
        double p6[3]= {-0.5,0.25,0.0};
        double p7[3]= {0.0,0.0,0.0};
        double p8[3]= {0.5,0.25,0.0};
        double p9[3]= {1.0,1.0,0.0};
        double p10[3]= {1.5,2.25,0.0};
        double p11[3]= {2.0,4.0,0.0};
        double p12[3]= {2.5,6.25,0.0};
*/
        
        //Cuando empieza en 1 solo se ingresa una vez
        //Cuando empieza en 2 se agregan dos veces

        structuredGrid->SetDimensions(1,9,9);       // y=numero de x tabuladas, z = 1  // 9*9*1 = 81
                                    //2,4,1)        //2*4*1  = 8


        /** Puntos**/

        structuredGrid->SetPoints(points);

        geometryFilter->SetInputData(this->structuredGrid);
        geometryFilter->Update();

        mapper2->SetInputConnection(geometryFilter->GetOutputPort());

        actor2->GetProperty()->SetPointSize(4);
        actor2->GetProperty()->SetColor(255,0,0);

        //            actor2->SetMapper(mapper2);


        actor2->GetProperty()->SetColor(0,255,0);
        actor2->GetProperty()->SetEdgeColor(1.0, 0.0, 0.0); //(R,G,B)
        actor2->GetProperty()->EdgeVisibilityOn();  /*Para que se vea la interseccion, si es que es dim:1 se ve plano*/

        actor2->SetMapper(mapper2);


            /** **/
//            actor2->GetProperty()->SetInterpolationToFlat();
//            actor2->GetProperty()->EdgeVisibilityOn();

           /** **/
            /** LINEAS **/

            outlineFilter->SetInputData(this->structuredGrid);
            outlineFilter->Update();

            mapper->SetInputConnection(outlineFilter->GetOutputPort());

//            actor->GetProperty()->SetColor(0,255,0);
//            actor->GetProperty()->SetEdgeColor(0.0, 0.0, 1.0); //(R,G,B)
            actor1->SetMapper(mapper);

            /** **/


           /**AXES  **/

           transform->Translate(0.0, 0.0, 0.0);

           this->axess->SetUserTransform(transform);
           this->axess->SetTotalLength(5,5,5);

        // KAT

        renderWindow->AddRenderer(renderer);

       // renderWindowInteractor->SetRenderWindow(renderWindow);
        //TAMAÑO DE LOS EJES X Y Z

        axes->SetTotalLength(10.0,10.0,10.0);
        axes->SetConeRadius(0.1);

        //axes->SetUserTransform(transform);
        renderer->AddActor(axes);
        renderer->AddActor(actor);
        renderer->AddActor(actor2);

        renderer->SetBackground(.1, .1, .2);

        //renderWindow->Render();
        //renderWindowInteractor->Start();
        this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

vtk::~vtk()
{

}