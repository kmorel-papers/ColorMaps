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

#include "vtkColorVectorSource.h"

#include "vtkCellArray.h"
#include "vtkColorTransferFunction.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkPolyData.h"
#include "vtkStreamingDemandDrivenPipeline.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

//=============================================================================
vtkCxxRevisionMacro(vtkColorVectorSource, "$Revision$");
vtkStandardNewMacro(vtkColorVectorSource);

//=============================================================================
vtkColorVectorSource::vtkColorVectorSource()
{
  this->StartColor[0] = 0.1381;
  this->StartColor[1] = 0.2411;
  this->StartColor[2] = 0.7091;

  this->EndColor[0] = 0.6728;
  this->EndColor[1] = 0.1409;
  this->EndColor[2] = 0.1266;

  this->SetNumberOfInputPorts(0);
}

vtkColorVectorSource::~vtkColorVectorSource()
{
}

void vtkColorVectorSource::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "StartColor: " << this->StartColor[0] << ", "
     << this->StartColor[0] << ", " << this->StartColor[0] << endl;
  os << indent << "EndColor: " << this->EndColor[0] << ", "
     << this->EndColor[0] << ", " << this->EndColor[0] << endl;
}

//-----------------------------------------------------------------------------
int vtkColorVectorSource::RequestInformation(
                                 vtkInformation *vtkNotUsed(request),
                                 vtkInformationVector **vtkNotUsed(inputVector),
                                 vtkInformationVector *outputVector)
{
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  double timeRange[2];
  timeRange[0] = 0.0;  timeRange[1] = 1.0;
  outInfo->Set(vtkStreamingDemandDrivenPipeline::TIME_RANGE(), timeRange, 2);

  return 1;
}

//-----------------------------------------------------------------------------
int vtkColorVectorSource::RequestData(
                                 vtkInformation *vtkNotUsed(request),
                                 vtkInformationVector **vtkNotUsed(inputVector),
                                 vtkInformationVector *outputVector)
{
  // get the info object
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  // get the current time
  double time = 0.0;
  if (outInfo->Has(vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEPS()))
    {
    time
      = outInfo->Get(vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEPS())[0];
    }

  // Interpolate to the given time.
  VTK_CREATE(vtkColorTransferFunction, interpolator);
  interpolator->RemoveAllPoints();
  interpolator->SetColorSpaceToDiverging();
  interpolator->AddRGBPoint(0.0, this->StartColor[0], this->StartColor[1],
                            this->StartColor[2]);
  interpolator->AddRGBPoint(1.0, this->EndColor[0], this->EndColor[1],
                            this->EndColor[2]);
  double rgb[3];
  interpolator->GetColor(time, rgb);

  double lab[3];
  vtkMath::RGBToLab(rgb, lab);

  // get the ouptut
  vtkPolyData *output = vtkPolyData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));

  VTK_CREATE(vtkPoints, points);
  points->Allocate(2);
  points->InsertNextPoint(0.0, 0.0, 0.0);
  points->InsertNextPoint(lab);
  output->SetPoints(points);

  VTK_CREATE(vtkCellArray, lines);
  lines->Allocate(lines->EstimateSize(1, 2));
  lines->InsertNextCell(2);
  lines->InsertCellPoint(0);  lines->InsertCellPoint(1);

  output->SetLines(lines);

  return 1;
}

