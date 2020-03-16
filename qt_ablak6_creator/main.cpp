#include <QtGui>
#include <QtCore>
#include <QStringBuilder>
//#include <QChart>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "newcontactwindow.h"
#include "firstmainwindow.h"
#include <stdio.h>



int main(int argc, char **argv  ){

   //Modalis segedablak: sajat esemenyertelmezo ciklust indit
   //Modalis ablakot statikus valtozokent deklaralom.
   QApplication app(argc,argv);

   QDesktopWidget wid;
   int screenWidth = wid.screen()->width();
   int screenHeight = wid.screen()->height();

   FirstMainWindow *foablak1= new FirstMainWindow;

   //foablak1-et futtat;
   foablak1->setGeometry((screenWidth/2)-(1000/2),(screenHeight/2)-(1000/2),1024,768);
   foablak1->show();
   
   return app.exec();

};
