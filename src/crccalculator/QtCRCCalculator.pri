INCLUDEPATH += \
    $$PWD/src/crccalculator/ui/widget/

SOURCES += \
    $$PWD/src/QtCRCCalculator.cc \
    $$PWD/src/QtCRCInterface.cc \
    src/crccalculator/ui/widget/CRCCalculatorWidget.cc

HEADERS += \
    $$PWD/src/QtCRCCalculator.hh \
    $$PWD/src/QtCRCInterface.hh \
    src/crccalculator/ui/widget/CRCCalculatorWidget.hh

FORMS += \
    src/crccalculator/ui/widget/CRCCalculatorWidget.ui
