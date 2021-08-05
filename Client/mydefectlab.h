#ifndef MYDEFECTLAB_H
#define MYDEFECTLAB_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <jsonFun.h>


class MyDefectLab : public QLabel
{


public:
    MyDefectLab(QWidget *parent = nullptr);
    ~MyDefectLab();
    QList<QPoint> coordinates;
    void clearPoly();

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void getInfo(static_info&, int, int, QRect&);

    void getDefectCoordinates(const QList<QPoint>&, const int, const QVector<QPolygon>&);

    void getNextCricle(int);

private:
    int curCricle;
    int rotateValue;
    void  getCoordinate(static_info&, int, int, int, int, float, float);
    QVector<QPolygon> m_polygon;

};

#endif // MYDEFECTLAB_H
