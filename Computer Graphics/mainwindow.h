#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();
    void on_set_point1_clicked();
    void on_set_point2_clicked();
    void on_setgridbutton_clicked();
    void on_resetButton_clicked();
    void on_DDALine_clicked();
    void DDAline(int r, int g, int b);
    void on_bresenhamLine_clicked();
    void on_midPointCircle_clicked();
    void on_bresenhamCircle_clicked();
    void on_ellipse_clicked();
    void on_floodfill_clicked();
    void floodfillutil(int x, int y, int r, int g, int b);
    void on_boundaryfill_clicked();
    void boundaryfillutil(int x, int y, QRgb q, int r, int g, int b);
    void on_scanlinefill_clicked();
    void initEdgeTable();
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void on_setvertex_clicked();
    void on_clearvertex_clicked();
    void poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b);
    void on_translation_clicked();
    void on_scaling_clicked();
    void on_rotation_clicked();
    void on_shearing_clicked();
    void on_reflection_clicked();
    void on_setcorner1_clicked();
    void on_setcorner2_clicked();
    void draw_Window();
    int computeCode(int xa, int ya);
    void cohenSutherlandClip(int x1, int y1,int x2, int y2);
    void on_lineclipping_clicked();
    int x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    int y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    void clip(int x1, int y1, int x2, int y2);
    void suthHodgClip();
    void on_polygonclipping_clicked();
    void on_setbezpoint_clicked();
    void on_clearbezpoint_clicked();
    void on_drawBezierCurve_clicked();
private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    QPoint cp1,cp2;
    void point(int x,int y, int r, int g, int b);
};

#endif // MAINWINDOW_H
