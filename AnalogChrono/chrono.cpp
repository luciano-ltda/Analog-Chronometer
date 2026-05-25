#include "chrono.h"

Chrono::Chrono(QObject *parent) : QObject(parent), q_milisseconds(0), isEnabled(false)
{
    q_Timer.setInterval(20); //resolução máxima de Atualização dos processos no Debian Trixie
    connect(&q_Timer, &QTimer::timeout, this, &Chrono::OnTimeout);
}

void Chrono::OnTimeout(){
    setSeconds(this->q_milisseconds + 1);
    emit timeElapsed();
}

QString Chrono::getTimer(){
    int mins = (q_milisseconds / 50) / 60;
    int secs = (q_milisseconds / 50) % 60;
    int mils = (q_milisseconds * 20) % 1000;

    QString FT = QString("%1:%2:%3").arg(mins, 2, 10, QChar('0')).arg(secs, 2, 10, QChar('0')).arg(mils, 3, 10, QChar('0'));

    return FT;
}

void Chrono::setSeconds(int seconds){
    if(seconds < 0){
        return;
    }else if(seconds == this->q_milisseconds){
        return;
    }else{
        this->q_milisseconds = seconds;
       emit timeElapsed();
    }
}


void Chrono::start(){
    if(!isEnabled){
        isEnabled = true;
        q_Timer.start();
        emit runChanged();
    }
}

void Chrono::stop(){
    if(isEnabled){
        isEnabled = false;
        q_Timer.stop();
        emit runChanged();
    }
}

void Chrono::reset(){
    if(isEnabled){
        this->stop();
    }
    if(q_milisseconds != 0){
        this->setSeconds(0);
    }
    emit runChanged();
}
