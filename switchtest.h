#ifndef SWITCHTEST_H
#define SWITCHTEST_H

#include <QObject>

class SwitchTest : public QObject
{
    Q_OBJECT
public:
    explicit SwitchTest(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SWITCHTEST_H