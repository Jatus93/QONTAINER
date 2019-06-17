#ifndef INTERACTIVEIOT_H
#define INTERACTIVEIOT_H
#include <QWidget>
#include <QLabel>
#include <iotbuilder.h>
#include <QGroupBox>
#include <QFormLayout>
#include <QToolBox>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QPushButton>
#include <QSlider>
#include <QJsonArray>
#include <QLCDNumber>
class InteractiveIot : public QDialog
{
    Q_OBJECT
public:
    InteractiveIot(QString JsonRooms ,QString eDevice="", QWidget *parent =nullptr);
    ~InteractiveIot();
signals:
    void newDevice(QString device);
    void closing();
private:
    QBoxLayout* createGroup(QWidget* first, QWidget* second);
    QLabel* setQLabel(QString text);
    void setUpDefault();
    void clearLayout(QLayout* to_clean);
    void lupdate();
    void closeEvent(QCloseEvent* event);

private slots:
    void setStatusEditor();
    void setName(const QString& s_name);
    void setRoom(const QString& s_Room);
    void setStatus(const QJsonDocument& s_status);
    void setSerial(const QString& s_serial);
    void setClass(const QString& dClass);
    void statusProxyButton(const bool status);
    void statusProxySlider(const int status);
    void setDone();
private:
    QString dClass;
    QString dserial;
    IoT* device;
    QLabel *name;
    QLabel *room;
    QLabel *serial;
    QMap<QString,QPushButton*>* statusButtons;
    QMap<QString,QSlider*>* statusSliders;
    QPushButton* done;
    QLineEdit* e_name;
    QComboBox *e_room;
    QGroupBox *e_status;
    QLineEdit *e_serial;
    QComboBox * classChoose;
    QFormLayout *wlayout;
    QLabel * lClass;
    QJsonObject devcurrent;
};

#endif // INTERACTIVEIOT_H