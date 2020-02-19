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
#ifndef CRCCALCULATORWIDGET_HH
#define CRCCALCULATORWIDGET_HH

#include <QLabel>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QProgressBar>

namespace Ui {
    class CRCCalculatorWidget;
}
class CRCCalculatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CRCCalculatorWidget(QWidget *parent = Q_NULLPTR);
    ~CRCCalculatorWidget();
private:
    Ui::CRCCalculatorWidget *ui;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief 输入设置
    QTextEdit *inputTextEdit;
    QPushButton *importFilePushButton;
    QLabel *fileNameLabel;
    QRadioButton *fileRadioButton;
    QRadioButton *hexRadioButton;
    QRadioButton *decRadioButton;
    QRadioButton *otcRadioButton;
    QRadioButton *binRadioButton;
    QRadioButton *asciiRadioButton;
    QRadioButton *utf8RadioButton;
    QRadioButton *localRadioButton;
    QProgressBar *progressBar;
private slots:
    void on_importFilePushButton_clicked();
    void on_fileRadioButton_clicked();
    void on_hexRadioButton_clicked();
    void on_decRadioButton_clicked();
    void on_otcRadioButton_clicked();
    void on_binRadioButton_clicked();
    void on_asciiRadioButton_clicked();
    void on_utf8RadioButton_clicked();
    void on_localRadioButton_clicked();
private:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief 参数模型
    QComboBox *modelComboBox;
    QCheckBox *inputReversalCheckBox;
    QCheckBox *outputReversalCheckBox;
    QComboBox *dataWidthComboBox;
    QLineEdit *polynomialLineEdit;
    QLineEdit *initValueLineEdit;
    QLineEdit *resultXORValueLineEdit;
private slots:
    void on_modelComboBox_currentIndexChanged(const int index);
    void on_inputReversalCheckBox_clicked();
    void on_outputReversalCheckBox_clicked();
    void on_dataWidthComboBox_currentIndexChanged(const int index);
private:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief 计算结果
    QLineEdit *resultHexLineEdit;
    QLineEdit *resultBinLineEdit;
    QLineEdit *resultDecLineEdit;
    QLineEdit *resultOtcLineEdit;
    QPushButton *copyHexPushButton;
    QPushButton *copyBinPushButton;
    QPushButton *copyDecPushButton;
    QPushButton *copyOtcPushButton;
private slots:
    void on_copyHexPushButton_clicked();
    void on_copyBinPushButton_clicked();
    void on_copyDecPushButton_clicked();
    void on_copyOtcPushButton_clicked();
private:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief 其他操作
    QPushButton *visitWebPushButton;
    QPushButton *calculatePushButton;
private slots:
    void on_visitWebPushButton_clicked();
    void on_calculatePushButton_clicked();
signals:

};

#endif // CRCCALCULATORWIDGET_HH
