#include <QCoreApplication>
#include <QString>
#include <Qdebug>
#include <Qvector>

class student                           //创建一个类，定义数据类型
{
public:
    int num;
    QString name;
    int score1;
    int score2;
};

bool comparescore1(const student &student1,const student &student2)         //定义三个比较函数，比较各项数据
{
   if(student1.score1>student2.score1)
       return true;
   if(student1.score1<student2.score1)
       return false;
}
bool comparescore2(const student &student1,const student &student2)
{
   if(student1.score2>student2.score2)
       return true;
   if(student1.score2<student2.score2)
       return false;
}
bool comparename(const student &student1,const student &student2)
{
    if(student1.name<student2.name)
        return true;
    if(student1.name>student2.name)
        return false;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //return a.exec();
    student stu1,stu2,stu3,stu4;                        //定义四个类，开始录入原始数据
    stu1.num=1403130209;
    stu1.name="lzs鲁智深";
    stu1.score1=80;
    stu1.score2=72;
    stu2.num=1403140101;
    stu2.name="lc林冲";
    stu2.score1=82;
    stu2.score2=76;
    stu3.num=1403140102;
    stu3.name="sj宋江";
    stu3.score1=76;
    stu3.score2=85;
    stu4.num=1403140103;
    stu4.name="ws武松";
    stu4.score1=88;
    stu4.score2=80;
    QVector<student> grade;                     //定义一个vector容器，将四个类放入其中
    grade<<stu1<<stu2<<stu3<<stu4;
    qDebug()<<"排序前原始信息为：";                //输出原始数据
    for(int i=0;i<4;i++)
    {
        qDebug()<<grade.at(i).num<<"\t"<<grade.at(i).name<<
                  "\t"<<grade.at(i).score1<<"\t"<<grade.at(i).score2;
    }
    std::sort(grade.begin(),grade.end(),comparescore1);                 //利用sort函数进行排序并且输出
    qDebug()<<"———————————————————————————————————————————————————————————"<<
              "\n"<<"按照课程1得分排序：";
    for(int i=0;i<4;i++)
    {
        qDebug()<<grade.at(i).num<<"\t"<<grade.at(i).name<<
                  "\t"<<grade.at(i).score1<<"\t"<<grade.at(i).score2;
    }
    std::sort(grade.begin(),grade.end(),comparescore2);
    qDebug()<<"———————————————————————————————————————————————————————————"<<
              "\n"<<"按照课程2得分排序：";
    for(int i=0;i<4;i++)
    {
        qDebug()<<grade.at(i).num<<"\t"<<grade.at(i).name<<
                  "\t"<<grade.at(i).score1<<"\t"<<grade.at(i).score2;
    }
    std::sort(grade.begin(),grade.end(),comparename);
    qDebug()<<"———————————————————————————————————————————————————————————"<<
              "\n"<<"按照姓名排序：";
    for(int i=0;i<4;i++)
    {
        qDebug()<<grade.at(i).num<<"\t"<<grade.at(i).name<<
                  "\t"<<grade.at(i).score1<<"\t"<<grade.at(i).score2;
    }
}
