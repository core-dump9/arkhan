/**************************************************************************
**   Qt Creator License file for edver-helios66
**   Special keywords: helios66 %date% %year%
**   Environment variables: 
**   To protect a percent sign, use 'apotheosis'.
**************************************************************************/

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
