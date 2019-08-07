/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *resetButton;
    QSpinBox *gridspinbox;
    QPushButton *setgridbutton;
    QGroupBox *tranformation;
    QLabel *label_15;
    QSpinBox *xshear;
    QSpinBox *anglespinbox;
    QPushButton *shearing;
    QLabel *label_17;
    QSpinBox *yshear;
    QPushButton *translation;
    QLabel *label_13;
    QSpinBox *xtranslate;
    QLabel *label_16;
    QSpinBox *yscale;
    QLabel *label_11;
    QPushButton *scaling;
    QLabel *label_14;
    QLabel *label_12;
    QSpinBox *xscale;
    QSpinBox *ytranslate;
    QPushButton *rotation;
    QPushButton *reflection;
    QPushButton *clearvertex;
    QLabel *label_10;
    QPushButton *setvertex;
    QGroupBox *clipping;
    QPushButton *lineclipping;
    QPushButton *setcorner1;
    QPushButton *setcorner2;
    QPushButton *polygonclipping;
    QGroupBox *beziercurve;
    QPushButton *drawBezierCurve;
    QPushButton *clearbezpoint;
    QPushButton *setbezpoint;
    QGroupBox *filling;
    QPushButton *scanlinefill;
    QPushButton *floodfill;
    QPushButton *boundaryfill;
    QGroupBox *drawellipse;
    QPushButton *ellipse;
    QSpinBox *r2spinbox;
    QSpinBox *r1spinbox;
    QLabel *label_7;
    QLabel *label_6;
    QGroupBox *drawcircle;
    QPushButton *bresenhamCircle;
    QSpinBox *radiusspinbox;
    QPushButton *midPointCircle;
    QLabel *label_2;
    QGroupBox *drawline;
    QPushButton *bresenhamLine;
    QPushButton *set_point2;
    QPushButton *set_point1;
    QPushButton *DDALine;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(999, 665);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 600, 600));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(690, 60, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 40, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(820, 60, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(840, 40, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 600, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 600));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(850, 10, 91, 21));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(710, 580, 241, 31));
        resetButton->setStyleSheet(QStringLiteral("background:green;"));
        gridspinbox = new QSpinBox(centralWidget);
        gridspinbox->setObjectName(QStringLiteral("gridspinbox"));
        gridspinbox->setGeometry(QRect(690, 10, 71, 22));
        gridspinbox->setMinimum(1);
        setgridbutton = new QPushButton(centralWidget);
        setgridbutton->setObjectName(QStringLiteral("setgridbutton"));
        setgridbutton->setGeometry(QRect(770, 10, 75, 23));
        tranformation = new QGroupBox(centralWidget);
        tranformation->setObjectName(QStringLiteral("tranformation"));
        tranformation->setGeometry(QRect(620, 290, 371, 191));
        label_15 = new QLabel(tranformation);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(280, 130, 16, 16));
        xshear = new QSpinBox(tranformation);
        xshear->setObjectName(QStringLiteral("xshear"));
        xshear->setGeometry(QRect(210, 130, 51, 22));
        anglespinbox = new QSpinBox(tranformation);
        anglespinbox->setObjectName(QStringLiteral("anglespinbox"));
        anglespinbox->setGeometry(QRect(300, 100, 51, 22));
        anglespinbox->setMinimum(-999);
        anglespinbox->setValue(0);
        shearing = new QPushButton(tranformation);
        shearing->setObjectName(QStringLiteral("shearing"));
        shearing->setGeometry(QRect(100, 130, 75, 23));
        label_17 = new QLabel(tranformation);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(190, 130, 16, 16));
        yshear = new QSpinBox(tranformation);
        yshear->setObjectName(QStringLiteral("yshear"));
        yshear->setGeometry(QRect(300, 130, 51, 22));
        translation = new QPushButton(tranformation);
        translation->setObjectName(QStringLiteral("translation"));
        translation->setGeometry(QRect(100, 40, 75, 23));
        label_13 = new QLabel(tranformation);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(280, 70, 16, 16));
        xtranslate = new QSpinBox(tranformation);
        xtranslate->setObjectName(QStringLiteral("xtranslate"));
        xtranslate->setGeometry(QRect(210, 40, 51, 22));
        xtranslate->setMinimum(-999);
        xtranslate->setMaximum(999);
        label_16 = new QLabel(tranformation);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(190, 70, 16, 16));
        yscale = new QSpinBox(tranformation);
        yscale->setObjectName(QStringLiteral("yscale"));
        yscale->setGeometry(QRect(300, 70, 51, 22));
        yscale->setMinimum(-999);
        yscale->setMaximum(999);
        yscale->setValue(1);
        label_11 = new QLabel(tranformation);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 40, 16, 16));
        scaling = new QPushButton(tranformation);
        scaling->setObjectName(QStringLiteral("scaling"));
        scaling->setGeometry(QRect(100, 70, 75, 23));
        label_14 = new QLabel(tranformation);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(260, 100, 31, 16));
        label_12 = new QLabel(tranformation);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(280, 40, 16, 16));
        xscale = new QSpinBox(tranformation);
        xscale->setObjectName(QStringLiteral("xscale"));
        xscale->setGeometry(QRect(210, 70, 51, 21));
        xscale->setMinimum(-999);
        xscale->setMaximum(999);
        xscale->setValue(1);
        ytranslate = new QSpinBox(tranformation);
        ytranslate->setObjectName(QStringLiteral("ytranslate"));
        ytranslate->setGeometry(QRect(300, 40, 51, 22));
        ytranslate->setMinimum(-999);
        ytranslate->setMaximum(999);
        rotation = new QPushButton(tranformation);
        rotation->setObjectName(QStringLiteral("rotation"));
        rotation->setGeometry(QRect(100, 100, 75, 23));
        reflection = new QPushButton(tranformation);
        reflection->setObjectName(QStringLiteral("reflection"));
        reflection->setGeometry(QRect(100, 160, 75, 23));
        clearvertex = new QPushButton(tranformation);
        clearvertex->setObjectName(QStringLiteral("clearvertex"));
        clearvertex->setGeometry(QRect(280, 10, 75, 23));
        label_10 = new QLabel(tranformation);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 10, 91, 16));
        setvertex = new QPushButton(tranformation);
        setvertex->setObjectName(QStringLiteral("setvertex"));
        setvertex->setGeometry(QRect(200, 10, 75, 23));
        label_15->raise();
        xshear->raise();
        anglespinbox->raise();
        shearing->raise();
        label_17->raise();
        yshear->raise();
        translation->raise();
        label_13->raise();
        xtranslate->raise();
        label_16->raise();
        yscale->raise();
        label_11->raise();
        scaling->raise();
        label_14->raise();
        label_12->raise();
        xscale->raise();
        ytranslate->raise();
        rotation->raise();
        reflection->raise();
        frame->raise();
        clearvertex->raise();
        label_10->raise();
        setvertex->raise();
        clipping = new QGroupBox(centralWidget);
        clipping->setObjectName(QStringLiteral("clipping"));
        clipping->setGeometry(QRect(620, 480, 371, 51));
        lineclipping = new QPushButton(clipping);
        lineclipping->setObjectName(QStringLiteral("lineclipping"));
        lineclipping->setGeometry(QRect(170, 20, 81, 23));
        setcorner1 = new QPushButton(clipping);
        setcorner1->setObjectName(QStringLiteral("setcorner1"));
        setcorner1->setGeometry(QRect(10, 20, 75, 23));
        setcorner2 = new QPushButton(clipping);
        setcorner2->setObjectName(QStringLiteral("setcorner2"));
        setcorner2->setGeometry(QRect(90, 20, 75, 23));
        polygonclipping = new QPushButton(clipping);
        polygonclipping->setObjectName(QStringLiteral("polygonclipping"));
        polygonclipping->setGeometry(QRect(260, 20, 101, 23));
        beziercurve = new QGroupBox(centralWidget);
        beziercurve->setObjectName(QStringLiteral("beziercurve"));
        beziercurve->setGeometry(QRect(620, 530, 371, 41));
        drawBezierCurve = new QPushButton(beziercurve);
        drawBezierCurve->setObjectName(QStringLiteral("drawBezierCurve"));
        drawBezierCurve->setGeometry(QRect(250, 10, 101, 23));
        clearbezpoint = new QPushButton(beziercurve);
        clearbezpoint->setObjectName(QStringLiteral("clearbezpoint"));
        clearbezpoint->setGeometry(QRect(170, 10, 75, 23));
        setbezpoint = new QPushButton(beziercurve);
        setbezpoint->setObjectName(QStringLiteral("setbezpoint"));
        setbezpoint->setGeometry(QRect(90, 10, 75, 23));
        filling = new QGroupBox(centralWidget);
        filling->setObjectName(QStringLiteral("filling"));
        filling->setGeometry(QRect(620, 240, 371, 41));
        scanlinefill = new QPushButton(filling);
        scanlinefill->setObjectName(QStringLiteral("scanlinefill"));
        scanlinefill->setGeometry(QRect(280, 10, 75, 23));
        floodfill = new QPushButton(filling);
        floodfill->setObjectName(QStringLiteral("floodfill"));
        floodfill->setGeometry(QRect(100, 10, 81, 23));
        boundaryfill = new QPushButton(filling);
        boundaryfill->setObjectName(QStringLiteral("boundaryfill"));
        boundaryfill->setGeometry(QRect(190, 10, 81, 23));
        drawellipse = new QGroupBox(centralWidget);
        drawellipse->setObjectName(QStringLiteral("drawellipse"));
        drawellipse->setGeometry(QRect(620, 200, 371, 41));
        ellipse = new QPushButton(drawellipse);
        ellipse->setObjectName(QStringLiteral("ellipse"));
        ellipse->setGeometry(QRect(260, 10, 101, 21));
        r2spinbox = new QSpinBox(drawellipse);
        r2spinbox->setObjectName(QStringLiteral("r2spinbox"));
        r2spinbox->setGeometry(QRect(190, 10, 51, 22));
        r1spinbox = new QSpinBox(drawellipse);
        r1spinbox->setObjectName(QStringLiteral("r1spinbox"));
        r1spinbox->setGeometry(QRect(90, 10, 51, 22));
        label_7 = new QLabel(drawellipse);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 10, 46, 20));
        label_6 = new QLabel(drawellipse);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 10, 46, 20));
        drawcircle = new QGroupBox(centralWidget);
        drawcircle->setObjectName(QStringLiteral("drawcircle"));
        drawcircle->setGeometry(QRect(620, 160, 371, 41));
        bresenhamCircle = new QPushButton(drawcircle);
        bresenhamCircle->setObjectName(QStringLiteral("bresenhamCircle"));
        bresenhamCircle->setGeometry(QRect(280, 10, 81, 21));
        radiusspinbox = new QSpinBox(drawcircle);
        radiusspinbox->setObjectName(QStringLiteral("radiusspinbox"));
        radiusspinbox->setGeometry(QRect(110, 10, 71, 22));
        midPointCircle = new QPushButton(drawcircle);
        midPointCircle->setObjectName(QStringLiteral("midPointCircle"));
        midPointCircle->setGeometry(QRect(190, 10, 81, 21));
        label_2 = new QLabel(drawcircle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 61, 16));
        drawline = new QGroupBox(centralWidget);
        drawline->setObjectName(QStringLiteral("drawline"));
        drawline->setGeometry(QRect(620, 90, 361, 71));
        bresenhamLine = new QPushButton(drawline);
        bresenhamLine->setObjectName(QStringLiteral("bresenhamLine"));
        bresenhamLine->setGeometry(QRect(220, 40, 111, 21));
        set_point2 = new QPushButton(drawline);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(180, 10, 81, 23));
        set_point1 = new QPushButton(drawline);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(90, 10, 81, 23));
        DDALine = new QPushButton(drawline);
        DDALine->setObjectName(QStringLiteral("DDALine"));
        DDALine->setGeometry(QRect(90, 40, 101, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", 0));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", 0));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", 0));
        resetButton->setText(QApplication::translate("MainWindow", "RESET", 0));
        setgridbutton->setText(QApplication::translate("MainWindow", "Set Grid", 0));
        tranformation->setTitle(QApplication::translate("MainWindow", "Transformation", 0));
        label_15->setText(QApplication::translate("MainWindow", "y:", 0));
        shearing->setText(QApplication::translate("MainWindow", "Shearing", 0));
        label_17->setText(QApplication::translate("MainWindow", "x:", 0));
        translation->setText(QApplication::translate("MainWindow", "Translation", 0));
        label_13->setText(QApplication::translate("MainWindow", "y:", 0));
        label_16->setText(QApplication::translate("MainWindow", "x:", 0));
        label_11->setText(QApplication::translate("MainWindow", "x:", 0));
        scaling->setText(QApplication::translate("MainWindow", "Scaling", 0));
        label_14->setText(QApplication::translate("MainWindow", "angle: ", 0));
        label_12->setText(QApplication::translate("MainWindow", "y:", 0));
        rotation->setText(QApplication::translate("MainWindow", "Rotation", 0));
        reflection->setText(QApplication::translate("MainWindow", "Reflection", 0));
        clearvertex->setText(QApplication::translate("MainWindow", "Clear vertex", 0));
        label_10->setText(QApplication::translate("MainWindow", "Polygon Drawing", 0));
        setvertex->setText(QApplication::translate("MainWindow", "Set vertex", 0));
        clipping->setTitle(QApplication::translate("MainWindow", "Clipping", 0));
        lineclipping->setText(QApplication::translate("MainWindow", "Line clipping", 0));
        setcorner1->setText(QApplication::translate("MainWindow", "Set Corner 1", 0));
        setcorner2->setText(QApplication::translate("MainWindow", "Set Corner 2", 0));
        polygonclipping->setText(QApplication::translate("MainWindow", "Polygon clipping", 0));
        beziercurve->setTitle(QApplication::translate("MainWindow", "Bezier Curve", 0));
        drawBezierCurve->setText(QApplication::translate("MainWindow", "Draw Bezier Curve", 0));
        clearbezpoint->setText(QApplication::translate("MainWindow", "Clear points", 0));
        setbezpoint->setText(QApplication::translate("MainWindow", "Set Points", 0));
        filling->setTitle(QApplication::translate("MainWindow", "Filling Algorithms", 0));
        scanlinefill->setText(QApplication::translate("MainWindow", "Scanline Fill", 0));
        floodfill->setText(QApplication::translate("MainWindow", "Flood Fill", 0));
        boundaryfill->setText(QApplication::translate("MainWindow", "Boundary Fill", 0));
        drawellipse->setTitle(QApplication::translate("MainWindow", "Ellpse", 0));
        ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        label_7->setText(QApplication::translate("MainWindow", "Set R2 :", 0));
        label_6->setText(QApplication::translate("MainWindow", "Set R1 :", 0));
        drawcircle->setTitle(QApplication::translate("MainWindow", "Circle", 0));
        bresenhamCircle->setText(QApplication::translate("MainWindow", "Bresenham", 0));
        midPointCircle->setText(QApplication::translate("MainWindow", "Mid Point", 0));
        label_2->setText(QApplication::translate("MainWindow", "   Set Radius", 0));
        drawline->setTitle(QApplication::translate("MainWindow", "Line", 0));
        bresenhamLine->setText(QApplication::translate("MainWindow", "Bresenham", 0));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", 0));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", 0));
        DDALine->setText(QApplication::translate("MainWindow", "DDA", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
