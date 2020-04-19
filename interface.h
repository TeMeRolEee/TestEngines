#pragma once

#include <QtCore/QString>
#include <QtCore/QJsonObject>

#ifdef Q_OS_WIN
#define EXPORT __declspec( dllexport )
#else
#define EXPORT
#endif

#ifdef __cplusplus
extern "C" {

EXPORT bool init();
EXPORT void deInit();
EXPORT bool scanFile(const QString &filepath, QJsonObject *result);

#endif
#ifdef __cplusplus
}
#endif

