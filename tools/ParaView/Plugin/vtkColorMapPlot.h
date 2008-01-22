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

// .NAME vtkColorMapPlot - Shows a color vector in CIELAB space
//
// .SECTION Description
//
// This simple source draws a curve representing the interploation of a
// diverging color map in CIELAB space.  Two RGB coordinates are given, and the
// source will interpolate in time in Msh space.  The curve will be from 0 to
// the current time step (so that the curve can be drawn out).
//

#ifndef _vtkColorMapPlot_h
#define _vtkColorMapPlot_h

#include "vtkPolyDataAlgorithm.h"

class vtkColorMapPlot : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkColorMapPlot, vtkPolyDataAlgorithm);
  static vtkColorMapPlot *New();
  virtual void PrintSelf(ostream &os, vtkIndent indent);

  // Definition:
  // The start and end colors, defined in RGB space.
  vtkSetVector3Macro(StartColor, double);
  vtkGetVector3Macro(StartColor, double);
  vtkSetVector3Macro(EndColor, double);
  vtkGetVector3Macro(EndColor, double);

  vtkSetMacro(Resolution, int);
  vtkGetMacro(Resolution, int);

protected:
  vtkColorMapPlot();
  ~vtkColorMapPlot();

  double StartColor[3];
  double EndColor[3];

  int Resolution;

  virtual int RequestInformation(vtkInformation *,
                                 vtkInformationVector **,
                                 vtkInformationVector *);

  virtual int RequestData(vtkInformation *,
                          vtkInformationVector **,
                          vtkInformationVector *);

private:
  vtkColorMapPlot(const vtkColorMapPlot &);     // Not implemented
  void operator=(const vtkColorMapPlot &);      // Not implemented
};

#endif //_vtkColorMapPlot_h
