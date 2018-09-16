#include <QCoreApplication>
#include <QDebug>
#include <QList>

typedef quint32 word;
typedef quint8  byte;
#define WORD_LLO(xxx) ((byte) ((word)(xxx)& 255))                       //取最低8位
#define WORD_HLO(xxx) ((byte) ((word)(xxx)>> 8))                        //左移8位取次低8位
#define WORD_LHI(xxx) ((byte) ((word)(xxx)>> 16))                       //取次高8位
#define WORD_HHI(xxx) ((byte) ((word)(xxx)>> 24))                       //取最高8位

#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )                         //取最大值
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )                         //取最小值

int main(int argc, char *argv[])
{
    qint32 i=0x12345678;                                                //定义32位无符号数
   qDebug()<<"原始值：0x12345678="<<i;                                   //输出原始值及各位数字
   qDebug()<<"0x12="<<WORD_HHI(i);
   qDebug()<<"0x34="<<WORD_LHI(i);
   qDebug()<<"0x56="<<WORD_HLO(i);
   qDebug()<<"0x78="<<WORD_LLO(i);
   QList<qint8> values;
           values<<WORD_HHI(i)<<WORD_LHI(i)                             //存入values
                <<WORD_HLO(i)<<WORD_LLO(i);

   qDebug()<<"最高8位和次高8位最大值:0x34("                                //取高8位和次高8位最大值并输出
          <<MAX(WORD_HHI(i),WORD_LHI(i))<<")";
   qDebug()<<"次低8位和最低8位最小值：0x56("                               //取低8位和次低8位最小值并输出
          <<MIN(WORD_HLO(i),WORD_LLO(i))<<")";

   qDebug("重新组合后十六进制：0x%x",(WORD_HLO(i)<<24)                    //重新组合并输出
        +(WORD_HHI(i)<<16)+(WORD_LLO(i)<<8)+(WORD_LHI(i)));
   qDebug()<<"重新组合后十进制："<<(WORD_HLO(i)<<24)+(WORD_HHI(i)<<16)
             +(WORD_LLO(i)<<8)+(WORD_LHI(i));

   qDebug()<<"排序前："<<values;
   std::sort(values.begin(),values.end(),std::greater<quint8>());    //排序并输出
   qDebug()<<"排序后："<<values;

   QCoreApplication a(argc, argv);
   return a.exec();
}
