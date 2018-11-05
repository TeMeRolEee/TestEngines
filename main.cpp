#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <memory>
#include "core.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("MoodEngine");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Based on its mood the engine result can be sometimes false, sometimes true");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption helpOption(QStringList() << "h" << "help", "Writing out the help");
    parser.addOption(helpOption);

    auto core = std::make_unique<Core>();





    return app.exec();
}