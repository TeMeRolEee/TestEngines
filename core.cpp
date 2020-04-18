#include "core.h"

#include <QtCore/QDirIterator>
#include <QDebug>

#include "jsonprinter.h"


Core::Core() {
	engine = new Engine();
	connect(this, &Core::finished, this, &Core::deleteLater);
	connect(this, &Core::initiateScanFile_signal, this, &Core::scanFile_slot, Qt::QueuedConnection);
	connect(this, &Core::initiateFolderScan_signal, this, &Core::folderScanner_slot, Qt::QueuedConnection);
}

Core::~Core() {
	delete engine;
}

int Core::folderScanner_slot(const QString &directoryPath, QJsonObject *result, bool *isDone) {

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

void Core::scanFile_slot(const QString &filePath, QJsonObject *result, bool *isDone) {
	auto *printer = new JsonPrinter();
	QFile qFile(filePath);

	if (!filePath.isEmpty() && qFile.exists()) {

		if (engine->getMood()) {
			printer->addScanResult(qFile.fileName(), 0, "No threat detected");
		} else {
			printer->addScanResult(qFile.fileName(), 1, "Blocked");
		}

	} else {
		printer->addScanResult(qFile.fileName(), -1, "File not found");
	}

	result = new QJsonObject(printer->getResultObject());
	delete printer;

	*isDone = true;
}
