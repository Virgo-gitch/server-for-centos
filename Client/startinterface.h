#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

#include <QWidget>

namespace Ui {
class startInterface;
}

class startInterface : public QWidget
{
    Q_OBJECT

public:
    explicit startInterface(QWidget *parent = nullptr);
    ~startInterface();

public slots:
    void getCurrentValue(int);

private:
    Ui::startInterface *ui;
};

#endif // STARTINTERFACE_H
