#include <QtCore/QRandomGenerator>
#include <QtCore/QDateTime>
#include "engine.h"


Engine::Engine() {
    QRandomGenerator generator;
    auto seedNumber = static_cast<quint32>(QDateTime::currentMSecsSinceEpoch());
    generator.seed(seedNumber);

    int moodNumber = generator.bounded(1,9999999);

    mood = moodNumber % 2 == 0;
}
