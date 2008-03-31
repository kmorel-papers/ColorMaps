// -*- c++ -*-

#include "generate_samples.h"

#include "vtkArrayCalculator.h"
#include "vtkImageData.h"
#include "vtkImageMapToColors.h"
#include "vtkMath.h"
#include "vtkPerlinNoise.h"
#include "vtkPNGWriter.h"
#include "vtkPointData.h"
#include "vtkSampleFunction.h"

#include <math.h>

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

const int DPI = 1200;
// const int DPI = 200;

//-----------------------------------------------------------------------------
void generate_bar(const char *filename, vtkColorTransferFunction *map)
{
  const int width = (int)(2.5*DPI);
  const int height = (int)(0.125*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    for (int i = 0; i <= width; i++)
      {
      double *color = map->GetColor((double)i/width);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}

//-----------------------------------------------------------------------------
void generate_radial(const char *filename, vtkColorTransferFunction *map)
{
  const int width = (int)(1.0*DPI);
  const int height = (int)(1.0*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    double y = 2.0*j/height - 1.0;
    for (int i = 0; i <= width; i++)
      {
      double x = 2.0*i/width - 1.0;
      double r = sqrt(x*x+y*y);
      double *color = map->GetColor(0.7*r);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}

//-----------------------------------------------------------------------------
void generate_discontinuity(const char *filename, vtkColorTransferFunction *map)
{
  const int width = (int)(1.25*DPI);
  const int height = (int)(0.125*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    for (int i = 0; i <= width; i++)
      {
      double x = 1.1*i/width;
      if (i > width/2)
        {
        x -= 0.1;
        }
      double *color = map->GetColor(x);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}

//-----------------------------------------------------------------------------
void generate_locality(const char *filename, vtkColorTransferFunction *map)
{
  const int width = (int)(2.5*DPI);
  const int height = (int)(0.5*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    double y = 0.4*j/height - 0.2;
    for (int i = 0; i <= width; i++)
      {
      double x = 2.0*i/width - 1.0;
      double v;
      if (   (y > -0.05) && (y < 0.05)
//           && (((x > -0.9) && (x < -0.8)) || ((x > 0.8) && (x < 0.9))) )
          && (x > -0.95) && (x < 0.95) )
        {
        v = 0.5;
        }
      else
        {
//         if (x < 0.0)
//           {
//           v = 0.05;
//           }
//         else
//           {
//           v = 0.95;
//           }
        v = 0.5*x + 0.5;
        }
      double *color = map->GetColor(v);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}

//-----------------------------------------------------------------------------
void generate_spatial_contrast_sensitivity(const char *filename,
                                           vtkColorTransferFunction *map)
{
  const int width = (int)(1.0*DPI);
  const int height = (int)(1.0*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    double y = (double)j/height;
    for (int i = 0; i <= width; i++)
      {
      double x = (double)i/width;
      double v = (1.0-y)*sin(50.0*x*x);
      double *color = map->GetColor(0.5*v+0.5);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}

static vtkSmartPointer<vtkImageData> HighFrequencyNoise;
//-----------------------------------------------------------------------------
void generate_hf_noise(const char *filename, vtkColorTransferFunction *map)
{
  const int width = (int)(1.0*DPI);
  const int height = (int)(0.75*DPI);

  if (!HighFrequencyNoise)
    {
    VTK_CREATE(vtkPerlinNoise, noiseFunction);
    noiseFunction->SetFrequency(30.0, 22.5, 1.0);
    noiseFunction->SetPhase(0.0, 0.0, 0.0);
    noiseFunction->SetAmplitude(0.5);

    VTK_CREATE(vtkSampleFunction, noiseImage);
    noiseImage->SetImplicitFunction(noiseFunction);
    noiseImage->SetOutputScalarTypeToDouble();
    noiseImage->SetSampleDimensions(width, height, 1);
    noiseImage->SetModelBounds(0.0, 1.0, 0.0, 1.0, 0.0, 0.0);
    noiseImage->CappingOff();
    noiseImage->ComputeNormalsOff();

    noiseImage->Update();

    HighFrequencyNoise = vtkSmartPointer<vtkImageData>::New();
    HighFrequencyNoise->ShallowCopy(noiseImage->GetOutput());
    HighFrequencyNoise->GetPointData()->GetScalars()->SetName("noise");
    }

  VTK_CREATE(vtkArrayCalculator, calculator);
  calculator->SetInput(HighFrequencyNoise);
  calculator->SetAttributeModeToUsePointData();
  calculator->AddScalarArrayName("noise");
  calculator->AddCoordinateScalarVariable("xpos", 0);
  calculator->SetFunction("0.15*(noise + 0.5) + 0.85*xpos");

  VTK_CREATE(vtkImageMapToColors, colorMap);
  colorMap->SetInputConnection(calculator->GetOutputPort());
  colorMap->SetLookupTable(map);
  colorMap->SetOutputFormatToRGB();

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInputConnection(colorMap->GetOutputPort());
  writer->Write();
}

//-----------------------------------------------------------------------------
void generate_lf_sensitivity(const char *filename,
                             vtkColorTransferFunction *map)
{
  const int width = (int)(1.0*DPI);
  const int height = (int)(0.75*DPI);
  VTK_CREATE(vtkImageData, imageData);
  imageData->SetDimensions(width+1, height+1, 1);
  imageData->SetScalarTypeToUnsignedChar();
  imageData->SetNumberOfScalarComponents(3);

  unsigned char *data
    = reinterpret_cast<unsigned char *>(imageData->GetScalarPointer());
  for (int j = 0; j <= height; j++)
    {
    double y = (double)j/height;
    for (int i = 0; i <= width; i++)
      {
      double x = (double)i/width;
      double v = (  0.8*(x - 0.5)
                  + 0.3*sin(8.0*2.0*vtkMath::DoublePi()*x)
                  + 0.3*sin(3.0*2.0*vtkMath::DoublePi()*y) );
      double *color = map->GetColor(0.5*v+0.5);
      data[0] = (unsigned char)(color[0]*255);
      data[1] = (unsigned char)(color[1]*255);
      data[2] = (unsigned char)(color[2]*255);
      data += 3;
      }
    }

  VTK_CREATE(vtkPNGWriter, writer);
  writer->SetFileName(filename);
  writer->SetInput(imageData);
  writer->Write();
}
