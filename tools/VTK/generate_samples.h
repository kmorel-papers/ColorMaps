// -*- c++ -*-

#include "vtkColorTransferFunction.h"

void generate_bar(const char *filename, vtkColorTransferFunction *map);

void generate_radial(const char *filename, vtkColorTransferFunction *map);

void generate_discontinuity(const char *filename,
                            vtkColorTransferFunction *map);

void generate_locality(const char *filename, vtkColorTransferFunction *map);

void generate_spatial_contrast_sensitivity(const char *filename,
                                           vtkColorTransferFunction *map);

void generate_hf_noise(const char *filename, vtkColorTransferFunction *map);

void generate_lf_sensitivity(const char *filename,
                             vtkColorTransferFunction *map);
