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
#include "CRCCalculatorWidget.hh"
#include "ui_CRCCalculatorWidget.h"

CRCCalculatorWidget::CRCCalculatorWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CRCCalculatorWidget)
{
    ui->setupUi(this);

    inputTextEdit = ui->inputTextEdit;
    importFilePushButton = ui->importFilePushButton;
    fileNameLabel = ui->fileNameLabel;
    fileRadioButton = ui->fileRadioButton;
    hexRadioButton = ui->hexRadioButton;
    decRadioButton = ui->decRadioButton;
    otcRadioButton = ui->otcRadioButton;
    binRadioButton = ui->binRadioButton;
    asciiRadioButton = ui->asciiRadioButton;
    utf8RadioButton = ui->utf8RadioButton;
    localRadioButton = ui->localRadioButton;
    progressBar = ui->progressBar;

    modelComboBox = ui->modelComboBox;
    inputReversalCheckBox = ui->inputReversalCheckBox;
    outputReversalCheckBox = ui->outputReversalCheckBox;
    dataWidthComboBox = ui->dataWidthComboBox;
    polynomialLineEdit = ui->polynomialLineEdit;
    initValueLineEdit = ui->initValueLineEdit;
    resultXORValueLineEdit = ui->resultXORValueLineEdit;

    resultHexLineEdit = ui->resultHexLineEdit;
    resultBinLineEdit = ui->resultBinLineEdit;
    resultDecLineEdit = ui->resultDecLineEdit;
    resultOtcLineEdit = ui->resultOtcLineEdit;
    copyHexPushButton = ui->copyHexPushButton;
    copyBinPushButton = ui->copyBinPushButton;
    copyDecPushButton = ui->copyDecPushButton;
    copyOtcPushButton = ui->copyOtcPushButton;

    visitWebPushButton = ui->visitWebPushButton;
    calculatePushButton = ui->calculatePushButton;
}

CRCCalculatorWidget::~CRCCalculatorWidget()
{
    delete ui;
}

void CRCCalculatorWidget::on_importFilePushButton_clicked()
{

}

void CRCCalculatorWidget::on_fileRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_hexRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_decRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_otcRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_binRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_asciiRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_utf8RadioButton_clicked()
{

}

void CRCCalculatorWidget::on_localRadioButton_clicked()
{

}

void CRCCalculatorWidget::on_modelComboBox_currentIndexChanged(const int index)
{
    Q_UNUSED(index);
}

void CRCCalculatorWidget::on_inputReversalCheckBox_clicked()
{

}

void CRCCalculatorWidget::on_outputReversalCheckBox_clicked()
{

}

void CRCCalculatorWidget::on_dataWidthComboBox_currentIndexChanged(const int index)
{
    Q_UNUSED(index);
}

void CRCCalculatorWidget::on_copyHexPushButton_clicked()
{

}

void CRCCalculatorWidget::on_copyBinPushButton_clicked()
{

}

void CRCCalculatorWidget::on_copyDecPushButton_clicked()
{

}

void CRCCalculatorWidget::on_copyOtcPushButton_clicked()
{

}

void CRCCalculatorWidget::on_visitWebPushButton_clicked()
{

}

void CRCCalculatorWidget::on_calculatePushButton_clicked()
{

}
