#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QTextEdit>

class myLineEdit : public QTextEdit
{
    Q_OBJECT;
public:
    explicit myLineEdit(QWidget *parent=nullptr);
    ~myLineEdit();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);


signals:
    void editDoubleClicked();

};

#endif // MYLINEEDIT_H
