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

// .NAME vtkCIELABGamutSource - Create a poly data representing the RGB gamut in CIELAB space.
//

#ifndef _vtkCIELABGamutSource_h
#define _vtkCIELABGamutSource_h

#include "vtkPolyDataAlgorithm.h"

class vtkCIELABGamutSource : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkCIELABGamutSource, vtkPolyDataAlgorithm);
  static vtkCIELABGamutSource *New();
  virtual void PrintSelf(ostream &os, vtkIndent indent);

  // Description:
  // Set the number of divisions to use along each axis of the gamut.
  vtkSetMacro(Divisions, int);
  vtkGetMacro(Divisions, int);

protected:
  vtkCIELABGamutSource();
  ~vtkCIELABGamutSource();

  int Divisions;

  virtual int RequestData(vtkInformation *,
                          vtkInformationVector **,
                          vtkInformationVector *);

private:
  vtkCIELABGamutSource(const vtkCIELABGamutSource &);   // Not implemented
  void operator=(const vtkCIELABGamutSource &);         // Not implemented
};

#endif //_vtkCIELABGamutSource_h
