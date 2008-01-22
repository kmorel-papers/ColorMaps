/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkOrderedCompositeDistributor.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

/*
 * Copyright 2008 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#include "vtkCIELABGamutSource.h"

#include "vtkCellArray.h"
#include "vtkMath.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkPolyData.h"
#include "vtkUnsignedCharArray.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

//=============================================================================
vtkCxxRevisionMacro(vtkCIELABGamutSource, "$Revision$");
vtkStandardNewMacro(vtkCIELABGamutSource);

//=============================================================================
vtkCIELABGamutSource::vtkCIELABGamutSource()
{
  this->Divisions = 10;

  this->SetNumberOfInputPorts(0);
}

vtkCIELABGamutSource::~vtkCIELABGamutSource()
{
}

void vtkCIELABGamutSource::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Divisions: " << this->Divisions << endl;
}

//-----------------------------------------------------------------------------
int vtkCIELABGamutSource::RequestData(
                                 vtkInformation *vtkNotUsed(request),
                                 vtkInformationVector **vtkNotUsed(inputVector),
                                 vtkInformationVector *outputVector)
{
  // get the info object
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  // get the ouptut
  vtkPolyData *output = vtkPolyData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  vtkIdType numPoints = 6*this->Divisions*this->Divisions;
  vtkIdType numCells = 6*(this->Divisions-1)*(this->Divisions-1);

  VTK_CREATE(vtkPoints, points);
  points->Allocate(numPoints);
  VTK_CREATE(vtkUnsignedCharArray, colors);
  colors->SetName("Colors");
  colors->SetNumberOfComponents(3);
  colors->Allocate(numPoints);

  double rgb[3];
  int i, j, k;

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = (double)i/(double)(this->Divisions-1);
      rgb[1] = (double)j/(double)(this->Divisions-1);
      rgb[2] = 0.0;
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = (double)i/(double)(this->Divisions-1);
      rgb[1] = (double)j/(double)(this->Divisions-1);
      rgb[2] = 1.0;
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = (double)i/(double)(this->Divisions-1);
      rgb[1] = 0.0;
      rgb[2] = (double)j/(double)(this->Divisions-1);
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = (double)i/(double)(this->Divisions-1);
      rgb[1] = 1.0;
      rgb[2] = (double)j/(double)(this->Divisions-1);
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = 0.0;
      rgb[1] = (double)i/(double)(this->Divisions-1);
      rgb[2] = (double)j/(double)(this->Divisions-1);
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  for (i = 0; i < this->Divisions; i++)
    {
    for (j = 0; j < this->Divisions; j++)
      {
      rgb[0] = 1.0;
      rgb[1] = (double)i/(double)(this->Divisions-1);
      rgb[2] = (double)j/(double)(this->Divisions-1);
      double *lab = vtkMath::RGBToLab(rgb);
      points->InsertNextPoint(lab);
      colors->InsertNextValue((unsigned char)(rgb[0]*255));
      colors->InsertNextValue((unsigned char)(rgb[1]*255));
      colors->InsertNextValue((unsigned char)(rgb[2]*255));
      }
    }

  output->SetPoints(points);
  output->GetPointData()->SetScalars(colors);

  VTK_CREATE(vtkCellArray, polys);
  polys->Allocate(polys->EstimateSize(numCells, 4));

  for (i = 0; i < 6; i++)
    {
    vtkIdType faceStart = i*(this->Divisions)*(this->Divisions);
    for (j = 0; j < this->Divisions-1; j++)
      {
      vtkIdType row1Start = faceStart + j*this->Divisions;
      vtkIdType row2Start = row1Start + this->Divisions;
      for (k = 0; k < this->Divisions-1; k++)
        {
        polys->InsertNextCell(4);
        polys->InsertCellPoint(row1Start  +k);
        polys->InsertCellPoint(row1Start+1+k);
        polys->InsertCellPoint(row2Start+1+k);
        polys->InsertCellPoint(row2Start  +k);
        }
      }
    }
  output->SetPolys(polys);

  return 1;
}

