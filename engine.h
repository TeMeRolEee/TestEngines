#pragma once

#include <QtCore/QJsonObject>

class Engine {

public:
    Engine();

private:
    bool mood = false;

    QJsonObject result;
};


