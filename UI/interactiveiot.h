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
class InteractiveIot : public QWidget
{
    Q_OBJECT
public:
    InteractiveIot(IoT * eDevice=nullptr, QWidget *parent =nullptr);

private:
    QBoxLayout* createGroup(QWidget* first, QWidget* second);
    QLabel* setQLabel(QString text);
    void setUpDefault();
    //void localSetLayout();
    void lupdate();

private slots:
    void setStatusEditor();
    void setName(const QString& s_name);
    void setRoom(const QString& s_Room);
    void setStatus(const QJsonDocument& s_status);
    void setSerial(const QString& s_serial);
    void setClass(const QString& dClass);
private:
    QString dClass;
    QString dserial;
    IoT* device;
    QLabel *name;
    QLabel *room;
    QLabel *status;
    QLabel *serial;
    QLineEdit* e_name;
    QLineEdit *e_room;
    QLayout *e_status;
    QLineEdit *e_serial;
    QComboBox * classChoose;
    QFormLayout *layout;
    QLabel * lClass;
};

#endif // INTERACTIVEIOT_H
