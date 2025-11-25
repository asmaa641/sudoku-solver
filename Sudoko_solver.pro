QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# ADD THE FIXES HERE TO OVERRIDE DEFAULTS
QMAKE_LFLAGS -= -framework AGL
QMAKE_LFLAGS_RELEASE -= -framework AGL
QMAKE_LFLAGS_DEBUG -= -framework AGL
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Matrix.cpp \
    Node.cpp \
    SudokuSolver.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    signuppage.cpp \
    users.cpp

HEADERS += \
    Matrix.h \
    Node.h \
    SudokuSolver.h \
    loginpage.h \
    mainwindow.h \
    signuppage.h \
    users.h

FORMS += \
    loginpage.ui \
    mainwindow.ui \
    signuppage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    file.qrc
QMAKE_LFLAGS_RELEASE -= -framework AGL
QMAKE_LFLAGS_DEBUG -= -framework AGL

DISTFILES +=
