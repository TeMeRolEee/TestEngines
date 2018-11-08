#pragma once

#include <QtCore/QString>
#include <QtCore/QJsonObject>

class JsonPrinter {
public:
	JsonPrinter();

	~JsonPrinter();

	void addScanResult(const QString &filename, int result, const QString &description);

	void printResult();

private:
	QJsonObject *jsonObject;
	QJsonArray *jsonArray;
};


