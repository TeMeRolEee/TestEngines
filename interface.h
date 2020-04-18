#pragma once

#include <QtCore/QString>
#include <QtCore/QJsonObject>

#define EXPORT __declspec( dllexport )

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
// used by C++ source code

EXPORT bool init();
EXPORT void deInit();
EXPORT bool scanFile(const QString &filepath, QJsonObject *result);

#endif
#ifdef __cplusplus
}
#endif

