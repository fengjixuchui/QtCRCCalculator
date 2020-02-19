/*
 * Copyritht 2020 QTCRCCALCULATOR PROJECT <https://github.com/qter188/QtCRCCalculator>
 * QtCRCCalculator is licensed according to the terms in the file LICENCE in the root of the source code directory.
 *
 * The file is encoding with UTF8 (with BOM). Thanks google translation <https://translate.google.cn>.
 *
 * Bug Report: qter@188.com
 * User Exchange QQ Group: 952218522
 * Qt Technical Exchange QQ Group: 723516989
 */
#ifndef QTCRCCALCULATOR_HH
#define QTCRCCALCULATORT_HH

#include <QObject>

class QtCRCCalculator : public QObject
{
    Q_OBJECT
public:
    explicit QtCRCCalculator(QObject *parent = Q_NULLPTR);
    ~QtCRCCalculator();
};

#endif // QTCRCCALCULATOR_HH
