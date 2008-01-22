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

// .NAME vtkCIELABAxisSource - Create a poly data representing axis in CIELAB space.
//

#ifndef _vtkCIELABAxisSource_h
#define _vtkCIELABAxisSource_h

#include "vtkPolyDataAlgorithm.h"

class vtkCIELABAxisSource : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkCIELABAxisSource, vtkPolyDataAlgorithm);
  static vtkCIELABAxisSource *New();
  virtual void PrintSelf(ostream &os, vtkIndent indent);

  // Description:
  // Set the scale factor (the value to which each axis goes).  Default is 100.
  vtkSetMacro(ScaleFactor, double);
  vtkGetMacro(ScaleFactor, double);

protected:
  vtkCIELABAxisSource();
  ~vtkCIELABAxisSource();

  double ScaleFactor;

  virtual int RequestData(vtkInformation *,
                          vtkInformationVector **,
                          vtkInformationVector *);

private:
  vtkCIELABAxisSource(const vtkCIELABAxisSource &);     // Not implemented
  void operator=(const vtkCIELABAxisSource &);          // Not implemented
};

#endif //_vtkCIELABAxisSource_h
