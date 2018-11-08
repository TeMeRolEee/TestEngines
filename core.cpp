#include "core.h"

#include <QtCore/QDirIterator>
#include <QDebug>

#include "jsonprinter.h"


Core::Core() {
	engine = new Engine();
}

Core::~Core() {
	delete engine;
}

int Core::folderScanner(const QString &directoryPath) {

	if (!directoryPath.isEmpty()) {
		QDirIterator directoryIterator(directoryPath);
		QStringList fileNameList;

		if (!directoryIterator.hasNext()) {
			qDebug() << "No files in the directory to hash!";
			return 1;
		}

		auto *printer = new JsonPrinter();

		while (directoryIterator.hasNext()) {

			directoryIterator.next();
			if (QFileInfo(directoryIterator.filePath()).isFile()) {
				fileNameList.append(directoryIterator.fileName());
			}
		}

		for (int i = 0; i < fileNameList.size(); i++) {
			if (engine->getMood()) {
                printer->addScanResult(fileNameList.at(i), 0, "No threat detected");
			} else {
                printer->addScanResult(fileNameList.at(i), 1, "Blocked");
			}
		}

		printer->printResult();

		delete printer;

		return 0;
	}

	return 1;
}

int Core::scanFile(const QString &filePath) {
    auto *printer = new JsonPrinter();
    QFile qFile(filePath);

    if(!filePath.isEmpty() && qFile.exists()) {


        if (engine->getMood()) {
            printer->addScanResult(qFile.fileName(), 0, "No threat detected");
        } else {
            printer->addScanResult(qFile.fileName(), 1, "Blocked");
        }

        printer->printResult();

        delete printer;

        return 0;
    }

    printer->addScanResult(qFile.fileName(), -1, "File not found");

    printer->printResult();

	return 1;
}
