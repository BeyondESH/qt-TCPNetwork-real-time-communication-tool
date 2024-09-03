#include "clientscombox.h"

#include <QMouseEvent>

ClientsCombox::ClientsCombox(QWidget * parent):QComboBox(parent)
{

}

void ClientsCombox::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        emit comboBoxClients_clicked();
    }
    QComboBox::mousePressEvent(e);
}
