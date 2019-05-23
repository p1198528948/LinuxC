#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    testStdFunc();
}

Dialog::~Dialog()
{
    delete ui;
}

/**
 * 主要是过一遍标准C语言的相关API
 * @brief Dialog::testStdFunc
 */
void Dialog::testStdFunc()
{
    // malloc() free()
    int *a = (int *)malloc(sizeof(int));
    *a = 200;
    qDebug() << QString("a addr is 0x%1")
                .arg(QString::number((unsigned int)a, 16));
    qDebug() << QString("a = %1").arg(*a);
    free(a);
    a = NULL;

    // memset
    char buffer[20];
    memset(buffer,0,sizeof(char)*20);
    memcpy(buffer,"123",3);
    //这一条的memset并不多余，memcpy并没把buffer全部覆盖，如果没有memset，
    //用printf打印buffer会有乱码甚至会出现段错误。
    //如果此处是strcpy(buffer,"123");便不用memset,
    //strcpy虽然不会覆盖buffer但是会拷贝字符串结束符

    // 这里的memset是多余的. 因为这块内存马上就被全部覆盖，清零没有意义.
    char buf[4];
    memset(buf,0,sizeof(char)*4);
    strcpy(buf,"123");
    //"123"中最后隐藏的'\0'占一位，总长4位。

    // memset
    char hello_buffer[] = "Helloworld\n";
    //printf("Buffer before memset:%s\n",hello_buffer);
    memset(hello_buffer,'*',strlen(hello_buffer));
    //printf("Buffer after  memset:%s\n",hello_buffer);

}
