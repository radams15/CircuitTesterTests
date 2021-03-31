//
// Created by rhys on 07/02/2021.
//

#ifndef CSD_CUSTOMTITLEBAR_H
#define CSD_CUSTOMTITLEBAR_H

#include <QSize>
#include <QEvent>
#include <QLabel>
#include <QPoint>
#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPushButton>
#include <QStyleOption>

namespace QCustomAttrs {
    enum WindowButton {
        Minimize = 0x01,
        Maximize = 0x02,
        Close    = 0x04,
        All      = Minimize | Maximize | Close
    };

    Q_DECLARE_FLAGS(WindowButtons, WindowButton)
    Q_DECLARE_OPERATORS_FOR_FLAGS(WindowButtons)
}

class CustomTitlebar : public QWidget{
    Q_OBJECT
    Q_PROPERTY(QCustomAttrs::WindowButtons windowButtons READ windowButtons WRITE setWindowButtons)
    Q_CLASSINFO("custom_obj_type", "QTitleBar")

public:
    explicit CustomTitlebar(QWidget *parent = nullptr);

    void setWindowButtons(QCustomAttrs::WindowButtons btns);
    inline QCustomAttrs::WindowButtons windowButtons() const { return this->m_frameButtons; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    bool canMove;
    bool maximizing;

    QPoint m_pCursor;
    const QSize FRAME_BUTTON_SIZE;

    QWidget *m_parentWindow;

    QCustomAttrs::WindowButtons m_frameButtons;

    QLabel lbl_windowTitle;
    QHBoxLayout m_layout;

    QPushButton btn_minimize;
    QPushButton btn_maximize;
    QPushButton btn_close;
    QPushButton btn_menu;

signals:
    void requestClose();
    void requestMaximize();
    void requestMinimize();

};


#endif //CSD_CUSTOMTITLEBAR_H
