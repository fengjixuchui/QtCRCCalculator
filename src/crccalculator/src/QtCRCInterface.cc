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
#include <QMetaEnum>

#include "QtCRCInterface.hh"

QtCRCInterface::QtCRCInterface(QObject *parent)
    : QObject (parent)
{

}

QStringList QtCRCInterface::supportedParameterModels()
{
    QStringList modelStrings;
    QMetaEnum models = QMetaEnum::fromType<CRCParameterModel>();

    const char *ch = nullptr;
    for (int i = 0; i < models.keyCount(); i++) {
        ch = models.valueToKey(i);
        if (ch){
            modelStrings.append(QString(ch));
        }
    }

    return modelStrings;
}

QString QtCRCInterface::polyFormulaString(QtCRCInterface::CRCParameterModel model)
{
    QString polynomial;

    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_8_ROHC:
        polynomial = QString("x8+x2+x+1");
        break;
    case CRC_8_MAXIM:
        polynomial = QString("x8+x5+x4+1");
        break;
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_MODBUS:
    case CRC_16_CCITT:
    case CRC_16_CCITT_FALSE:
    case CRC_16_x25:
    case CRC_16_XMODEM:
        polynomial = QString("x6+x2+x5+1");
        break;
    case CRC_16_DNP:
        polynomial = QString("x6+x3+x2+x1+x0+x8+x6+x5+x2+1");
        break;
    case CRC_32:
    case CRC_32_MPEG2:
        polynomial = QString("x32+x6+x3+x2+x6+x2+x1+x0+x8+x7+x5+x4+x2+x+1");
        break;
    default:
        polynomial = QString("Error: Polynomial not found");
        break;
    }

    return polynomial;
}

uint32_t QtCRCInterface::initValue(QtCRCInterface::CRCParameterModel model)
{
    uint32_t init = 0;

    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_8_MAXIM:
        init = 0x00;
        break;
    case CRC_8_ROHC:
        init = 0xff;
        break;
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_CCITT:
    case CRC_16_XMODEM:
    case CRC_16_DNP:
        init = 0x0000;
        break;
    case CRC_16_USB:
    case CRC_16_MODBUS:
    case CRC_16_CCITT_FALSE:
    case CRC_16_x25:
        init = 0xffff;
        break;
    case CRC_32:
    case CRC_32_MPEG2:
        init = 0xffffffff;
        break;
    }

    return init;
}

uint32_t QtCRCInterface::polynomial(QtCRCInterface::CRCParameterModel model)
{
    uint32_t poly = 0;

    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_8_ROHC:
        poly = 0x07;
        break;
    case CRC_8_MAXIM:
        poly = 0x31;
        break;
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_MODBUS:
        poly = 0x8005;
        break;
    case CRC_16_CCITT:
    case CRC_16_XMODEM:
    case CRC_16_CCITT_FALSE:
    case CRC_16_x25:
        poly = 0x1021;
        break;
    case CRC_16_DNP:
        poly = 0x3d65;
        break;
    case CRC_32:
    case CRC_32_MPEG2:
        poly = 0x04c11db7;
        break;
    }

    return poly;
}

uint32_t QtCRCInterface::xorValue(QtCRCInterface::CRCParameterModel model)
{
    uint32_t value = 0;

    switch (model) {
    case CRC_8:
    case CRC_8_ROHC:
    case CRC_8_MAXIM:
        value = 0x00;
        break;
    case CRC_8_ITU:
        value = 0x55;
        break;
    case CRC_16_IBM:

    case CRC_16_MODBUS:
    case CRC_16_CCITT:
    case CRC_16_CCITT_FALSE:
    case CRC_16_XMODEM:
        value = 0x0000;
        break;
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_x25:
    case CRC_16_DNP:
        value = 0xffff;
        break;
    case CRC_32:
        value = 0xffffffff;
        break;
    case CRC_32_MPEG2:
        value = 0x00000000;
        break;
    }

    return value;
}

bool QtCRCInterface::isInputReversal(QtCRCInterface::CRCParameterModel model)
{
    bool reversal = true;

    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_16_CCITT_FALSE:
    case CRC_16_XMODEM:
    case CRC_32_MPEG2:
        reversal = false;
        break;

    case CRC_8_ROHC:
    case CRC_8_MAXIM:
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_MODBUS:
    case CRC_16_CCITT:
    case CRC_16_x25:
    case CRC_16_DNP:
    case CRC_32:
        reversal = true;
         break;
    }

    return reversal;
}

bool QtCRCInterface::isOutputReversal(QtCRCInterface::CRCParameterModel model)
{
    bool reversal = true;

    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_16_CCITT_FALSE:
    case CRC_16_XMODEM:
    case CRC_32_MPEG2:
        reversal = false;
        break;

    case CRC_8_ROHC:
    case CRC_8_MAXIM:
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_MODBUS:
    case CRC_16_CCITT:
    case CRC_16_x25:
    case CRC_16_DNP:
    case CRC_32:
        reversal = true;
         break;
    }

    return reversal;
}

int QtCRCInterface::bitsWidth(QtCRCInterface::CRCParameterModel model)
{
    int ret = -1;
    switch (model) {
    case CRC_8:
    case CRC_8_ITU:
    case CRC_8_ROHC:
    case CRC_8_MAXIM:
        ret = 8;
        break;
    case CRC_16_IBM:
    case CRC_16_MAXIM:
    case CRC_16_USB:
    case CRC_16_MODBUS:
    case CRC_16_CCITT:
    case CRC_16_CCITT_FALSE:
    case CRC_16_x25:
    case CRC_16_XMODEM:
    case CRC_16_DNP:
        ret = 16;
        break;
    case CRC_32:
    case CRC_32_MPEG2:
        ret = 32;
        break;
    }
    return ret;
}
