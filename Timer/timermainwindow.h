#ifndef TIMERMAINWINDOW_H
#define TIMERMAINWINDOW_H

#include <QMainWindow>
#include <QTime>  // 时间类
#include <QTimer>  // 定时器类

namespace Ui {
class TimerMainWindow;
}

class TimerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TimerMainWindow(QWidget *parent = nullptr);
    ~TimerMainWindow();
protected:
    void timerEvent(QTimerEvent* event);  // 定时器时间处理类
private slots:
    void onTimeout(void);  // 定时器到时函数
    void on_buttonStart_clicked();  // 启动计时器
    void on_buttonEnd_clicked();  // 复位计时器

private:
    void initTime();  // 初始化时间
private:
    Ui::TimerMainWindow *ui;
    int m_timerID;         // 定时器ID

    QTimer* m_timer;       // 定时器
    QTime* m_timeCounter;  // 计时器
    bool isStart;          // 计时器是否启动
};

#endif // TIMERMAINWINDOW_H
