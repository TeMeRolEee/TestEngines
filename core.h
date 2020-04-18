#pragma once

#include <QtCore/QThread>
#include "engine.h"

class Core : public QThread {
Q_OBJECT

public:
	Core();

	~Core() override;

private:
	Engine *engine;

public slots:

	int folderScanner_slot(const QString &directoryPath, QJsonObject *result, bool *isDone);

	void scanFile_slot(const QString &filePath, QJsonObject *result, bool *isDone);

signals:

	void initiateScanFile_signal(const QString &filePath, QJsonObject *result, bool *isDone);

	void initiateFolderScan_signal(const QString &directoryPath, QJsonObject *result, bool *isDone);
};
