

#include "searchdlg.h"

SearchDlg::SearchDlg(QWidget * parent): QDialog(parent){
 
   layout   =   new QHBoxLayout();
   this     ->  setLayout(layout);
   txtExpression = new QLineEdit ();
   layout->addWidget(txtExpression);
   btnSearch= new QPushButton(tr("Keress"));
   layout->addWidget(btnSearch);
   connect(btnSearch,SIGNAL(clicked()),this,SLOT(search()));
  }

void SearchDlg::search(){
    emit searchInvoked( txtExpression->text() );
}
