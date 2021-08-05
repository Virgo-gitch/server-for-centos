#ifndef MYDEFECTPOSLAB_H
#define MYDEFECTPOSLAB_H

#include <QLabel>
#include <QObject>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QMessageBox>

class myDefectPosLab : public QLabel
{
    Q_OBJECT
public:
    explicit myDefectPosLab(QWidget *parent=nullptr);
    ~myDefectPosLab();

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void getDefectInfo(const int, const int, const int, const std::string, const int, const int);

    void setDraw(const bool&);

signals:
    void drawMaskEnd(const QPoint&, const QPoint&, const int, const int, const int, const int);

public:
    int X, Y;
    bool bDraw;

private:
    QPoint sp, ep;
    int m_orient;
    int m_gifX, m_gifY;
    float res1, res3;
    int outW=0, outH=0;

};

#endif // MYDEFECTPOSLAB_H
