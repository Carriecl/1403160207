#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QStringList>

typedef quint32 word;
typedef quint8  byte;
#define WORD_LLO(xxx) ((byte) ((word)(xxx)& 255))  //取最低8位
#define WORD_HLO(xxx) ((byte) ((word)(xxx)>> 8))   //左移8位取次低8位
#define WORD_LHI(xxx) ((byte) ((word)(xxx)>> 16))  //取次高8位
#define WORD_HHI(xxx) ((byte) ((word)(xxx)>> 24))  //取最高8位
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )


int main(int argc, char *argv[])
{
    qint32 i=0x12345678;                           //定义32位无符号数
   qDebug()<<"原始值：0x12345678="<<i;
   qDebug()<<"0x12="<<WORD_HHI(i);
   qDebug()<<"0x34="<<WORD_LHI(i);
   qDebug()<<"0x56="<<WORD_HLO(i);
   qDebug()<<"0x78="<<WORD_LLO(i);

   QCoreApplication a(argc, argv);
   return a.exec();
}
