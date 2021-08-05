#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
public:
    explicit MyLabel(QWidget *parent=nullptr);
    ~MyLabel();
    bool m_stop;
    qreal maskWidth;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void onTimeout();

private:
    QLinearGradient linegradient, masklinegradient;

};

#endif // MYLABEL_H
