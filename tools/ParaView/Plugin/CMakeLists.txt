PROJECT(ColorMapParaViewCode)

FIND_PACKAGE(ParaView REQUIRED)
INCLUDE(${PARAVIEW_USE_FILE})

SET(SRCS
  vtkCIELABAxisSource.cxx
  vtkCIELABGamutSource.cxx
  vtkColorMapPlot.cxx
  vtkColorVectorSource.cxx
  )

ADD_PARAVIEW_PLUGIN(ColorMapsPlugin "1.0"
  SERVER_MANAGER_SOURCES ${SRCS}
  SERVER_MANAGER_XML ColorMapsPluginSM.xml
  GUI_RESOURCE_FILES ColorMapsPluginGUI.xml
  )
