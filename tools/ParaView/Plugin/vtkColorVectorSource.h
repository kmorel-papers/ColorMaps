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

// .NAME vtkColorVectorSource - Shows a color vector in CIELAB space
//
// .SECTION Description
//
// This simple source draws a line representing a vector in CIELAB space.
// The vector is defined in RGB space.  Two RGB coordinates are given, and
// the source will interpolate in time in Msh space.
//

#ifndef _vtkColorVectorSource_h
#define _vtkColorVectorSource_h

#include "vtkPolyDataAlgorithm.h"

class vtkColorVectorSource : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkColorVectorSource, vtkPolyDataAlgorithm);
  static vtkColorVectorSource *New();
  virtual void PrintSelf(ostream &os, vtkIndent indent);

  // Definition:
  // The start and end colors, defined in RGB space.
  vtkSetVector3Macro(StartColor, double);
  vtkGetVector3Macro(StartColor, double);
  vtkSetVector3Macro(EndColor, double);
  vtkGetVector3Macro(EndColor, double);

protected:
  vtkColorVectorSource();
  ~vtkColorVectorSource();

  double StartColor[3];
  double EndColor[3];

  virtual int RequestInformation(vtkInformation *,
                                 vtkInformationVector **,
                                 vtkInformationVector *);

  virtual int RequestData(vtkInformation *,
                          vtkInformationVector **,
                          vtkInformationVector *);

private:
  vtkColorVectorSource(const vtkColorVectorSource &);   // Not implemented
  void operator=(const vtkColorVectorSource &);         // Not implemented
};

#endif //_vtkColorVectorSource_h
