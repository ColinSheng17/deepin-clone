#ifndef DDISKINFO_P_H
#define DDISKINFO_P_H

#include <QSharedData>

#include "ddiskinfo.h"

class DDiskInfoPrivate : public QSharedData
{
public:
    DDiskInfoPrivate(DDiskInfo *qq);

    virtual QString filePath() const {return QString();}
    virtual void refresh() = 0;

    virtual bool hasScope(DDiskInfo::DataScope scope, DDiskInfo::ScopeMode mode) const = 0;
    virtual bool openDataStream(int index) = 0;
    virtual void closeDataStream() = 0;

    virtual qint64 read(char *data, qint64 maxSize) = 0;
    virtual qint64 write(const char *data, qint64 maxSize) = 0;

    virtual bool atEnd() const = 0;

    DDiskInfo *q;
    DDiskInfo::DataScope currentScope = DDiskInfo::NullScope;
    DDiskInfo::ScopeMode currentMode = DDiskInfo::Read;

    QString name;
    QString kname;
    quint64 size = 0;
    QString sizeDisplay;
    QString typeName;
    DDiskInfo::Type type;
    bool havePartitionTable = true;
    QList<DPartInfo> children;
    QString ptTypeName;
    DDiskInfo::PTType ptType;
};

#endif // DDISKINFO_P_H