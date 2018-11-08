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

		for (const auto &fileName : fileNameList) {
			if (engine->getMood()) {
				printer->addResultScan(fileName, 0, "No threat detected");
			} else {
				printer->addResultScan(fileName, 1, "Blocked");
			}
		}

		return 0;
	}

	return 1;
}

int Core::scanFile(const QString &filePath) {
	return 1;
}
