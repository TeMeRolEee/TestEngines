#include "jsonprinter.h"

#include <iostream>

#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QFileInfo>
#include <QDebug>
#include <thread>

JsonPrinter::JsonPrinter() {
	jsonObject = new QJsonObject();
	jsonArray = new QJsonArray();
}

JsonPrinter::~JsonPrinter() {
	delete jsonObject;
	delete jsonArray;
}

void JsonPrinter::addScanResult(const QString &filename, int result, const QString &description) {
	QFile file(filename);
	QFileInfo fileInfo(file.fileName());

	auto *newResult = new QJsonObject;

	newResult->insert("filename", fileInfo.fileName());
	newResult->insert("verdict", result);
	newResult->insert("description", description);

	jsonArray->push_back(*newResult);
}

void JsonPrinter::printResult() {
	jsonObject->insert("scan_result", *jsonArray);
	std::cout << QJsonDocument(*jsonObject).toJson(QJsonDocument::Compact).toStdString();
	//std::this_thread::sleep_for(std::chrono_literals::operator ""s(2));
}

QJsonObject JsonPrinter::getResultObject() {
	if (!jsonObject->isEmpty()) {
		return *jsonObject;
	}
	return QJsonObject();
}



