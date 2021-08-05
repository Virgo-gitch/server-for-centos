#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent):
    QTextEdit(parent)
{

}

myLineEdit::~myLineEdit()
{

}

void myLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit editDoubleClicked();
    QTextEdit::mouseDoubleClickEvent(event);
}

