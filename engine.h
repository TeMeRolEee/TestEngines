#pragma once

#include <QtCore/QJsonObject>

class Engine {

public:
    Engine();

    bool getMood();

private:
    bool mood = false;

    QJsonObject result;
};


