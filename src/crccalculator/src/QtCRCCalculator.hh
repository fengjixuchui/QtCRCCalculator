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
#include "QtCRCInterface.hh"

class QtCRCCalculator : public QObject
{
    Q_OBJECT
private:
    explicit QtCRCCalculator(QObject *parent = Q_NULLPTR);
    ~QtCRCCalculator();
public:
    enum TextModel{
        TextModelFile,
        TextModelHex,
        TextModelDec,
        TextModelOtc,
        TextModelBin,
        TextModelUtf8,
        TextModelLocal
    };
    Q_ENUM(TextModel)

    /**
     * @brief instance 本类是一个单实例类，该函数获取唯一单实例（未被创建则创建）
     * @return crc计算器实例
     */
    static QtCRCCalculator* instance();

    /**
     * @brief registerQmlType 将该类注册为qml单实例控件，使用时导入即可：import CustomControls.QtCalculator
     */
    void registerQmlType();

    /**
     * @brief calculatreCRC 计算crc值
     * @param data 待计算数据（文本）,如果需要计算文件的crc，则data是文件名称（绝对路径）
     * @param model 文本格式，详见TextModel
     */
    Q_INVOKABLE void calculatreCRC(QString data, int model, int textModel);
private:
    static QtCRCCalculator *instancePtr;
};

#endif // QTCRCCALCULATOR_HH
