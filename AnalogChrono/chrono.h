#ifndef CHRONO_H
#define CHRONO_H

#include <QObject>
#include <QTimer>
#include <QString>

class Chrono : public QObject{

    Q_OBJECT
    Q_PROPERTY(int     q_milisseconds READ getMilisseconds WRITE setSeconds NOTIFY timeElapsed   );
    Q_PROPERTY(QString q_Timer        READ getTimer                         NOTIFY timeElapsed   );
    Q_PROPERTY(bool    running        READ isRunning                        NOTIFY runChanged    );


private:
    int    q_milisseconds;
    bool   isEnabled;
    QTimer q_Timer;

public:
    explicit Chrono(QObject *parent = nullptr);

    QString getTimer();
    int getMilisseconds() const { return q_milisseconds; }
    bool isRunning() const { return isEnabled; }

/*===========================================================================================*/

private slots:
    void OnTimeout();

public slots:

    void setSeconds(int seconds);

    void start();
    void stop() ;
    void reset();

/*============================================================================================*/

signals:

    void timeElapsed();
    void runChanged() ;
};

#endif // CHRONO_H
