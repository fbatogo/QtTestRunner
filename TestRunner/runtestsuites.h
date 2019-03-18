#ifndef RUNTESTSUITES_H
#define RUNTESTSUITES_H

#include <QString>
#include <QMap>

class RunTestSuites
{
public:
    RunTestSuites();

    bool setCommandLineParameters(int argc, char *argv[]);

    QMap<QString, QMap<QString, QString> > knownParameters();

    QString parameterHelp();

    bool parametersAreValid();

    int executeAll();
    int executeByPattern(QString pattern);

private:
    void populateParameterMap();

    int mArgc;
    char **mArgv;
    QMap<QString, QMap<QString, QString> > mParameterMap;
};

#endif // RUNTESTSUITES_H
