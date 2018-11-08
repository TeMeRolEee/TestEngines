#include "jsonprinter.h"

#include <iostream>

#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QFileInfo>

JsonPrinter::JsonPrinter() {
	jsonObject = new QJsonObject();
}

JsonPrinter::~JsonPrinter() {
	delete jsonObject;
}

void JsonPrinter::addResultScan(const QString &filename, int result, const QString &description) {
	QFile file(filename);
	QFileInfo fileInfo(file.fileName());

	QJsonArray resultArray;
	QJsonObject newResult;

	newResult.insert("filename", fileInfo.fileName());
	newResult.insert("verdict", result);
	newResult.insert("description", description);

	resultArray.push_back(newResult);

	jsonObject->insert("scan_result", resultArray);
}

void JsonPrinter::printResult() {
	std::cout << QJsonDocument(*jsonObject).toJson().toStdString();
}



