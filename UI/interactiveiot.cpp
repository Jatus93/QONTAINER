#include "interactiveiot.h"

InteractiveIot::InteractiveIot(IoT* eDevice, QWidget *parent):QWidget (parent)
{
    name = setQLabel("Nome");
    room = setQLabel("Stanza");
    serial = setQLabel("Seriale");
    lClass = setQLabel("Type");
    status = setQLabel("Status corrente");
    e_name= new QLineEdit;
    e_room= new QLineEdit;
    e_serial= new QLineEdit;
    classChoose = new QComboBox;
    layout = new QFormLayout();
    std::list<std::string> dlist = IoTBuilder::getKeys();
    if(eDevice !=nullptr){
        device = eDevice;
    }else{
        device = IoTBuilder::getDevice(QJsonDocument::fromJson("{\"class\":\"dimmerableLight\",\"name\": \"Change me\", \"room\": \"Change me\", \"serial\": \"Change me\"}"));
    }
    dserial = QString::fromStdString(device->getSerial());
    setUpDefault();
    foreach(const std::string& key, dlist){
        classChoose->addItem(tr(key.c_str()));
        if(device->getClass() == key){
            classChoose->setCurrentIndex(classChoose->findText(tr(key.c_str())));
        }
    }
    if(eDevice !=  nullptr){
        e_serial->setDisabled(true);
        classChoose->setDisabled(true);
    }
    connect(classChoose,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(setClass(const QString&)));
    setStatusEditor();
    layout->addItem(createGroup(lClass,classChoose));
    layout->addItem(createGroup(name,e_name));
    layout->addItem(createGroup(room,e_room));
    layout->addItem(createGroup(serial,e_serial));
    layout->addWidget(status);
    layout->addItem(e_status);
    this->setLayout(layout);
    this->show();

}

QLabel* InteractiveIot::setQLabel(QString text){
    QLabel* local = new QLabel(text);
    local->setAlignment(Qt::AlignLeft);
    return local;
}

QBoxLayout* InteractiveIot::createGroup(QWidget* first, QWidget* second){
    QBoxLayout* local = new QBoxLayout(QBoxLayout::LeftToRight);
    local->addWidget(first);
    local->addWidget(second);
    return local;
}

void InteractiveIot::setStatusEditor(){
    QJsonObject instruction(device->getDeviceInstruction().object());
    e_status = new QBoxLayout(QBoxLayout::BottomToTop);
    foreach(const auto key,instruction.keys()){
       if((instruction.value(key).toObject().value(tr("max")).toInt()-instruction.value(key).toObject().value(tr("min")).toInt())==1){
           QPushButton* button = new QPushButton();
           button->setCheckable(true);
           button->setDown(false);
           button->setStyleSheet("QPushButton{background-color:green;}QPushButton:checked{background-color:red;}");
           e_status->addWidget(button);
       }
       if((instruction.value(key).toObject().value(tr("max")).toInt()-instruction.value(key).toObject().value(tr("min")).toInt())>1){
           QSlider* slider = new QSlider(Qt::Orientation::Horizontal);
           slider->setMinimum(instruction.value(key).toObject().value(tr("min")).toInt());
           slider->setMaximum(instruction.value(key).toObject().value(tr("max")).toInt());
           e_status->addWidget(slider);
       }
       e_status->addWidget(new QLabel(key));
    }
}

void InteractiveIot::setUpDefault(){
    e_name->setText(tr(device->getName().c_str()));
    e_name->setAlignment(Qt::AlignRight);
    e_name->setStyleSheet("QLineEdit{width:100px;}");
    connect(e_name, SIGNAL(textChanged(const QString &)),this,SLOT(setName(const QString&)));
    e_room->setText(tr(device->getRoom().c_str()));
    e_room->setAlignment(Qt::AlignRight);
    connect(e_room, SIGNAL(textChanged(const QString &)),this,SLOT(setRoom(const QString&)));
    e_serial->setText(dserial);
    e_serial->setAlignment(Qt::AlignRight);
    connect(e_serial, SIGNAL(textChanged(const QString &)),this,SLOT(setSerial(const QString&)));
}

void InteractiveIot::setName(const QString& s_name){
    device->setName(s_name.toStdString());
}

void InteractiveIot::setRoom(const QString& s_Room){
    device->setRoom(s_Room.toStdString());
}

void InteractiveIot::setStatus(const QJsonDocument& s_status){
    device->setDevice(s_status);
}

void InteractiveIot::setSerial(const QString& s_serial){
    dserial = s_serial;
}

void InteractiveIot::setClass(const QString& dClass){
    this->dClass = dClass;
    QJsonObject dev = device->JsonSerialize().object();
    dev["class"] = dClass;
    dev["serial"] = dserial;
    QJsonDocument doc(dev);
    delete device;
    device = IoTBuilder::getDevice(doc);
    lupdate();
}

void InteractiveIot::lupdate(){
    layout->removeItem(e_status);
    setUpDefault();
    setStatusEditor();
    setUpdatesEnabled(true);
}
