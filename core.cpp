#include "core.h"


Core::Core() {
    engine = new Engine();
}

Core::~Core() {
    delete engine;
}
