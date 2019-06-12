#include "interactiveiot.h"

InteractiveIot::InteractiveIot(QString JsonRooms,IoT* eDevice, QWidget *parent):QWidget (parent)
{
    statusButtons = nullptr;
    statusSliders = nullptr;
    name = setQLabel("Name");
    room = setQLabel("Room");
    serial = setQLabel("Serial");
    lClass = setQLabel("Type");
    e_name= new QLineEdit(this);
    e_room= new QComboBox(this);
    e_serial= new QLineEdit(this);
    classChoose = new QComboBox(this);
    wlayout = new QFormLayout(this);
    std::list<std::string> dlist = IoTBuilder::getKeys();
    if(eDevice !=nullptr){
        device = eDevice;
    }else{
        device = IoTBuilder::getDevice(QJsonDocument::fromJson("{\"class\":\"dimmerableLight\",\"name\": \"Change me\", \"room\": \"Change me\", \"serial\": \"Change me\"}"));
    }
    devcurrent = device->JsonSerialize().object();
    dserial = QString::fromStdString(device->getSerial());
    setUpDefault();
    foreach(const std::string& key, dlist){
        classChoose->addItem(tr(key.c_str()));
        if(device->getClass() == key){
            classChoose->setCurrentIndex(classChoose->findText(tr(key.c_str())));
        }
    }
    QJsonDocument jrooms = QJsonDocument::fromJson(JsonRooms.toUtf8());
    QJsonArray rooms(jrooms.object()["rooms"].toArray());
    e_room->addItem(tr("Change me"));
    foreach(auto room, rooms){
        e_room->addItem(room.toString());
        if(device->getRoom() == room.toString().toStdString()){
            e_room->setCurrentIndex(e_room->findText(room.toString()));
        }
    }
    e_room->setEditable(true);
    if(eDevice !=  nullptr){
        e_serial->setDisabled(true);
        classChoose->setDisabled(true);
    }
    connect(classChoose,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(setClass(const QString&)));
    connect(e_room,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(setRoom(const QString&)));
    done = new QPushButton(tr("Done"));
    connect(done,SIGNAL(clicked(bool)),this,SLOT(setDone()));
    setStatusEditor();
    wlayout->addItem(createGroup(lClass,classChoose));
    wlayout->addItem(createGroup(room,e_room));
    wlayout->addItem(createGroup(name,e_name));
    wlayout->addItem(createGroup(serial,e_serial));
    wlayout->addWidget(done);
    wlayout->addWidget(e_status);
    this->setLayout(wlayout);
}

QLabel* InteractiveIot::setQLabel(QString text){
    QLabel* local = new QLabel(text,this);
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
    e_status = new QGroupBox(tr("Status"),this);
    QVBoxLayout* s_layout = new QVBoxLayout(e_status);
    if(statusButtons != nullptr){
        delete statusButtons;
        statusButtons = nullptr;
    }
    if(statusSliders != nullptr){
        delete statusSliders;
        statusSliders = nullptr;
    }

    foreach(const auto key,instruction.keys()){
        QLabel * field = new QLabel(key,e_status);
        s_layout->addWidget(field);
        if((instruction.value(key).toObject().value(tr("max")).toInt()-instruction.value(key).toObject().value(tr("min")).toInt())==1){
            QPushButton* button = new QPushButton(e_status);
            button->setCheckable(true);
            button->setDown(static_cast<bool>(devcurrent["status"].toObject()[key].toInt()));
            button->setStyleSheet("QPushButton{background-color:green;}QPushButton:checked{background-color:red;}");
            s_layout->addWidget(button);
            if(statusButtons == nullptr)
                statusButtons = new QMap<QString,QPushButton*>();
            statusButtons->insert(key,button);
            connect(button,SIGNAL(toggled(const bool)),this,SLOT(statusProxyButton(const bool)));
        }
        if((instruction.value(key).toObject().value(tr("max")).toInt()-instruction.value(key).toObject().value(tr("min")).toInt())>1){
            QSlider* slider = new QSlider(Qt::Orientation::Horizontal,e_status);
            slider->setMinimum(instruction.value(key).toObject().value(tr("min")).toInt());
            slider->setMaximum(instruction.value(key).toObject().value(tr("max")).toInt());
            slider->setValue(devcurrent["status"].toObject()[key].toInt());
            s_layout->addWidget(slider);
            if(statusSliders == nullptr)
                statusSliders = new QMap<QString,QSlider*>();
            statusSliders->insert(key,slider);
            connect(slider,SIGNAL(valueChanged(int)),this,SLOT(statusProxySlider(const int)));
        }
    }
    e_status->setLayout(s_layout);
    e_status->update();
}

void InteractiveIot::setUpDefault(){
    e_name->setText(tr(device->getName().c_str()));
    e_name->setAlignment(Qt::AlignRight);
    e_name->setStyleSheet("QLineEdit{width:100px;}");
    connect(e_name, SIGNAL(textChanged(const QString &)),this,SLOT(setName(const QString&)));

    e_serial->setText(dserial);
    e_serial->setAlignment(Qt::AlignRight);
    connect(e_serial, SIGNAL(textChanged(const QString &)),this,SLOT(setSerial(const QString&)));
}

void InteractiveIot::setName(const QString& s_name){
    device->setName(s_name.toStdString());
    devcurrent = device->JsonSerialize().object();
}

void InteractiveIot::setRoom(const QString& s_Room){
    device->setRoom(s_Room.toStdString());
    devcurrent = device->JsonSerialize().object();
}

void InteractiveIot::setStatus(const QJsonDocument& s_status){
    device->setDevice(s_status);
    devcurrent = device->JsonSerialize().object();
}

void InteractiveIot::setSerial(const QString& s_serial){
    //dserial = s_serial;
    devcurrent["serial"] = s_serial;
    delete device;
    device = IoTBuilder::getDevice(QJsonDocument(devcurrent));
}

void InteractiveIot::setClass(const QString& dClass){
    this->dClass = dClass;
    devcurrent["class"] = dClass;
    delete device;
    device = IoTBuilder::getDevice(QJsonDocument(devcurrent));
    lupdate();
}

void InteractiveIot::lupdate(){
    this->layout()->removeWidget(e_status);
    clearLayout(e_status->layout());
    delete e_status;
    setUpDefault();
    setStatusEditor();
    setUpdatesEnabled(true);
    this->layout()->addWidget(e_status);
    update();
}

void InteractiveIot::clearLayout(QLayout* to_clean){
    if(to_clean == nullptr)
        return;
    QLayoutItem* element;
    while((element = to_clean->takeAt(0))){
        if(element->layout() != nullptr)
            clearLayout(element->layout());
        if(element->widget() != nullptr){

            delete element->widget();
        }
        delete element;

    }
    delete to_clean;
}
void InteractiveIot::setDone(){
    QString jdevice(QJsonDocument(devcurrent).toJson());
    if(devcurrent["name"].toString().toStdString() == "Change me"){
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Name is not valid");
        messageBox.setFixedSize(500,200);
    }
    else if(devcurrent["room"].toString().toStdString() == "Change me"){
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Room is not valid");
        messageBox.setFixedSize(500,200);
    }
    else if(devcurrent["serial"].toString().toStdString() == "Change me"){
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Serial is not valid");
        messageBox.setFixedSize(500,200);
    }else {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error",jdevice);
        messageBox.setFixedSize(500,200);
        emit newDevice(jdevice);
        //delete this->device;
        //this->close();
    }
}

void InteractiveIot::statusProxyButton(const bool status){
    QString key = statusButtons->key(dynamic_cast<QPushButton*>(sender()));
    devcurrent["status"].toObject()[key] = static_cast<int>(status);
    setStatus(QJsonDocument(devcurrent));
}

void InteractiveIot::statusProxySlider(const int status){
    QString key = statusSliders->key(dynamic_cast<QSlider*>(sender()));
    devcurrent["status"].toObject()[key] = static_cast<int>(status);
    setStatus(QJsonDocument(devcurrent));
}

InteractiveIot::~InteractiveIot(){

    if(statusSliders){
        qDeleteAll(*statusSliders);
        statusSliders->clear();
        delete statusSliders;
    }
    if(statusButtons){
        qDeleteAll(*statusButtons);
        statusButtons->clear();
        delete statusButtons;
    }
    if(device)
        delete device;
}
