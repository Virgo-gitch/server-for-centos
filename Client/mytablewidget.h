#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QTableWidget>
#include <QMouseEvent>
#include <QTimer>



class myTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit myTableWidget(QWidget *parent=nullptr);
    ~myTableWidget();
    QTimer *timer;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void enterEvent(QEvent *event) override;

    void leaveEvent(QEvent *event) override;

signals:
    void cellRightClick(QTableWidgetItem *item);

    void mouseHover(QTableWidgetItem *item, QPoint& point);

private:
    QString previouText;
    QTableWidgetItem *item;
    QPoint showPoint;


public slots:
    void timetest();

};

#endif // MYTABLEWIDGET_H
