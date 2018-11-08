#include <iostream>
#include <memory>

#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QDebug>

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

    QCommandLineOption scanOption(QStringList() << "s" << "scan", "Scan a specified file", "scan");
    parser.addOption(scanOption);

    QCommandLineOption folderOption(QStringList() << "f" << "folder",
                                    "Iterates through the given folder non-recursively and scans them.", "folder");
    parser.addOption(folderOption);

    parser.process(app);

    auto core = std::make_unique<Core>();

    if (parser.isSet(scanOption)) {
        return core->scanFile(parser.value(scanOption));
    } else if (parser.isSet(folderOption)) {
        return core->folderScanner(parser.value(folderOption));
    }

    parser.showHelp();
}