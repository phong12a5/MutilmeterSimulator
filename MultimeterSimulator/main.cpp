#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ModelData.h"
#include "AppDefine.h"
#include "DefineModel.h"
#include "App_Enum.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    ModelData* model = ModelData::getInstance();
    DefineModel * defineModel = DefineModel::getInstance();
    engine.rootContext()->setContextProperty("ModelData", model);
    engine.rootContext()->setContextProperty("Define", defineModel);
    qmlRegisterType<App_Enum>("App_Enum", 1, 0, "App_Enum");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
