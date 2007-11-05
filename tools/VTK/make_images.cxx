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

  VTK_CREATE(vtkColorTransferFunction, purple2orange);
  purple2orange->SetColorSpaceToMsh();
  purple2orange->AddRGBPoint(0.0, 0.436, 0.308, 0.631);
  // Spin the other way.
  purple2orange->AddRGBPoint(15.0/32.0, 0.965, 0.908, 0.912);
  purple2orange->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  purple2orange->AddRGBPoint(1.0, 0.759, 0.334, 0.046);
  generate_bar("Purple2OrangeBar.png", purple2orange);

  VTK_CREATE(vtkColorTransferFunction, green2purple);
  green2purple->SetColorSpaceToMsh();
  green2purple->AddRGBPoint(0.0, 0.085, 0.532, 0.201);
  green2purple->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  // Spin the other way.
  green2purple->AddRGBPoint(17.0/32.0, 0.965, 0.908, 0.912);
  green2purple->AddRGBPoint(1.0, 0.436, 0.308, 0.631);
  generate_bar("Green2PurpleBar.png", green2purple);

  VTK_CREATE(vtkColorTransferFunction, blue2tan);
  blue2tan->SetColorSpaceToMsh();
  blue2tan->AddRGBPoint(0.0, 0.293, 0.562, 0.873);
  blue2tan->AddRGBPoint(0.5, 0.943, 0.943, 0.943);
  blue2tan->AddRGBPoint(1.0, 0.845, 0.643, 0.204);
  generate_bar("Blue2TanBar.png", blue2tan);

  return 0;
}
