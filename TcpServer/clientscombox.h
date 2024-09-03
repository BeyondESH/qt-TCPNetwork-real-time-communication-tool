#ifndef CLIENTSCOMBOX_H
#define CLIENTSCOMBOX_H

#include <QComboBox>
#include <QWidget>

class ClientsCombox : public QComboBox
{
    Q_OBJECT
public:
    ClientsCombox(QWidget * parent=nullptr);
protected:
    void mousePressEvent(QMouseEvent * e) override;
signals:
    void comboBoxClients_clicked();
};

#endif // CLIENTSCOMBOX_H
