#ifndef CENTERFRAME_H
#define CENTERFRAME_H
#include <QFrame>
#include <common.h>


class QVBoxLayout;
class QHBoxLayout;
class DrawWidget;
class QGroupBox;
class QPushButton;
class QLineEdit;

//绘图框架类
class CenterFrame : public QFrame
{
    Q_OBJECT
public:
    explicit CenterFrame(QWidget *parent=0);//创建用户中心窗口区

    DrawWidget* insideWidget() const;//获取绘图区绘图对象的指针

protected:

    void createUserCommandArea();//创建绘图框的用户命令区

    void createUI();//创建用户界面

    void updateButtonStatus();//更新按键状态


public slots:
    void setPenStyle(int penStyle);
    void setPenWidth(int width=1);
    void setPenColor(QColor color);
    void clearPaint();
    void showimage();//画图


//按键响应槽函数
protected slots:
    void on_btnRectClicked();
    void on_btnEllipseClicked();
    void on_btnLineClicked();
    void on_btnTriangleClicked();
    void on_btnTextClicked();//绘制文本按键
    void on_edtTextEdited(const QString &text);//输入文本
    void on_btnDiamondClicked();


private:
    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    DrawWidget* drawWidget;
    QGroupBox* group;

    QPushButton* btnRect;
    QPushButton* btnEllipse;
    QPushButton* btnLine;
    QPushButton* btnTriangle;
    QPushButton* btnDiamond;
    QPushButton* btnText;
    QLineEdit* edtText;



};

#endif // CENTERFRAME_H
