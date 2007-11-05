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
  generate_spatial_contrast_sensitivity("RainbowSpatialContrast.png", rainbow);

  VTK_CREATE(vtkColorTransferFunction, grayscale);
  grayscale->SetColorSpaceToLab();
  grayscale->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  grayscale->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
  generate_bar("GrayscaleBar.png", grayscale);
//   generate_discontinuity("GrayscaleDiscontinuity.png", grayscale);
  generate_locality("GrayscaleLocality.png", grayscale);
  generate_spatial_contrast_sensitivity("GrayscaleSpatialContrast.png",
                                        grayscale);

  VTK_CREATE(vtkColorTransferFunction, blackbody);
  blackbody->SetColorSpaceToLab();
  blackbody->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  blackbody->AddRGBPoint(0.4, 0.9, 0.0, 0.0);
  blackbody->AddRGBPoint(0.8, 0.9, 0.9, 0.0);
  blackbody->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
  generate_locality("BlackBodyLocality.png", blackbody);

  VTK_CREATE(vtkColorTransferFunction, cool2warm);
  cool2warm->SetColorSpaceToMsh();
  cool2warm->AddRGBPoint(0.0, 0.186, 0.392, 0.749);
  cool2warm->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  cool2warm->AddRGBPoint(1.0, 0.758, 0.214, 0.233);
  generate_bar("Cool2WarmBar.png", cool2warm);
//   generate_discontinuity("Cool2WarmDiscontinuity.png", cool2warm);
  generate_spatial_contrast_sensitivity("Cool2WarmSpatialContrast.png",
                                        cool2warm);
  generate_radial("Cool2WarmRadial.png", cool2warm);

  VTK_CREATE(vtkColorTransferFunction, cool2warmLab);
  cool2warmLab->SetColorSpaceToLab();
  cool2warmLab->AddRGBPoint(0.0, 0.186, 0.392, 0.749);
  cool2warmLab->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  cool2warmLab->AddRGBPoint(1.0, 0.758, 0.214, 0.233);
  generate_radial("Cool2WarmLabRadial.png", cool2warmLab);

  VTK_CREATE(vtkColorTransferFunction, green2red);
  green2red->SetColorSpaceToLab();
  green2red->AddRGBPoint(0.0, 0.231, 0.675, 0.157);
  green2red->AddRGBPoint(1.0, 0.988, 0.404, 0.2);
  generate_bar("Green2RedBar.png", green2red);

  VTK_CREATE(vtkColorTransferFunction, cyan2mauve);
  cyan2mauve->SetColorSpaceToLab();
  cyan2mauve->AddRGBPoint(0.0, 0.0, 0.6, 0.75);
  cyan2mauve->AddRGBPoint(1.0, 0.768, 0.467, 0.341);
  generate_bar("Cyan2MauveBar.png", cyan2mauve);

  return 0;
}
