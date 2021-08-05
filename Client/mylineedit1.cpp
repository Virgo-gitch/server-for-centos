#include "mylineedit1.h"

myLineEdit1::myLineEdit1(QWidget *parent):
    QLineEdit(parent)
{

}


myLineEdit1::~myLineEdit1()
{

}


void myLineEdit1::focusInEvent(QFocusEvent *event)
{
    emit getFocus();
    QLineEdit::focusInEvent(event);
}
