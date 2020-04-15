#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include <QDebug>

#include "engine.h"

bool Engine::getMood() {
	bool mood;
	QRandomGenerator generator;

	auto seedNumber = static_cast<quint32>(QDateTime::currentMSecsSinceEpoch() + counter++);
	generator.seed(seedNumber);

	int moodNumber = generator.bounded(1, 9999999);

	mood = moodNumber % 2 == 0;

	return mood;
}
