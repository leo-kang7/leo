#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QButtonGroup>
#include <QMainWindow>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QString>
#include<QStack>
#include<QTime>
#include<iterator>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString input2;
public:
    QButtonGroup input;
    QButtonGroup output;
    QString data_input;
    QString data_output;
    int code_input;
    int code_resu;
    int start;
    QString resu;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    //进制转换
    void on_lineEdit_input_textChanged(const QString &arg1);
    void print_resu();
    void code_change();

      void num0Clicked();
      void num1Clicked();
      void num2Clicked();
      void num3Clicked();
      void num4Clicked();
      void num5Clicked();
      void num6Clicked();
      void num7Clicked();
      void num8Clicked();
      void num9Clicked();

      void plusClicked();//+
      void minClicked();//-
      void mulClicked();//乘
      void divClicked();//除
      void dotClicked();//小数点
      void fuClicked(); //正负号

      void equalClicked();//等于号

      void leftClicked();//左括号
      void rightClicked();//右括号

      void deleteClicked();//DEL
      void clearClicked();//AC
      void sinClicked();
      void cosClicked();
      void logClicked();
private:
    Ui::MainWindow *ui;
    void system_init();
};

#endif // MAINWINDOW_H
