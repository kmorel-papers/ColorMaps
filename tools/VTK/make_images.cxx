// -*- c++ -*-

#include "generate_samples.h"

#include "vtkColorTransferFunction.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

int main(int, char **)
{
  VTK_CREATE(vtkColorTransferFunction, rainbow);
  rainbow->SetColorSpaceToHSV();
  rainbow->HSVWrapOff();
  rainbow->AddHSVPoint(0.0, 0.66667, 1.0, 1.0);
  rainbow->AddHSVPoint(1.0, 0.0, 1.0, 1.0);
  generate_bar("RainbowBar.png", rainbow);
//   generate_radial("RainbowRadial.png", rainbow);
//   generate_discontinuity("RainbowDiscontinuity.png", rainbow);
//   generate_spatial_contrast_sensitivity("RainbowSpatialContrast.png", rainbow);

  VTK_CREATE(vtkColorTransferFunction, grayscale);
  grayscale->SetColorSpaceToLab();
  grayscale->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  grayscale->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
  generate_bar("GrayscaleBar.png", grayscale);
//   generate_discontinuity("GrayscaleDiscontinuity.png", grayscale);
  generate_locality("GrayscaleLocality.png", grayscale);
//   generate_spatial_contrast_sensitivity("GrayscaleSpatialContrast.png",
//                                         grayscale);

  VTK_CREATE(vtkColorTransferFunction, blackbody);
  blackbody->SetColorSpaceToLab();
  blackbody->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  blackbody->AddRGBPoint(0.4, 1.0, 0.0, 0.0);
  blackbody->AddRGBPoint(0.8, 1.0, 1.0, 0.0);
  blackbody->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
  generate_locality("BlackBodyLocality.png", blackbody);

  VTK_CREATE(vtkColorTransferFunction, cool2warm);
  cool2warm->SetColorSpaceToMsh();
  cool2warm->AddRGBPoint(0.0, 0.186, 0.392, 0.749);
  cool2warm->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  cool2warm->AddRGBPoint(1.0, 0.758, 0.214, 0.233);
//   generate_bar("Cool2WarmBar.png", cool2warm);
//   generate_discontinuity("Cool2WarmDiscontinuity.png", cool2warm);
//   generate_spatial_contrast_sensitivity("Cool2WarmSpatialContrast.png",
//                                         cool2warm);

  return 0;
}
