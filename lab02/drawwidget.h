#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include <common.h>
#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>


class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = 0);
    ~DrawWidget();

    void setShapeType(ST::ShapeType type);//设置绘图类型
    ST::ShapeType shapeType();//利用枚举变量，返回当前绘图类型
    void setDrawnText(QString text);

/*************************************事件**********************************/
protected:
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent (QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent (QPaintEvent *);
    void resizeEvent (QResizeEvent *);

    void drawShape(const QPointF ptStart,const QPointF ptEnd,const ST::ShapeType drawType);
    QRectF textRect(const QPointF ptStart, const QPointF ptEnd, QString displayText, QFontMetrics fm);

signals:
public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void clear();
    void choseimage();

private :
    QPixmap *pix;//画板指针，画图形
    QPixmap *pic;//画板指针，画图片
    QPoint startpos;//绘图起点
    QPoint endpos;//绘图终点
    bool canDraw;//绘图标志，true：绘制，false:不绘制
    int style;
    int weight;
    QColor color;
    ST::ShapeType drawType;
    QString drawnText;
    QString filename;
};
#endif // DRAWWIDGET_H
