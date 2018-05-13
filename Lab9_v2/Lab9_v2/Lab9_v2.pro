TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Base/herbivore.cpp \
    Base/mammal.cpp \
    Base/predator.cpp \
    tiger.cpp

HEADERS += \
    Base/herbivore.hpp \
    Base/mammal.hpp \
    Base/predator.hpp \
    tiger.hpp
