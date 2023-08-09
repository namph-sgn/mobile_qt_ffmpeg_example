#include <QtGui>
#include <QtQml>
#include "dataentrymodel/dataentrymodel.h"
#include <nx/build_info.h>

int main(int argc, char **argv) {  
  QGuiApplication app(argc, argv);

  qmlRegisterType<DataEntryModel>("nam.example", 1, 0, "DataEntryModel");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
