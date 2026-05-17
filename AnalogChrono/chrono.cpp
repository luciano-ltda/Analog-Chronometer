#include "chrono.h"



Chrono::Chrono(QObject *parent) : QObject(parent), q_seconds(0), isEnabled(false)
{
    q_Timer.setInterval(1000);
    connect(&q_Timer, &QTimer::timeout, this, &Chrono::OnTimeout);
}

void Chrono::OnTimeout(){
    setSeconds(this->q_seconds + 1);
    emit timeElapsed();
}

QString Chrono::getTimer(){
    int mins = q_seconds / 60;
    int secs = q_seconds % 60;

    QString FT = QString("%1:%2").arg(mins, 2, 10, QChar('0')).arg(secs, 2, 10, QChar('0'));

    return FT;
}

void Chrono::setSeconds(int seconds){
    if(seconds < 0){
        return;
    }else if(seconds == this->q_seconds){
        return;
    }else{
        this->q_seconds = seconds;
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
    if(q_seconds != 0){
        this->setSeconds(0);
    }
    emit runChanged();
}
