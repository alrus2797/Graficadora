#ifndef VTK_H
#define VTK_H

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

#include "analizador.h"
#include "funciones.h"
#include "typedef.h"
#include <vector>
#include <iostream>

using namespace std;

class vtk

{

public:

  vtk();
  vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();

protected:

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

    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
      vtkSmartPointer<vtkRenderWindowInteractor>::New();

    vtkSmartPointer<vtkAxesActor> axes =
      vtkSmartPointer<vtkAxesActor>::New();

private:
  QStandardItemModel *model =new QStandardItemModel();

};

#endif // VTK_H
