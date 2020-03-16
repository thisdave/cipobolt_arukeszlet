#ifndef NEWCONTACTWINDOW_H
#define NEWCONTACTWINDOW_H


#include <QtGui>

class NewContactWindow : public QDialog  
{
   Q_OBJECT
   private:

     QLabel * labelAdatok;

     QGroupBox *group;
     QLabel * labelVasId;
     QLabel * labelNev;
     QLabel * labelEmail;
     QLabel * labelCipoMeret;
     QLabel * labelMarka;
     QLabel * labelDbSzam;
     QLabel * labelCipoModellNev;


//Epito elemek
     QLineEdit *txtVasId;
     QLineEdit *txtNev;
     QLineEdit *txtEmail;
     QLineEdit *txtCipoMeret;
     QLineEdit *txtDbSzam;
     QLineEdit *txtCipoModellNev;
     QLineEdit *txtCipoMarka;
     QPushButton *btnOk;
     QPushButton *btnCancel;

//Elrendezok
     QGridLayout *grid_layo; //racs layout
     QVBoxLayout *main_layo; //ablak layout
     QHBoxLayout *btns_layo; //gombok layoutja


//Adat tagok, amik a tenyleges informaciot tartalmazzak:
     QString *vasID;
     QString *Nev;
     QString *emailcim;
     QString *cipom;
     QString *ModellNev;
     QString *DbSzam;

   public:

     NewContactWindow(QWidget * parent=0);
  
  QString getVasId();
  QString getName();
  QString getEmail();
  QString getCipoMeret();
  QString getModellNev();
  QString getDbSzam();

  signals:
  public slots:

  
};

#endif
