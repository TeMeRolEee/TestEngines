#include <iostream>
#include <memory>

#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QDebug>
#include <thread>

#include "core.h"


int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("MoodEngine");
	QCoreApplication::setApplicationVersion("1.0");

	QCommandLineParser parser;
	parser.setApplicationDescription("Based on its mood the engine result can be sometimes false, sometimes true");
	parser.addHelpOption();
	parser.addVersionOption();

	QCommandLineOption scanOption(QStringList() << "s" << "scan", "Scan a specified file", "scan");
	parser.addOption(scanOption);

	QCommandLineOption folderOption(QStringList() << "f" << "folder",
									"Iterates through the given folder non-recursively and scans them.", "folder");
	parser.addOption(folderOption);

	parser.process(app);

	auto core = std::make_unique<Core>();

	//std::this_thread::sleep_for(std::chrono_literals::operator ""s(2));

	if (parser.isSet(scanOption)) {
		return core->scanFile(parser.value(scanOption));
	} else if (parser.isSet(folderOption)) {
		return core->folderScanner(parser.value(folderOption));
	}

	//std::this_thread::sleep_for(std::chrono_literals::operator ""s(2));

	parser.showHelp();
}
