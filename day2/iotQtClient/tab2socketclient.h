#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include "socketclient.h"

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();
    SocketClient * pSocketClient;

private:
    Ui::Tab2SocketClient *ui;
//    SocketClient * pSocketClient;

private slots:
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);
    void slotSocketSendData();
    //void slotSocketSendData(QString);

signals:
    void sigLedWrite(int);
};

#endif // TAB2SOCKETCLIENT_H
