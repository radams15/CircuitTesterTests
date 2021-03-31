# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'layoutJbelSx.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(1148, 886)
        self.centralwidget = QWidget(Form)
        self.centralwidget.setObjectName(u"centralwidget")
        self.horizontalLayout = QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.toolBox = QToolBox(self.centralwidget)
        self.toolBox.setObjectName(u"toolBox")
        self.toolBox.setEnabled(True)
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.toolBox.sizePolicy().hasHeightForWidth())
        self.toolBox.setSizePolicy(sizePolicy)
        self.toolBox.setMinimumSize(QSize(100, 0))
        self.toolBox.setMaximumSize(QSize(160, 16777215))
        self.page = QWidget()
        self.page.setObjectName(u"page")
        self.page.setGeometry(QRect(0, 0, 160, 814))
        sizePolicy.setHeightForWidth(self.page.sizePolicy().hasHeightForWidth())
        self.page.setSizePolicy(sizePolicy)
        self.verticalLayout = QVBoxLayout(self.page)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.toolButton_2 = QToolButton(self.page)
        self.toolButton_2.setObjectName(u"toolButton_2")
        icon = QIcon()
        icon.addFile(u"LayoutTest1/images/resistor.png", QSize(), QIcon.Normal, QIcon.Off)
        self.toolButton_2.setIcon(icon)
        self.toolButton_2.setIconSize(QSize(64, 64))

        self.verticalLayout.addWidget(self.toolButton_2)

        self.toolButton = QToolButton(self.page)
        self.toolButton.setObjectName(u"toolButton")
        icon1 = QIcon()
        icon1.addFile(u"LayoutTest1/images/capacitor.png", QSize(), QIcon.Normal, QIcon.Off)
        self.toolButton.setIcon(icon1)
        self.toolButton.setIconSize(QSize(64, 64))

        self.verticalLayout.addWidget(self.toolButton)

        self.toolButton_3 = QToolButton(self.page)
        self.toolButton_3.setObjectName(u"toolButton_3")
        icon2 = QIcon()
        icon2.addFile(u"LayoutTest1/images/bulb.png", QSize(), QIcon.Normal, QIcon.Off)
        self.toolButton_3.setIcon(icon2)
        self.toolButton_3.setIconSize(QSize(64, 64))

        self.verticalLayout.addWidget(self.toolButton_3)

        self.toolBox.addItem(self.page, u"General Components")
        self.page_2 = QWidget()
        self.page_2.setObjectName(u"page_2")
        self.page_2.setGeometry(QRect(0, 0, 160, 814))
        sizePolicy.setHeightForWidth(self.page_2.sizePolicy().hasHeightForWidth())
        self.page_2.setSizePolicy(sizePolicy)
        self.toolBox.addItem(self.page_2, u"Connectors")

        self.horizontalLayout.addWidget(self.toolBox)

        self.graphicsView = QGraphicsView(self.centralwidget)
        self.graphicsView.setObjectName(u"graphicsView")

        self.horizontalLayout.addWidget(self.graphicsView)

        self.verticalFrame = QFrame(self.centralwidget)
        self.verticalFrame.setObjectName(u"verticalFrame")
        self.verticalLayout_2 = QVBoxLayout(self.verticalFrame)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.doubleSpinBox = QDoubleSpinBox(self.verticalFrame)
        self.doubleSpinBox.setObjectName(u"doubleSpinBox")
        self.doubleSpinBox.setDecimals(1)
        self.doubleSpinBox.setSingleStep(0.500000000000000)
        self.doubleSpinBox.setValue(2.500000000000000)

        self.verticalLayout_2.addWidget(self.doubleSpinBox)

        self.checkBox = QCheckBox(self.verticalFrame)
        self.checkBox.setObjectName(u"checkBox")
        self.checkBox.setChecked(True)

        self.verticalLayout_2.addWidget(self.checkBox)


        self.horizontalLayout.addWidget(self.verticalFrame)

        Form.setCentralWidget(self.centralwidget)

        self.retranslateUi(Form)

        self.toolBox.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.toolButton_2.setText(QCoreApplication.translate("Form", u"...", None))
        self.toolButton.setText(QCoreApplication.translate("Form", u"...", None))
        self.toolButton_3.setText(QCoreApplication.translate("Form", u"...", None))
        self.toolBox.setItemText(self.toolBox.indexOf(self.page), QCoreApplication.translate("Form", u"General Components", None))
        self.toolBox.setItemText(self.toolBox.indexOf(self.page_2), QCoreApplication.translate("Form", u"Connectors", None))
        self.checkBox.setText(QCoreApplication.translate("Form", u"Enabled", None))
    # retranslateUi

