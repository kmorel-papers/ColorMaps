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

#include "vtkCIELABAxisSource.h"

#include "vtkCellArray.h"
#include "vtkCellData.h"
#include "vtkFloatArray.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkPolyData.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

//=============================================================================
vtkCxxRevisionMacro(vtkCIELABAxisSource, "$Revision$");
vtkStandardNewMacro(vtkCIELABAxisSource);

//=============================================================================
vtkCIELABAxisSource::vtkCIELABAxisSource()
{
  this->ScaleFactor = 100.0;

  this->SetNumberOfInputPorts(0);
}

vtkCIELABAxisSource::~vtkCIELABAxisSource()
{
}

void vtkCIELABAxisSource::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "ScaleFactor: " << this->ScaleFactor << endl;
}

//-----------------------------------------------------------------------------
int vtkCIELABAxisSource::RequestData(
                                 vtkInformation *vtkNotUsed(request),
                                 vtkInformationVector **vtkNotUsed(inputVector),
                                 vtkInformationVector *outputVector)
{
  // get the info object
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  // get the ouptut
  vtkPolyData *output = vtkPolyData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  VTK_CREATE(vtkPoints, points);
  points->Allocate(6);
  points->InsertNextPoint(0.0, 0.0, 0.0);
  points->InsertNextPoint(this->ScaleFactor, 0.0, 0.0);
  points->InsertNextPoint(0.0, -this->ScaleFactor, 0.0);
  points->InsertNextPoint(0.0, this->ScaleFactor, 0.0);
  points->InsertNextPoint(0.0, 0.0, -this->ScaleFactor);
  points->InsertNextPoint(0.0, 0.0, this->ScaleFactor);
  output->SetPoints(points);

  VTK_CREATE(vtkCellArray, lines);
  lines->Allocate(lines->EstimateSize(5, 2));
  VTK_CREATE(vtkFloatArray, scalars);
  scalars->SetName("Axes");
  scalars->SetNumberOfComponents(1);
  scalars->Allocate(5);

  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(1);
  scalars->InsertNextValue(0.0f);

  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(2);
  scalars->InsertNextValue(2.0f);

  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(3);
  scalars->InsertNextValue(3.0f);

  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(4);
  scalars->InsertNextValue(4.0f);

  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(5);
  scalars->InsertNextValue(5.0f);

  output->SetLines(lines);
  output->GetCellData()->SetScalars(scalars);

  return 1;
}

