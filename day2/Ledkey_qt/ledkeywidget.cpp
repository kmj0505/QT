#include "ledkeywidget.h"
#include "ui_ledkeywidget.h"

LedkeyWidget::LedkeyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LedkeyWidget)
{
    ui->setupUi(this);
    pKeyled = new KeyLed(this);
    pQTimer = new QTimer(this);
    connect(pKeyled, SIGNAL(updateKeydataSig(int)), this, SLOT(slotKeyCheckBoxUpdate(int)));
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(slotSetValueDial()));
    connect(ui->pPBtimerStart, SIGNAL(clicked(bool)), this, SLOT(slotTimerStart(bool)));
    connect(ui->pCBtimervalue, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotTimerValueChange(QString)));
    connect(ui->pDialLed, SIGNAL(valueChanged(int)), pKeyled, SLOT(writeLedData(int)));
    connect(ui->pDialLed, SIGNAL(valueChanged(int)), ui->pProgressBarLed, SLOT(setValue(int)));
    connect(ui->pPBappQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void LedkeyWidget::slotKeyCheckBoxUpdate(int key)
{
    static int lcdData = 0;
    lcdData ^= (0x01 << (key-1));
    ui->pLcdNumberKey->display(lcdData);
    if(key == 1){
        if(ui->pCBkey1->isChecked())
            ui->pCBkey1->setChecked(false);     //pCBkey1체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey1->setChecked(true);
    }else if(key == 2){
        if(ui->pCBkey2->isChecked())
            ui->pCBkey2->setChecked(false);     //pCBkey2체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey2->setChecked(true);
    }else if(key == 3){
        if(ui->pCBkey3->isChecked())
            ui->pCBkey3->setChecked(false);     //pCBkey3체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey3->setChecked(true);
    }else if(key == 4){
        if(ui->pCBkey4->isChecked())
            ui->pCBkey4->setChecked(false);     //pCBkey4체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey4->setChecked(true);
    }else if(key == 5){
        if(ui->pCBkey5->isChecked())
            ui->pCBkey5->setChecked(false);     //pCBkey5체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey5->setChecked(true);
    }else if(key == 6){
        if(ui->pCBkey6->isChecked())
            ui->pCBkey6->setChecked(false);     //pCBkey6체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey6->setChecked(true);
    }else if(key == 7){
        if(ui->pCBkey7->isChecked())
            ui->pCBkey7->setChecked(false);     //pCBkey7체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey7->setChecked(true);
    }else if(key == 8){
        if(ui->pCBkey8->isChecked())
            ui->pCBkey8->setChecked(false);     //pCBkey8체크박스에 체크가 되어있으면 체크를 해제한다
        else
            ui->pCBkey8->setChecked(true);
    }
}

void LedkeyWidget::slotTimerValueChange(QString strValue)
{
    if(pQTimer->isActive()) {
        pQTimer->stop();
        pQTimer->start(strValue.toInt());
    }
}

void LedkeyWidget::slotSetValueDial()
{
    int value = ui->pDialLed->value();
    if(value >= ui->pDialLed->maximum())
        value = 0;
    else
        value++;
    ui->pDialLed->setValue(value);
}

void LedkeyWidget::slotTimerStart(bool check)
{
    if(check) {
        QString strValue = ui->pCBtimervalue->currentText();        //Timer숫자를 string으로 가져옴
        int timerValue = strValue.toInt();      //string -> int
        pQTimer->start(timerValue);
        ui->pPBtimerStart->setText("Timer Stop");
    } else {
        pQTimer->stop();
        ui->pPBtimerStart->setText("Timer Start");
    }
}

LedkeyWidget::~LedkeyWidget()
{
    delete ui;
}

