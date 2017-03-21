#-------------------------------------------------
#
# Project created by QtCreator 2017-03-18T20:25:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scribble
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        signupwindow.cpp \
    courselist.cpp \
    course.cpp \
    textbook.cpp \
    chapter.cpp \
    note.cpp \
    userbranchnote.cpp \
    change.cpp \
    student.cpp \
    database.cpp

HEADERS  += signupwindow.h \
    courselist.h \
    course.h \
    textbook.h \
    chapter.h \
    note.h \
    userbranchnote.h \
    change.h \
    student.h \
    database.h

FORMS    += signupwindow.ui
