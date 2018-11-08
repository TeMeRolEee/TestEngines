#pragma once

#include "engine.h"

class Core {

public:
    Core();

    ~Core();

	int folderScanner(const QString &directoryPath);

	int scanFile(const QString &filePath);

private:
    Engine *engine;
};


