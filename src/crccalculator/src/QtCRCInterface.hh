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
#ifndef QTCRCINTERFACE_HH
#define QTCRCINTERFACE_HH

#include <QObject>
#include <QStringList>

class QtCRCInterface:public QObject
{
    Q_OBJECT
public:
    explicit QtCRCInterface(QObject *parent = nullptr);

    /// \brief crc算法模型（crc参数模型）
    enum CRCParameterModel{
        CRC_8,
        CRC_8_ITU,
        CRC_8_ROHC,
        CRC_8_MAXIM,

        CRC_16_IBM,
        CRC_16_MAXIM,
        CRC_16_USB,
        CRC_16_MODBUS,
        CRC_16_CCITT,
        CRC_16_CCITT_FALSE,
        CRC_16_x25,
        CRC_16_XMODEM,
        CRC_16_DNP,

        CRC_32,
        CRC_32_MPEG2
    };
    Q_ENUM(CRCParameterModel)

    /**
     * @brief calculateCRC  -- crc计算函数，支持的参数模型见CRCParameterModel
     * @param input         -- 输入数据
     * @param length        -- 输入数据长度
     * @param crc           -- crc计算结果
     * @param model         -- crc参数模型
     */
    template<typename T>
    T calculateCRC(uint8_t *input, uint64_t length, QtCRCInterface::CRCParameterModel model){
        T crcReg = static_cast<T>(initValue(model));
        T poly = static_cast<T>(polynomial(model));
        uint8_t byte = 0;

        T temp = 1;
        while (length--){
            byte = *(input++);

            if (isInputReversal(model)){
                reverseInt(byte,byte);
            }

            crcReg ^= static_cast<T>((byte << 8*(sizeof (T)-1)));
            for(int i = 0;i < 8;i++){
                if(crcReg & (temp << (sizeof (T)*8-1))){
                    crcReg = static_cast<T>((crcReg << 1) ^ poly);
                }else {
                    crcReg = static_cast<T>(crcReg << 1);
                }
            }
        }

        if (isOutputReversal(model)){
            reverseInt(crcReg,crcReg);
        }

        T crc = (crcReg ^ static_cast<T>(xorValue(model))) ;
        return crc;
    }
public:
    /**
     * @brief supportedParameterModels  -- 支持的crc参数模型
     * @return                          -- 参数模型列表
     */
    QStringList supportedParameterModels();

    /**
     * @brief polyFormulaString -- 获取多项式公式
     * @param model             -- crc参数模型
     * @return                  -- 多项式公式
     */
    QString polyFormulaString(CRCParameterModel model);

    /**
     * @brief initValue     -- 获取crc初始值
     * @param model         -- crc参数模型
     * @return              -- 指定参数模型的crc初始值(根据实际情况进项强制转换)
     */
    uint32_t initValue(QtCRCInterface::CRCParameterModel model);

    /**
     * @brief polynomial-- 获取多项式
     * @param model     -- crc参数模型
     * @return          -- 执行的参数模型的多项式(根据实际情况进项强制转换)
     */
    uint32_t polynomial(QtCRCInterface::CRCParameterModel model);

    /**
     * @brief xorValue  -- 结果异或值
     * @param model     -- crc参数模型
     * @return          -- 结果异或值
     */
    uint32_t xorValue(QtCRCInterface::CRCParameterModel model);

    /**
     * @brief isInputReversal   -- 判断输入是否需要翻转
     * @param model             -- crc参数模型
     * @return                  -- 输入数据需要翻转返回true，否则返回false
     */
    bool isInputReversal(QtCRCInterface::CRCParameterModel model);

    /**
     * @brief isOutputReversal  -- 判断输入是否需要翻转
     * @param model             -- crc参数模型
     * @return                  -- 输入数据需要翻转返回true，否则返回false
     */
    bool isOutputReversal(QtCRCInterface::CRCParameterModel model);

    /**
     * @brief bitsWidth     -- 获取位宽
     * @param model         -- 参数模型
     * @return              -- 位宽
     */
    int bitsWidth(QtCRCInterface::CRCParameterModel model);
private:
    /**
     * @brief reverseInt    -- 将一个整数按位反转
     * @param input         -- 输入数据
     * @param output        -- 输出输出
     * @return              -- 转换是否成功
     */
    template<typename T>
    bool reverseInt(const T &input, T &output){
        int bitsWidth = sizeof (input)*8;

        QString inputStr = QString("%1").arg(QString::number(input, 2), bitsWidth, '0');
        QString outputStr;
        outputStr.resize(bitsWidth);
        for (int i = 0; i < bitsWidth; i++){
            outputStr.replace(i, 1, inputStr.at(bitsWidth-1-i));
        }

        bool ok;
        output = static_cast<T>(outputStr.toULongLong(&ok, 2));
        return ok;
    }
};

#endif
