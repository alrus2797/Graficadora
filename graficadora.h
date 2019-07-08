#ifndef GRAFICADORA_H
#define GRAFICADORA_H

#include <QMainWindow>

#include <vtkVersion.h>
#include <vtkCellArray.h>
#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include "vtkSmartPointer.h"
#include <map>
#include <vtkAxesActor.h>
#include <vtkTransform.h>

#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>
#include <vtkPolyData.h>

#include <vtkSmartPointer.h>
#include <vtkStructuredGrid.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkMath.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>

#include <vtkStructuredGridOutlineFilter.h>
#include <vtkStructuredGridGeometryFilter.h>
#include <QStandardItemModel>
#include <QMainWindow>

#include "analizador.h"
#include "arbol.h"

namespace Ui {
class Graficadora;
}

class Graficadora : public QMainWindow
{
    Q_OBJECT

public:

    vtkSmartPointer<vtkStructuredGrid> structuredGrid =
      vtkSmartPointer<vtkStructuredGrid>::New();

    vtkSmartPointer<vtkStructuredGridOutlineFilter> outlineFilter =
      vtkSmartPointer<vtkStructuredGridOutlineFilter>::New();

    vtkSmartPointer<vtkPoints> points =
      vtkSmartPointer<vtkPoints>::New();

    vtkSmartPointer<vtkStructuredGridGeometryFilter> geometryFilter =
      vtkSmartPointer<vtkStructuredGridGeometryFilter>::New();

    vtkSmartPointer<vtkPolyLine> polyLine =
       vtkSmartPointer<vtkPolyLine>::New();

    vtkSmartPointer<vtkTransform> transform =
       vtkSmartPointer<vtkTransform>::New();

    vtkSmartPointer<vtkAxesActor> axess =
       vtkSmartPointer<vtkAxesActor>::New();

    vtkSmartPointer<vtkPolyDataMapper> mapper0 =
       vtkSmartPointer<vtkPolyDataMapper>::New();

    vtkSmartPointer<vtkPolyDataMapper> mapper =
       vtkSmartPointer<vtkPolyDataMapper>::New();

    vtkSmartPointer<vtkPolyDataMapper> mapper2 =
      vtkSmartPointer<vtkPolyDataMapper>::New();

    vtkSmartPointer<vtkActor> actor =
      vtkSmartPointer<vtkActor>::New();

    vtkSmartPointer<vtkActor> actor1 =
      vtkSmartPointer<vtkActor>::New();

    vtkSmartPointer<vtkActor> actor2 =
      vtkSmartPointer<vtkActor>::New();

    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();

    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
      vtkSmartPointer<vtkRenderWindowInteractor>::New();

    vtkSmartPointer<vtkAxesActor> axes =
      vtkSmartPointer<vtkAxesActor>::New();

    explicit Graficadora(QWidget *parent = 0);
    ~Graficadora();

private slots:

    void on_Boton_clicked();

private:
    Ui::Graficadora *ui;

    analizador * expresion=new analizador;
    QStandardItemModel *model =new QStandardItemModel();
    Arbol *arbol=new Arbol;
    std::map<std::string,int>prioridad;

};

#endif // GRAFICADORA_H
