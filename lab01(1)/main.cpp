#include <QCoreApplication>
#include <QString>
#include <Qdebug>
#include <Qvector>

class student
{
public:
    int num;
    QString name;
    int score1;
    int score2;
};

bool comparescore1(const student &student1,const student &student2)
{
   if(student1.score1>student2.score1)
       return true;
   if(student1.score1<student2.score1)
       return false;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //return a.exec();
    student stu1,stu2,stu3,stu4;
    stu1.num=1403130209;
    stu1.name="鲁智深";
    stu1.score1=80;
    stu1.score2=72;
    stu2.num=1403140101;
    stu2.name="林冲";
    stu2.score1=82;
    stu2.score2=76;
    stu3.num=1403140102;
    stu3.name="宋江";
    stu3.score1=76;
    stu3.score2=85;
    stu4.num=1403140103;
    stu4.name="武松";
    stu4.score1=88;
    stu4.score2=80;
    QVector<student> grade;
    grade<<stu1<<stu2<<stu3<<stu4;
    std::sort(grade.begin(),grade.end(),comparescore1);
    qDebug()<<"/******************************************/"<<
              "\n"<<"按照课程1得分排序：";
    for(int i=0;i<4;i++)
    {
        qDebug()<<grade.at(i).num<<"\t"<<grade.at(i).name<<
                  "\t"<<grade.at(i).score1<<"\t"<<grade.at(i).score2;
    }
}
