#include "firstmainwindow.h"

 FirstMainWindow::FirstMainWindow (QWidget *parent):
                           QMainWindow(parent)
{
   
   this->resize(1024, 768);
   this->setWindowTitle("FirstMainWindow");
  
//Menuk megadasa: Start:
   fileMenu=this->menuBar()->addMenu(tr("&fajl"));
   tablaMenu=this->menuBar()->addMenu(tr("&tablat_megjelenit")) ;
   rendezesMenu=this->menuBar()->addMenu(tr("&rendezes"));
//Menuk megadasa: vege:

// ACTION-ök megadasa KEZDET:

    //Fajl MENUben szereplo ACRION ök megadasa KEZDET:

     newContactAction = new QAction(tr("&uj bejegyzes"),this);
     newContactAction -> setStatusTip( tr("kere&ses nev alapján") );
     connect(newContactAction, SIGNAL(triggered()), this,SLOT(addNewContact() ) );
     fileMenu -> addAction(newContactAction);

      //Kilepes Action START:
     exitAction    =    new QAction(tr("&kilep"),this);
     exitAction    ->    setShortcut(tr("Ctrl+Q"));//gyorsbillentyű megadasa az actionhöz
     exitAction    ->    setStatusTip(tr("Alkalmazas bezarasa"));//ez jon fol a "status bar"-ban
     connect(exitAction,SIGNAL( triggered() ),this,SLOT( close() ));
     fileMenu->addAction(exitAction);
     //Programbol Kilepes Action VEGE:


     //Kereses Action START:
     showSearchAction= new QAction(tr("&Kereses"),this);
     showSearchAction-> setShortcut(QKeySequence::Find);
     showSearchAction-> setStatusTip(tr("&Keresés nev alapján"));
     connect(showSearchAction, SIGNAL( triggered() ) ,this, SLOT(  showSearch() ) );
     fileMenu->addAction(showSearchAction);

//FILE MENU megadasa VEGE:

//Tablak Beolvas, Kiir Actionok KEZDET:

   //maintable fajlbol betoltes KEZDETE:
     mainTablaBetoltesFajlbol_Action= new QAction(tr("&Toltsd be a mainTablat ebbol a fajlbol: '00_Data.txt' ") ,this);
     mainTablaBetoltesFajlbol_Action  -> setStatusTip( tr("MainTabla adatok kirrasa 00_data.txt be"));
     connect( mainTablaBetoltesFajlbol_Action , SIGNAL(triggered()), 
                         this,SLOT(mainTablaBetoltesFajlbol() ));
     tablaMenu->addAction( mainTablaBetoltesFajlbol_Action);
   //maintable fajlbol betoltes VEGE:
    
     //maintable fajlba kiirása KEZDETE:
     /*mainTablaKiirasFajlba_Action=new QAction(tr("Ird ki a maintablet a 00_data.txt- be") ,this);
     mainTablaKiirasFajlba_Action  -> setStatusTip( tr("adatok kiirasa a maintablet a 00_data.txt- be"));
     connect( mainTablaKiirasFajlba_Action , SIGNAL(triggered()), 
                       this,SLOT( mainTablaKiirasFajlba()) );
    tablaMenu->addAction(   mainTablaKiirasFajlba_Action);*/
    //maintable fajlba kiirása VEGE:

    //Cipoarak beolvasasa fájlbol KEZDET:
     cipoarakTablaBetoltesFajlbol_Action = 
              new QAction(tr("T&oltsd be a cipoarakat a cipoarak.txt fajlbol") ,this);
     cipoarakTablaBetoltesFajlbol_Action  
           -> setStatusTip( tr("cipoarak betoltese"));
     connect( cipoarakTablaBetoltesFajlbol_Action  , SIGNAL(triggered()),
              this,SLOT( cipoarakTablaBetoltesFajlbol()) );
     tablaMenu->addAction(   cipoarakTablaBetoltesFajlbol_Action );
    //Cipoarak beolvasasa fájlbol VEGE:     

      //Cipoarak kiirasa fájlba KEZDET:
     /*cipoarakTablaKiirasFajlba_Action =
              new QAction(tr("&Ird ki a cipoarakat a  cipoarak.txt be")  ,this);
     cipoarakTablaKiirasFajlba_Action 
                  -> setStatusTip( tr("Cipoaraktabla tartalmanak kiirasa a cipoarak.txt be"));
     connect(  cipoarakTablaKiirasFajlba_Action  , SIGNAL(triggered()),  
                         this,SLOT( cipoarakTablaKiirasFajlba())) ;
     tablaMenu->addAction( cipoarakTablaKiirasFajlba_Action );
    //Cipoarak kiirasa fájlba VEGE:  */

    //raktarkeszlet tablat fajlbol beolvas KEZDETE:
    raktarkeszletTablaBetoltesFajlbol_Action=new QAction(tr("Olvasd be a raktarkeszletet a table2_raktarkeszlet.txt-bol raktarkeszlettable-be") ,this);
    raktarkeszletTablaBetoltesFajlbol_Action  -> setStatusTip( tr("raktarkeszlet_tablat fajlbol beolvas "));
     connect( raktarkeszletTablaBetoltesFajlbol_Action , SIGNAL(triggered()),
                this,SLOT( raktarkeszletTablaBetoltesFajlbol()) );
      tablaMenu->addAction(  raktarkeszletTablaBetoltesFajlbol_Action);
    //maintable fajlba kiirása VEGE:   

    /*//raktarkeszlet_tablet fajlba kiir KEZDETE:
    raktarkeszletTablaKiirasFajlba_Action=new QAction(tr("Ird ki a raktarkeszletet a 02_raktarkeszlet.txt- be") ,this);
    raktarkeszletTablaKiirasFajlba_Action  -> setStatusTip( tr("Ird ki a 02_raktarkeszlet.txt- be a raktarKeszlet_tablat"));
    connect( raktarkeszletTablaKiirasFajlba_Action , SIGNAL(triggered()), 
                 this,SLOT( raktarkeszletTablaKiirasFajlba()) );
    tablaMenu->addAction(  raktarkeszletTablaKiirasFajlba_Action);*/
    //raktark tabla fajlba kiirása VEGE:  
 
 //Tablak Beolvas, Kiir Actionok VEGE:

    // Tablakat Rejt KEZDET:
    osszes_tablat_elrejt_Action = new QAction(tr("&Osszes tablat rejt") ,this);
    osszes_tablat_elrejt_Action -> setStatusTip( tr("foablakban elrejtem az osszes tablat"));
    connect( osszes_tablat_elrejt_Action , SIGNAL(triggered()), this,SLOT(  osszes_tablat_elrejt() ));
    tablaMenu->addAction(osszes_tablat_elrejt_Action);
     // Tablakat Rejt VEGE:

    //Nyers adatok betoltese MainTable be KEZD:
    /*nyers_adatsorokat_beolvas_fajlbol_Action= new QAction(tr("mainTable &feltoltese fajlbol"),this);
    nyers_adatsorokat_beolvas_fajlbol_Action-> setStatusTip(tr("&mainTable feloltese fajlbol"));
    connect(  nyers_adatsorokat_beolvas_fajlbol_Action, SIGNAL(triggered()), this,SLOT(   nyers_adatsorokat_beolvas() ) );
    tablaMenu->addAction(osszes_tablat_elrejt_Action);*/

    //Nyers adatok betoltese MainTable be VEGE



   //mainTabla Rendezes Menu QActionok feltoltesenek KEZDET:
   mainTabla_rendezd_vasnev_sz_Action = new QAction(tr("rendezd_mainTablat nev szerint!"),this);
   mainTabla_rendezd_vasnev_sz_Action -> setStatusTip( tr("Rendezd mainTablat nev szerint emelkedo sorrendbe") );
    connect(  mainTabla_rendezd_vasnev_sz_Action, SIGNAL(triggered()), this,SLOT(   mainTabla_rendezd_vasnev_sz())  );
     rendezesMenu -> addAction(mainTabla_rendezd_vasnev_sz_Action);

   mainTabla_rendezd_cipomeret_sz_Action = new QAction(tr("rendezd mainTablat cipomeret szerint"),this);
   mainTabla_rendezd_cipomeret_sz_Action  -> setStatusTip( tr("rendezd cipomeret szerint") );
   connect( mainTabla_rendezd_cipomeret_sz_Action, SIGNAL(triggered()), this,SLOT(  mainTabla_rendezd_cipoMeret_sz())  );
   rendezesMenu -> addAction(    mainTabla_rendezd_cipomeret_sz_Action);
   
   mainTabla_rendezd_vasemail_sz_Action = new QAction(tr("rendezd mainTablat vasemailcim szerint emelkedo sorrendbe!"),this);
   mainTabla_rendezd_vasemail_sz_Action  -> setStatusTip( tr("rendezes email szerint emelkedo sorrendbe") );
   connect(  mainTabla_rendezd_vasemail_sz_Action , SIGNAL(triggered()), this,SLOT(mainTabla_rendezd_vasemailcim_sz())  );
   rendezesMenu -> addAction(mainTabla_rendezd_vasemail_sz_Action );

   mainTabla_rendezd_cipomodell_sz_Action = new QAction(tr("rendezd mainTablat cipomarka szerint"),this);
   mainTabla_rendezd_cipomodell_sz_Action  -> setStatusTip( tr("rendezd cipomodell szerint") );
   connect(   mainTabla_rendezd_cipomodell_sz_Action, SIGNAL(triggered()),
                       this,SLOT( mainTabla_rendezd_cipomodellId_sz() )  );
   rendezesMenu -> addAction(   mainTabla_rendezd_cipomodell_sz_Action);

   //RENDEZES MENU QActionok feltoltesenek VEGE:   



//ACTIONok megadasa VEGE:



//TABLEok feltoltesenek KEZDESE:

    //Tabla 1 mainTable  memfoglalasa es oszlopok def KEZDET:
    this     ->    table1_main = new QTableWidget();
    table1_main    ->    setSelectionMode(QAbstractItemView::SingleSelection);
    table1_main    ->    setColumnCount(6);
    table1_main    ->  setRowCount(0);   
    this    ->     setCentralWidget(table1_main);
    //table1 oszlopainak a neveit egy QStringList tip. objektumban tárolom.
    QStringList headerlabels1;
    headerlabels1 << "vasarlo_id" <<"vasNev" << "vasEmail" << "Cipomeret" <<
                      "CipomodNev" << "dbszam" << "\n";
    table1_main->setHorizontalHeaderLabels(headerlabels1);
    connect (table1_main , SIGNAL(itemSelectionChanged()),
               this,SLOT(updateStatusText( )) );   //TABLE mainTable VEGE:
    //TABLE mainTable memfoglalasa  es oszlopok def VEGE:

    //Tabla 2 cipoarak lefoglalasa es oszlopok def KEZDET:
    this  -> table2_cipoarak = new QTableWidget();
    table2_cipoarak ->  setSelectionMode(QAbstractItemView::SingleSelection);
    table2_cipoarak->  setColumnCount(3);
    table2_cipoarak->  setRowCount(0);

    QStringList headerlabels2 ;
    headerlabels2 <<"cipomodellid" << "cipomodellNev" << "CipomodellAr"<< "\n";
    table2_cipoarak->setHorizontalHeaderLabels(headerlabels2);

    connect (table2_cipoarak , SIGNAL(itemSelectionChanged()),
              this,SLOT(updateStatusText( )) );
    //TABLE cipoArak lefoglalasa es oszlopok def START:


    //TABLE raktarkeszlet  peldanyositasa

    //Ezt majd folyamatosan kell feltolteni egyenkent adni hozza a sorokat
    this                    -> table3_raktarkeszlet=new QTableWidget();
    table3_raktarkeszlet    ->  setSelectionMode(QAbstractItemView::SingleSelection);
    this    ->     setCentralWidget(table3_raktarkeszlet);
    table3_raktarkeszlet    ->  setColumnCount(6);//??
    QStringList headerlabels3;
    headerlabels3 << "raktarkeszl" << "2" << "3"
                    << "4 "<< "5"  << "6" << "\n";
    table3_raktarkeszlet->setHorizontalHeaderLabels(headerlabels3);
    connect ( table3_raktarkeszlet ,  SIGNAL(itemSelectionChanged()),
            this,SLOT(updateStatusText( )) );
    //TABLE raktarkeszlet  peldanysa es oszlopok def VEGE:

//TABLEok feltoltesenek VEGE:

//TABLAKAT MEGJELENITO Actionok megadasa KEZDET:
    // MASIK TABLA megj: Actionok VEGE:
    mainTablaMutat_Action  = new QAction(tr("Megjelenit &mainTable-t"),this);
    mainTablaMutat_Action  -> setStatusTip( tr("tabla1 megjelenitese") );
    connect(   mainTablaMutat_Action  , SIGNAL(triggered()), this,SLOT(tablat_valts_1() ) );
    tablaMenu -> addAction( mainTablaMutat_Action ) ;

 
    cipoarakTablaMutat_Action  = new QAction(tr("Megjelenit &cipoaraktTable-t"),this);
    cipoarakTablaMutat_Action -> setStatusTip( tr("tabla2 megjelenitese") );
    connect(  cipoarakTablaMutat_Action , SIGNAL(triggered()), this,SLOT(tablat_valts_2()) );
    tablaMenu -> addAction( cipoarakTablaMutat_Action);

    raktarkeszletTablaMutat_Action  = new QAction(tr("Megjelenit &raktarkeszletTable-t"),this);
    raktarkeszletTablaMutat_Action -> setStatusTip( tr("tabla3 megjelenitese") );
    connect( raktarkeszletTablaMutat_Action , SIGNAL(triggered()), this,SLOT(tablat_valts_3() ) );
    tablaMenu -> addAction(raktarkeszletTablaMutat_Action );
 
    // MASIK TABLA megj: Actionok VEGE:
//Tovabbi Actionok VEGE:
};


 
void FirstMainWindow::osszes_tablat_elrejt(){
//Ez a fuggveny elrejti a tablakat
     //table1_main->hide();
     //table1_main->setVisible(false);

    table2_cipoarak->hide();
    table2_cipoarak->setVisible(false);  

    //table3_raktarkeszlet->hide();
    //table3_raktarkeszlet->setVisible(false);

    //this->centralWidget()->adjustSize();
  
} ;


 void FirstMainWindow::tablat_valts_1(){
        this   ->    setCentralWidget(table1_main);
        table1_main->setVisible(true);
        table1_main->show();
      }
 
  void FirstMainWindow::tablat_valts_2() {    
        this   -> setCentralWidget(table2_cipoarak);
        table2_cipoarak->setVisible(true);
        table2_cipoarak->show();

 }

 void FirstMainWindow::tablat_valts_3(){

         this   ->  setCentralWidget(table3_raktarkeszlet);
         table3_raktarkeszlet->setVisible(true);
         table3_raktarkeszlet->show();
      }

 void FirstMainWindow::showSearch(){ 

      if(! searchDialog1->isVisible() )
            {
                this->searchDialog1->show();
            }
                                      
 };


//RENDEZEZES: MAINTABLE rendezese KEZD: 
void FirstMainWindow::  mainTabla_rendezd_vasnev_sz(){
   table1_main->sortByColumn(0,Qt::AscendingOrder);
}
void FirstMainWindow::  mainTabla_rendezd_vasemailcim_sz(){
   table1_main->sortByColumn(1,Qt::AscendingOrder);
}
void FirstMainWindow::   mainTabla_rendezd_cipoMeret_sz(){
   table1_main->sortByColumn(2,Qt::AscendingOrder);
}
void FirstMainWindow::mainTabla_rendezd_cipomodellId_sz(){
   table1_main->sortByColumn(3,Qt::AscendingOrder);
}
//RENDEZEZES: MAINTABLE VEGE: 


//RENDEZEZES: TABLE CIPOARAK KEZD: 
void FirstMainWindow::cipoarakTabla_rendezd_cipoModellId_szerint(){
     table2_cipoarak->sortByColumn(0,Qt::AscendingOrder);
}
void FirstMainWindow::cipoarakTabla_rendezd_cipoModellNev_szerint(){
table2_cipoarak->sortByColumn(2,Qt::AscendingOrder);
}

void FirstMainWindow::cipoarakTabla_rendezd_cipoAr_szerint(){
table2_cipoarak->sortByColumn(1,Qt::AscendingOrder);
}

//RENDEZEZES:  CIPOARAKTABLE VEGE: 


// RENDEZES: RAKTARKESZLET  KEZD:
void FirstMainWindow::raktarkeszletTabla_rendezd_cipoId_szerint(){
   table1_main->sortByColumn(0,Qt::AscendingOrder);
}

// RENDEZES: RAKTARKESZLET  VEGE:




// BETOLVASAS CIPOARAKAT 01_cipoarak.txt bol
int FirstMainWindow::cipoarakTablaBetoltesFajlbol(){
 
    int vanhiba=0;

    std::ifstream file_cipoarak;
    //Ez az objektum jelenti a fajlt 

    file_cipoarak.open("Data//01_cipoarak.txt");
    if(file_cipoarak.fail()) {vanhiba=1; return -1;}

    if(table2_cipoarak) delete table2_cipoarak;
    table2_cipoarak = new QTableWidget();

    std::string line1("");
   
   if(vanhiba ==0)
   {   
      std::getline(file_cipoarak, line1);
      std::getline(file_cipoarak, line1);
      std::getline(file_cipoarak, line1);



      std::string cipomodellId_tmp="";
      std::string cipomodellNev_tmp="";
      std::string cipomodellAr_tmp= "";
    
      const std::string delimiter=" "; 
        
      QString cipomodellId2="";
      QString cipomodellNev2="";
      QString cipomodellAr2="";

      int currentRowsNbrMax=table2_cipoarak->rowCount();
      
      ;
    
     for (int currentRowsNbr=0; currentRowsNbr < currentRowsNbrMax; currentRowsNbr++)
          {
            std::getline(file_cipoarak, line1);
             if (file_cipoarak.eof() ) {  vanhiba=0; break;}
             else

            {
              if(file_cipoarak.fail()){vanhiba=1; break; }
           
             vanhiba=0;
        //atmeneti stringek a beolvasashoz
   

          cipomodellId_tmp=line1.substr(0,line1.find(delimiter));
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
          cipomodellNev_tmp=line1.substr(0,(line1.find(delimiter)));
          line1.erase(0,(line1.find(delimiter))+(delimiter.length()));
          cipomodellAr_tmp=line1;

          //atmasolom a Qstringekbe az ertekeket.
         
          cipomodellId2    =  QString::fromStdString(cipomodellId_tmp);
          cipomodellNev2   =  QString::fromStdString(cipomodellNev_tmp);
          cipomodellAr2    =  QString::fromStdString(cipomodellAr_tmp);
         //nem kell c tipusu stringbe konvertalni
       

           table2_cipoarak->insertRow( table2_cipoarak->rowCount() );

          //table_cipoarak feltoltese KEZD:
          QTableWidgetItem * newCipomodellIdItem2=new QTableWidgetItem(cipomodellId2);
        
           table2_cipoarak->setItem(0,table2_cipoarak->rowCount()-1,newCipomodellIdItem2);

          QTableWidgetItem * newCipomodellNevItem2=new QTableWidgetItem(cipomodellNev2);
      
           table2_cipoarak->setItem(1,table2_cipoarak->rowCount()-1,newCipomodellNevItem2);
 
          QTableWidgetItem * newCipomodellArItem2=new QTableWidgetItem(cipomodellAr2);
 
           table2_cipoarak->setItem(2,table2_cipoarak->rowCount()-1,newCipomodellArItem2);
   
          //table_cipoarak feltoltese VEGE:
        }
      }
file_cipoarak.close();

if (! (vanhiba > 0)) 
       {file_cipoarak.close() ;return -1;} 
else {
         file_cipoarak.close();
          return -1;}
return -1;
}

};

int FirstMainWindow::cipoarakTablaKiirasFajlba(){
   //ez a fuggveny kiirja a CipoarakTable-t cipoarak.txt fajlba fajlba
   std::fstream file_cipoarak_kim;//Ez az objektum jelenti a fajlt

   file_cipoarak_kim.open("Data//01_cipoarak.txt");  //alapbol out
       

   int currentRowsNumber=table2_cipoarak->rowCount();
   int i;
   for(i=0;i<currentRowsNumber;i++){
      file_cipoarak_kim << (table2_cipoarak->itemAt(i,0)->text()).toStdString();
       if(!file_cipoarak_kim.is_open()) return -1;

        file_cipoarak_kim << " ";
        file_cipoarak_kim << (table2_cipoarak->itemAt(i,1)->text()).toStdString();
       if(!file_cipoarak_kim.is_open()) return -1;
        file_cipoarak_kim << " ";
        file_cipoarak_kim << (table2_cipoarak->itemAt(i,2)->text().toStdString());
       if(! file_cipoarak_kim.is_open()) return -1;
       file_cipoarak_kim << "\n";
       if(! file_cipoarak_kim.is_open()){ break ;}
       currentRowsNumber++;
   }

  //irasi puffer kiuritese:
   file_cipoarak_kim.flush() ;
  //fajl lezarasa:
   file_cipoarak_kim.close();
   return 0;
};



//raktarkeszlet beolvasasa fajlbol KEZDET:
int FirstMainWindow::raktarkeszletTablaBetoltesFajlbol(){
return 0;
};
//raktarkeszlet beolvasasa fajlbol VEGE:

//raktarkeszlet tabla kiirasa KEZDET:
int FirstMainWindow::raktarkeszletTablaKiirasFajlba(){
return 0;
};
//raktarkeszlet tabla kiirasa VEGE

int FirstMainWindow::uj_cipotipus_felvetele(QString cipoModellNev, QString cipoId,QString cipoAr){
 
         int currentRowsNmbr=table2_cipoarak->rowCount();
         
         table2_cipoarak->setRowCount(currentRowsNmbr+1);
         table2_cipoarak->insertRow(currentRowsNmbr);

         QTableWidgetItem *newCipoId2Item=new QTableWidgetItem(cipoId);   
         QTableWidgetItem *newCipoModellNev2Item=new QTableWidgetItem( cipoModellNev);
         QTableWidgetItem *newCipoAr2Item = new QTableWidgetItem(cipoAr);

	 table2_cipoarak->setItem(currentRowsNmbr,0,newCipoId2Item);
         table2_cipoarak->setItem(currentRowsNmbr,1,newCipoModellNev2Item);
         table2_cipoarak->setItem(currentRowsNmbr,2,newCipoAr2Item);
         currentRowsNmbr++;
return 0;
}




//felkesz függvények kezd:


//felkesz fuggvenyek vege:

int  FirstMainWindow::mainTablaBetoltesFajlbol(){
return 1;
}


int FirstMainWindow::mainTablaKiirasFajlba(){
  return 1;
}



elemi_Vasarlas::~elemi_Vasarlas(){
  delete vasarloNeve;
  delete vasarloEmailje;
}

int FirstMainWindow:: nyers_adatsorokat_beolvas(){
    //file_data.txt feldolgozasa KEZD:
    if(table1_main) delete table1_main;
    table1_main=new QTableWidget();
    int hibavan=0;
    std::string line1;

    std::ifstream file1;

   
     file1.open("00_data.txt");
     if(file1.fail()) {hibavan=1; return -1;}
         //elso 5 sort beolvasom és figyelmen kivul hagyom
     if (file1.is_open())   {std::getline(file1, line1,'\n');}
 
     if (file1.is_open())  {std::getline(file1, line1,'\n');}

     if (file1.is_open()) {std::getline(file1, line1,'\n');}

     if (file1.is_open()) {std::getline(file1, line1,'\n');}

     if (file1.is_open()) {std::getline(file1, line1,'\n');}


    if (file1.is_open())
    {
       
        while (1)
           {
            if (file1.is_open()){ std::getline(file1, line1,'\n'); }
            if(file1.fail()) {hibavan=1; return -1;}

            std::istringstream iss1(line1);

            std::string vasarloId_tmp;
            std::string vasarloNev_tmp;
            std::string vasarloEmail_tmp;
            std::string cipoMeret_tmp;
            std::string cipoModellId_tmp;
            std::string cipoModellNev_tmp;
            std::string cipoDbSzam_tmp;

            if ( !(iss1 >> vasarloId_tmp)     )        { break; return -1;}   // error
            if ( !(iss1 >> vasarloNev_tmp)      )       { break; return -1;}   // error
            if ( !(iss1 >> vasarloEmail_tmp)    )       { break; return -1;}   // error
            if ( !(iss1 >> cipoMeret_tmp)      )        { break; return -1;}  // error
            if ( !(iss1 >> cipoModellId_tmp)  )         { break; return -1;}  // error
            if ( !(iss1 >> cipoModellNev_tmp) )         { break; return -1;}  // error
            if ( !(iss1 >> cipoDbSzam_tmp)    )         { break;return -1; }  // error


            QString vasarloId2("");
            QString vasarloNev2("");
            QString vasarloEmail2("");
            QString cipoMeret2("");
            QString cipoModellId2("");
            QString cipoModellNev2("");
            QString cipoDbSzam2=("");

            //atmasolom a Qstringekbe az ertekeket.
            vasarloId2       =        QString::fromStdString( vasarloId_tmp.c_str() );
            vasarloNev2        =    QString::fromStdString( vasarloNev_tmp.c_str() );
            vasarloEmail2      =    QString::fromStdString( vasarloEmail_tmp.c_str() );
            cipoMeret2         =    QString::fromStdString( cipoMeret_tmp.c_str() );
            cipoModellId2      =    QString::fromStdString( cipoModellId_tmp.c_str() );
            cipoModellNev2     =    QString::fromStdString( cipoModellNev_tmp.c_str());
            cipoDbSzam2        =     QString::fromStdString(cipoDbSzam_tmp.c_str());



            //beolvasott adatok atmasolasa a Tablaba:
            int currentRowsNbr=table1_main->rowCount();
            table1_main->insertRow(currentRowsNbr);

            QTableWidgetItem*  newVasIdItem=new QTableWidgetItem(vasarloId2);
            table1_main->setItem(currentRowsNbr,0,newVasIdItem);
            QTableWidgetItem*  newNameItem=new QTableWidgetItem(vasarloNev2);
            table1_main->setItem(currentRowsNbr,1,newNameItem);
            QTableWidgetItem * newEmailItem=new QTableWidgetItem(vasarloEmail2);
            table1_main->setItem(currentRowsNbr,2,newEmailItem);
            QTableWidgetItem * newCipomItem=new QTableWidgetItem(cipoMeret2);
            table1_main->setItem(currentRowsNbr,3,newCipomItem);
            QTableWidgetItem * newModellNameItem=new QTableWidgetItem(cipoModellNev2);
            table1_main->setItem(currentRowsNbr,4,newModellNameItem);
            QTableWidgetItem * newDbszamItem=new QTableWidgetItem(cipoDbSzam2);
            table1_main->setItem(currentRowsNbr,5,newDbszamItem);
            QTableWidgetItem * newModellIdItem=new QTableWidgetItem(cipoModellNev2);
            table1_main->setItem(currentRowsNbr,6,newModellIdItem);

            if(file1.fail()) {hibavan=1; return -1;}

            if( file1.eof() ) break;
           }

    }
    
    file1.close();
    if(hibavan) return -1;

    return 1;
};



void FirstMainWindow::adatokat_feldolgoz_fromMainTable_toMainTableB(){
    int hibavan=0; 
    if(hibavan) return;
    else return ;

}



/*void FirstMainWindow::addNewContact(){

//eloszor leteznie kell a main table nek hogy hozza adhassunk egy nevet
     NewContactWindow  *newContactDialog = new NewContactWindow(this);

     if(newContactDialog->exec()==QDialog::Accepted)
     {
         int currentRowsNbr=table1_main->rowCount();
       //  table1_main->setRowCount(currentRowsNbr+1);

         table1_main->insertRow(currentRowsNbr);
         QTableWidgetItem*  newNameItem=new QTableWidgetItem(newContactDialog->getVasId());
         table1_main->setItem(currentRowsNbr,0,newNameItem);
         QTableWidgetItem*  newVasarloIdItem=new QTableWidgetItem(newContactDialog->getName());
         table1_main->setItem(currentRowsNbr,1,newVasarloIdItem);
         QTableWidgetItem * newEmailItem=new QTableWidgetItem(newContactDialog->getEmail());
         table1_main->setItem(currentRowsNbr,2,newEmailItem);
         QTableWidgetItem * newCipomItem=new QTableWidgetItem(newContactDialog->getCipoMeret());
         table1_main->setItem(currentRowsNbr,3,newCipomItem);
         QTableWidgetItem * newModellNevItem=new QTableWidgetItem(newContactDialog->getModellNev());
         table1_main->setItem(currentRowsNbr,4,newModellNevItem);
         QTableWidgetItem * newDbszamItem=new QTableWidgetItem(newContactDialog->getDbSzam());
         table1_main->setItem(currentRowsNbr,5,newDbszamItem);
     }
     delete newContactDialog;

};*/

void FirstMainWindow::updateStatusText(){
    QList<QTableWidgetItem*> selectedItems = table1_main -> selectedItems();

    if(selectedItems.length()  > 0) 
     {
        this->statusBar()->showMessage(        "Name: " %
         table1_main->item(selectedItems.first()->row(), 0)->text()      );
     
     }
};

void FirstMainWindow::closeEvent(QCloseEvent* event)
{
     msg.setWindowTitle("Kilepes");
     msg.setText("Tenyleg Kilepes?");
     msg.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

    if(msg.exec()==QMessageBox::Yes)
              {event->accept();}
    else event->ignore();
    return;
};

