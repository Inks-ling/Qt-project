#include "timermainwindow.h"
#include "ui_timermainwindow.h"

TimerMainWindow::TimerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimerMainWindow)
{
    ui->setupUi(this);
    m_timerID = startTimer(1000);  // 启动定时器
    m_timer = new QTimer;  // 创建定时器
    m_timeCounter = new QTime;  // 创建计时器
    isStart = false;  // 开关初始化为未启动

    initTime();  // 初始化时间
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

TimerMainWindow::~TimerMainWindow()
{
    delete ui;
    killTimer(m_timerID);  // 销毁定时器
}
// 定时器事件处理函数
void TimerMainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    QTime curtime = QTime::currentTime();  // 获取系统当前时间
    ui->lcdHour->display(curtime.hour());
    ui->lcdMinute->display(curtime.second());
    ui->lcdSecond->display(curtime.minute());
}

// initTime()
void TimerMainWindow::initTime()
{
    m_timeCounter->setHMS(0, 0, 0);
    ui->lcdCounter->display(m_timeCounter->toString("HH:mm:ss:zzz"));
}

// 定时器到时
void TimerMainWindow::onTimeout(void)
{
    *m_timeCounter = m_timeCounter->addMSecs(1);
    ui->lcdCounter->display(m_timeCounter->toString("HH:mm:ss:zzz"));
}

// "开始"
void TimerMainWindow::on_buttonStart_clicked()
{
    if(!isStart){
        isStart = true;
        m_timer->start(1);  // 每个1毫秒启动定时器
        ui->buttonStart->setText("停止");
        ui->buttonEnd->setEnabled(false);
    }else{
        isStart = false;
        m_timer->stop();
        ui->buttonStart->setText("开始");
        ui->buttonEnd->setEnabled(true);
    }
}

// "复位"
void TimerMainWindow::on_buttonEnd_clicked()
{
    initTime();
}


