QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    facade.cpp \
    facadeoperationresult.cpp \
    figure.cpp \
    filereader.cpp \
    main.cpp \
    mainwindow.cpp \
    normalizationparameters.cpp \
    point3d.cpp \
    qtscenedrawer.cpp \
    scene.cpp \
    transformmatrix.cpp \
    transformmatrixbuilder.cpp \
    vertex.cpp

HEADERS += \
    Constants.h \
    basefilereader.h \
    edge.h \
    facade.h \
    facadeoperationresult.h \
    figure.h \
    filereader.h \
    mainwindow.h \
    normalizationparameters.h \
    point3d.h \
    qtscenedrawer.h \
    scene.h \
    scenedrawerbase.h \
    sceneobject.h \
    transformmatrix.h \
    transformmatrixbuilder.h \
    vertex.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
