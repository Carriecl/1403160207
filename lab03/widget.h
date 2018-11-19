#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>


namespace Ui {
class Widget;
}
QT_CHARTS_USE_NAMESPACE

class dataWorker;
class QDateTime;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void resetChart(const QString &title);
    void initComboMonth();
    void initComboCity();
    void addLineSeries(QChart* chart, const QString &seriesName, const QColor color, const int lineWidth=1);      // 向Chart中添加序列（Series）
    void connectMarkers();          // 连接序列中所有Legend中Marker的信号与槽



private slots:          //槽函数
    void handleMarkerClicked();
    void on_btnStart_clicked();
    void updateDataChart(QList<QDateTime> date, QList<qreal> lineOne, QList<qreal> linetwo);
    void on_cbShowPoint_clicked();
    void on_btnLegendAlign_clicked();
    void on_cbLegendBold_clicked();
    void on_cbLegendItalic_clicked();
    void on_ButtonTemperature_clicked();    //查询温度单选框被按下
    void on_ButtonAQI_clicked();            //查询AQI单选框被按下
    void on_dataError(QString error);

private:
    Ui::Widget *ui;
    dataWorker* worker;
    QStringList citypinyin,city;       //城市拼音和城市名
    QStringList urlString;


};

#endif // WIDGET_H
