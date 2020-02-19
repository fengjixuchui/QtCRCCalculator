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
#include <QQmlEngine>
#include "QtCRCCalculator.hh"

QtCRCCalculator *QtCRCCalculator::instancePtr = Q_NULLPTR;
QtCRCCalculator::QtCRCCalculator(QObject *parent)
    : QObject(parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

QtCRCCalculator::~QtCRCCalculator()
{

}

QtCRCCalculator* QtCRCCalculator::instance()
{
    if (!instancePtr){
        new QtCRCCalculator;
    }

    Q_ASSERT_X(instancePtr, __FUNCTION__, "Can not allocate memory for QtCRCCalculator");
    return instancePtr;
}

void QtCRCCalculator::calculatreCRC(QString data, int model, int textModel)
{

}

void QtCRCCalculator::registerQmlType()
{
    qmlRegisterSingletonType<QtCRCCalculator>("CustomControls.QtCalculator", 1, 0, "QtCRCCalculator", [](QQmlEngine *, QJSEngine *)->QObject*{
        return QtCRCCalculator::instance();
    });
}
