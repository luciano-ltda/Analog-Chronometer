import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import CustomChronometer 1.0

Window {
    id: mainW
    width: 640
    height: 640

    visible: true
    title: qsTr("Analog Chronometer - Test Project of Luciano")

    Chrono{
        id: timer

    }

//consistencia
Rectangle{
width: parent.width
height: parent.height
color:"#2e2e2e"
gradient: Gradient{
    GradientStop {
        position: 0.0
        color: "black" }
    GradientStop {
        position: 0.7
        color: "#2e2e2e" }
}


    Rectangle{

        id: hexLabel
        width: conatainment.width
        height: parent.height * 0.2
        color: "#9e9e9e"

        anchors.centerIn: parent
        anchors.verticalCenterOffset: parent.height * 0.37

        z: 2

        Text {
            id: name
            text: qsTr(timer.q_Timer)
            font.pixelSize: parent.height / 3
            anchors.centerIn: parent
        }
    }

    Image {
            id: prologo
            width: parent.width
            height: parent.height
            fillMode: Image.PreserveAspectFit
            source: "qrc:/img/logo_provant.png"
            z: 1
    }

    Rectangle{
        id: conatainment
        width: Math.min(mainW.width, mainW.height) * 0.6
        height: width
        radius: mainW.height * 0.8

        color: "#dcdcdc"

        anchors.verticalCenterOffset: - parent.height / 6
        anchors.centerIn: parent
        z: 2

        Image{
            id: chronobase
            width: parent.width
            height: parent.height
            source: "qrc:/img/base.png"

            fillMode: Image.PreserveAspectFit

            Rectangle{
                id: pointer
                width: 5
                height: parent.parent.width * 0.3
                radius: 10

                color: "#4b4b4b"
                border.color: "black"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.verticalCenter

                transformOrigin: Item.Bottom
                rotation: timer.q_seconds * 6
                }
            }

        Rectangle{
            id: buttonTray
            width: conatainment.width
            height: parent.height * 0.2
            radius: 5

            color: "#4f4f4f"
            border.color: "black"

            anchors.top: parent.bottom
            anchors.verticalCenterOffset: 150

            Row{
                anchors.centerIn: parent
                spacing: parent.height * 0.5

                Button{
                id: startstop
                width: buttonTray.width / 4
                height: buttonTray.height / 2

                anchors.verticalCenter: parent.verticalCenter

                text: timer.running ? "Stop" : "Start"
                font.pixelSize: height / 2

                onClicked: { //logica do clique
                        if (timer.running){
                            timer.stop();
                        }else{
                            timer.start();
                        }
                    }

                }

                Button{
                id: reset
                width: buttonTray.width / 4
                height: buttonTray.height / 2

                anchors.verticalCenter: parent.verticalCenter

                text: "Reset"
                font.pixelSize: height / 2

                onClicked: timer.reset();
                }

            }
        }
    }
}}
