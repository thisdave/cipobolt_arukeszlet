#ifndef FIRSTMAINWINDOW_H
#define FIRSTMAINWINDOW_H

#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QVector>
#include <QString>
#include <string>
#include <QStringBuilder>
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "newcontactwindow.h"
#include "searchdlg.h"

class FirstMainWindow : public QMainWindow{
 Q_OBJECT
 public:
 explicit FirstMainWindow (QWidget * parent = nullptr);
 
 signals: 
 public slots:






    //Rendezo_fv.ek. keszek

    void mainTabla_rendezd_vasnev_sz();
    void mainTabla_rendezd_vasemailcim_sz();
    void mainTabla_rendezd_cipomodellId_sz();
    void mainTabla_rendezd_cipoMeret_sz();


    //Rendezes Cipoarak KEZD:
    void cipoarakTabla_rendezd_cipoModellId_szerint();
    void cipoarakTabla_rendezd_cipoModellNev_szerint();
    void cipoarakTabla_rendezd_cipoAr_szerint();
    //Rendezes Cipoarak VEGE:

    //Rendezes Table raktarkeszlet KEZD:
     void raktarkeszletTabla_rendezd_cipoId_szerint();
    //Rendezes Table raktarkeszlet VEGE:



    int nyers_adatsorokat_beolvas();

    void adatokat_feldolgoz_fromMainTable_toMainTableB();
   //beolvas_uj_adatokat_mainTablebe();

    void osszes_tablat_elrejt();
    void tablat_valts_1();//Cipoarak tablat mutat a, többit elrejti
    void tablat_valts_2();//Raktarkeszlet tablat mutatja, többit elrejti
    void tablat_valts_3();//Main tablat mutatja, többit elrejti
  
    //A 'cipoarak.txt'-jet ugyanugy visszairom mindig
    int cipoarakTablaBetoltesFajlbol(); 
    //'01_Cipoarak.txt 'beolvassa fajlbol es betolti a table_CipoArak tablaba
    int cipoarakTablaKiirasFajlba() ;
    // a table_CipoArak tabla tartalmat kiirja a 'cipoarak.txt'tablaba

    int mainTablaBetoltesFajlbol();
    // a main tabla tartalmat kiirja a '02_raktarkeszlet.txt' tablaba
    int mainTablaKiirasFajlba();
    //a mainTabla tartalmat kiirja a  01_data.txt  tablaba

    //raktarkeszlet betoltese/kiirasa
    int raktarkeszletTablaBetoltesFajlbol();
    int raktarkeszletTablaKiirasFajlba();



 

     int uj_cipotipus_felvetele(QString cipoModellNev, QString cipoId,QString cipoAr);

    //void addNewContact();
    void updateStatusText();
    void showSearch();

public:
    void closeEvent(QCloseEvent* event); 

   //rövid műveletek, gyorsbillentyűs
    QAction *exitAction;
    QAction *newContactAction;
    QAction *loadNewDataFromFileAction; 

    QAction * nyers_adatsorokat_beolvas_fajlbol_Action;
   
    QAction *adatok_make_main_tableBfrom_MainTable_Action;

    QAction * cipoarakTablaBetoltesFajlbol_Action;//fv nev pipa
    QAction * cipoarakTablaKiirasFajlba_Action;// fv nev pipa
    QAction * mainTablaBetoltesFajlbol_Action;
    QAction * mainTablaKiirasFajlba_Action;
    QAction * raktarkeszletTablaKiirasFajlba_Action;
    QAction * raktarkeszletTablaBetoltesFajlbol_Action;

    QAction * osszes_tablat_elrejt_Action;

    QAction * showSearchAction;
    QAction * struktFeltoltAction;
    QAction * cipomDiagAction;

    QAction * mainTablaMutat_Action;
    QAction * cipoarakTablaMutat_Action;
    QAction * raktarkeszletTablaMutat_Action;
 


    QAction *  mainTabla_rendezd_vasnev_sz_Action;
    QAction *  mainTabla_rendezd_vasemail_sz_Action;
    QAction *  mainTabla_rendezd_cipomeret_sz_Action;
    QAction *  mainTabla_rendezd_cipomodell_sz_Action ;



    QMenu * fileMenu;
    QMenu * rendezesMenu;
    QMenu * tablaMenu;
    QMessageBox msg;

    QTableWidget * table1_main;
    QTableWidget *table1_mainB;
    QTableWidget * table2_cipoarak;
    QTableWidget * table3_raktarkeszlet;
   

     //ezt majd a konstruktorban letrehozom, adatbetolt tolti fel
    SearchDlg * searchDialog1;

    int cipom_elemszam;


    friend class NewContactWindow;

};

#endif

class elemi_Vasarlas {
    public:
    int vasarlas_tetel1db_id;
    QString *vasarloNeve;
    QString *vasarloEmailje;
    int cipoModellId;
    int cipoMeret;
    int darabSzam;

//Konstruktor

    elemi_Vasarlas(int cipoMeret,int darabSzam, int cipoModellId,   
        const QString & vasarloNeve,const QString & vasarloEmailje)
      { 
       this->cipoMeret  =  cipoMeret;
       this->darabSzam  =  darabSzam; 
       this->vasarloNeve    = new QString("");
       *(this->vasarloNeve) = vasarloNeve; 

       this->vasarloEmailje = new QString("");
       *(this->vasarloEmailje) = vasarloEmailje;

       this->cipoModellId  = cipoModellId;
    
      };

//Destruktor
    ~elemi_Vasarlas();

};
