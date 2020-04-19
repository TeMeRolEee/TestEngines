#include "interface.h"

#include <chrono>
#include <thread>
#include <iostream>

#include <QtCore/QJsonDocument>

#include "core.h"

QThread *thread = nullptr;
Core *core = nullptr;

bool init() {
	thread = new QThread();
	core = new Core();

	thread->moveToThread(core);
	thread->start();

	return thread->isRunning();
}

bool scanFile(const QString &filepath, QJsonObject *result) {
	if (core == nullptr) {
		return false;
	}

	bool *isDone = new bool();
	emit core->initiateScanFile_signal(filepath, result, isDone);

	/// 5 sec timout basically
	for (int i = 0; i < 500; ++i) {
		if (*isDone) {
			delete isDone;
			return true;
		} else {
			std::this_thread::sleep_for(std::chrono_literals::operator ""ms(10));
		}
	}

	delete isDone;

	return false;
}

void deInit() {
	if (thread != nullptr) {
		thread->quit();
		thread->wait();
	}

	delete thread;
	delete core;
}
