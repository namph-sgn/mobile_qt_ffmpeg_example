import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2
import nam.example 1.0

Window{
    id: mainWindow
    objectName: "mainWindow"

    visible: true
    title: "QML for Android Example"
    width: 800
    height: 600

    ListView {
        id: view
        anchors.fill: parent
        model: DataEntryModel {}
        delegate: ListDelegate {
            width: ListView.view.width
            // construct a string based on the models proeprties
            text: 'hsv(' +
                  Number(model.hue).toFixed(2) + ',' +
                  Number(model.saturation).toFixed() + ',' +
                  Number(model.brightness).toFixed() + ')'
            // sets the font color of our custom delegates
            color: model.name

            onClicked: {
                // make this delegate the current item
                view.currentIndex = index
                view.focus = true
            }
            onRemove: {
                // remove the current entry from the model
                dynamic.remove(index)
            }
        }
        highlight: ListHighlight{}
    }





}
