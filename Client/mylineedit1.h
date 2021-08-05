#ifndef MYLINEEDIT1_H
#define MYLINEEDIT1_H

#include <QLineEdit>
#include <QFocusEvent>

class myLineEdit1 : public QLineEdit
{
    Q_OBJECT
public:
    explicit myLineEdit1(QWidget *parent=nullptr);
    ~myLineEdit1();

protected:
    void focusInEvent(QFocusEvent *event);

signals:
    void getFocus();
};

#endif // MYLINEEDIT1_H
