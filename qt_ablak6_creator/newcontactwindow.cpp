#include "newcontactwindow.h"

NewContactWindow::NewContactWindow  (QWidget *parent) :
QDialog(parent)
     {

      this->setWindowTitle("Kontakt hozzaadasa"); 
  
      group                    =     new QGroupBox();

      labelVasId               =     new QLabel("Adatok:");
      labelAdatok              =     new QLabel("Adatok:");
      labelNev                 =     new QLabel("Nev:");
      labelEmail               =     new QLabel("email:");
      labelCipoMeret           =     new QLabel("cipomeret:");  
      labelDbSzam              =     new QLabel("db_szam:");
      labelCipoModellNev       =      new QLabel("cipo_markamodell:");
     
      txtVasId            =    new QLineEdit("");
      txtNev              =    new QLineEdit("");
      txtEmail            =     new QLineEdit("");
      txtCipoMeret        =     new QLineEdit("");
      txtCipoModellNev    =     new QLineEdit("");
      txtDbSzam           =     new QLineEdit("");
      txtCipoMarka         =     new QLineEdit("");
      btnOk             =     new QPushButton("ok");
      btnCancel         =     new QPushButton("cancel");

      //1. Csinálok egy gridlayoutot
      //2.  hozzaadom a 4 vezerlot
      //3. Beállítom hogy a group QGroupBox objektum kezelője
      // a grid_layo legyen      

      grid_layo = new QGridLayout();

      grid_layo->addWidget(labelNev, 0 ,0);
      grid_layo->addWidget(txtNev, 0 ,1);
      grid_layo->addWidget(labelEmail, 1,0);
      grid_layo->addWidget(txtEmail, 1 ,1);
      grid_layo->addWidget(labelCipoMeret,2,0);
      grid_layo->addWidget(txtCipoMeret, 2 ,1);
      grid_layo->addWidget(labelCipoModellNev,3,0);
      grid_layo->addWidget(txtCipoModellNev,3,1);
      grid_layo->addWidget(labelDbSzam,4,0);
      grid_layo->addWidget(txtDbSzam,4,1);
 


      group->setLayout(grid_layo);

   

      btns_layo        =           new QHBoxLayout();
      btns_layo       ->          addStretch();
      btns_layo       ->           addWidget(btnOk);
      btns_layo       ->           addWidget(btnCancel);

      main_layo        =          new QVBoxLayout();
      this            ->      setLayout(main_layo);
      main_layo       ->      addWidget(group);
      main_layo       ->      addStretch();
      main_layo       ->      addLayout(btns_layo);

      


      
     connect( btnOk,SIGNAL(clicked()),this, SLOT( accept()    ));
     connect( btnCancel,SIGNAL(clicked()),this, SLOT(reject() ));
      
      
    }
QString NewContactWindow::getVasId()        {  return txtVasId->text();    }
QString NewContactWindow::getName()          {  return txtNev->text();         }
QString NewContactWindow::getEmail()         {  return txtEmail->text();       }
QString NewContactWindow::getCipoMeret()     {  return txtCipoMeret->text();  }
QString NewContactWindow::getModellNev()     {  return txtCipoMarka->text();      }
QString NewContactWindow::getDbSzam()        {  return txtDbSzam->text();      }
