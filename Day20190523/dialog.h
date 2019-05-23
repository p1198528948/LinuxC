#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <stdio.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    // 测试标准C语言函数
    void testStdFunc();
};

#endif // DIALOG_H
