#include "ModelData.h"

ModelData* ModelData::m_instantce = nullptr;


ModelData::ModelData(QObject *parent) : QObject(parent)
{
    m_pointerMode = static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_OFF);
    m_activedDeviced = -1;
    initObjects();
    m_capNormalTimer.setSingleShot(true);
    m_capAbnormalTimer.setSingleShot(true);
    m_capNormalTimer.setInterval(800);
    m_capAbnormalTimer.setInterval(800);
    QObject::connect(&m_capNormalTimer,SIGNAL(timeout()),this,SLOT(onCapNormalTimerTrigged()));
    QObject::connect(&m_capAbnormalTimer,SIGNAL(timeout()),this,SLOT(onCapAbnormalTimerTrigged()));
}

ModelData::~ModelData()
{
    if(m_instantce != nullptr){
        delete  m_instantce;
    }
}

void ModelData::updateActivedDevice(bool actived, int index, int posConnectedWire, int negaConnectedWire, int extConnectedWire)
{
    DLT_LOG << " actived: " << actived
            << " index: " << index
            << " posConnectedWire: " << posConnectedWire
            << " negaConnectedWire: " << negaConnectedWire
            << " extConnectedWire: " << extConnectedWire;
    if(actived){
        switch (index) {
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_1):
            handleActivedRes1();
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_2):
            handleActivedRes2();
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_1):
            handleActivedCapNormal(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_2):
            handleActivedCapAbnormal(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_3):
            handleActivedCapError(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_1):
            handleActivedConductorNormal();
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_2):
            handleActivedConductorError();
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_DIODE):
            handleActivedDiode(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_TRANSISTOR):
            handleActivedTransistor(posConnectedWire,negaConnectedWire,extConnectedWire);
            break;
        default:
            break;
        }
    }else{
        updateStateOfDeActviedMultimeter();
    }
    
}

void ModelData::handleActivedRes1()
{
    switch (this->pointerMode()) {
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-42));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-29));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(41));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(44.5));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}

void ModelData::handleActivedRes2()
{
    switch (this->pointerMode()) {
        case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-45));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-42));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(15.2));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(41));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}

void ModelData::handleActivedCapNormal(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
    switch (this->pointerMode()) {
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        DLT_LOG << "0.1";
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(43));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        m_capNormalTimer.start();
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(20));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        m_capNormalTimer.start();
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-20));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        m_capNormalTimer.start();
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-43));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        m_capNormalTimer.start();
        break;
    default:
        break;
    }
}

void ModelData::handleActivedCapAbnormal(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
    if(m_pointerMode >= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R) &&
       m_pointerMode <= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R)){
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(45));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        m_capAbnormalTimer.start();
    }
}

void ModelData::handleActivedCapError(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
    if(m_pointerMode >= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R) &&
       m_pointerMode <= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R)){
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(45));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
    }
}

void ModelData::handleActivedConductorNormal()
{
    DLT_LOG;
    switch (this->pointerMode()) {
        case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-42));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-29));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(40.5));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(44));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}

void ModelData::handleActivedConductorError()
{
    DLT_LOG;
}

void ModelData::handleActivedDiode(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
        if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
           negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK))
        {
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }else if (posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                  negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED)) {
            DLT_LOG << "m_pointerMode: " << m_pointerMode;
            if(m_pointerMode >= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R) &&
               m_pointerMode <= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R)){
                m_multimeter->setProperty("runningAnimation",QVariant(false));
                m_multimeter->setProperty("nextRotation",QVariant(45));
                m_multimeter->setProperty("runningAnimation",QVariant(true));
            }else{
                DLT_LOG << "1: ";
                m_multimeter->setProperty("runningAnimation",QVariant(false));
                m_multimeter->setProperty("nextRotation",QVariant(-45));
                m_multimeter->setProperty("runningAnimation",QVariant(true));
            }
        }
}

void ModelData::handleActivedTransistor(int posConnectedWire, int negaConnectedWire, int extConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire << " >> extConnectedWire: " << extConnectedWire;
    if(m_pointerMode >= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R) &&
       m_pointerMode <= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R)){
        if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE)){
            DLT_LOG << "TH1: Que do vao Chan E, Que den vao C";
            DLT_LOG << "Hien tuong: Kim khong nhich";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                 negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE) &&
                 extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK)){
            DLT_LOG << "TH2: Que do vao Chan E, Que den vao B";
            DLT_LOG << "Hien tuong: Kim len vi tri 30";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            switch (this->pointerMode()) {
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
                m_multimeter->setProperty("nextRotation",QVariant(0));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
                m_multimeter->setProperty("nextRotation",QVariant(-10));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
                m_multimeter->setProperty("nextRotation",QVariant(-30));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
                m_multimeter->setProperty("nextRotation",QVariant(-40));
                break;
            default:
                m_multimeter->setProperty("nextRotation",QVariant(-45));
                break;
            }
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                 negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                 extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE)){
            DLT_LOG << "TH3: Que den vao Chan E, Que do vao C";
            DLT_LOG << "Hien tuong: Kim khong nhich";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
        else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED)){
            DLT_LOG << "TH4: Que den vao Chan E, Que do vao B";
            DLT_LOG << "Hien tuong: Kim khong nhich";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
        else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK)){
            DLT_LOG << "TH5: Que do vao chan C, Que den vao B";
            DLT_LOG << "Hien tuong: Kim len";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            switch (this->pointerMode()) {
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
                m_multimeter->setProperty("nextRotation",QVariant(-10));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
                m_multimeter->setProperty("nextRotation",QVariant(-35));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
                m_multimeter->setProperty("nextRotation",QVariant(-40));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
                m_multimeter->setProperty("nextRotation",QVariant(-44));
                break;
            default:
                m_multimeter->setProperty("nextRotation",QVariant(-45));
                break;
            }
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
        else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_NONE) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED)){
            DLT_LOG << "TH6: Que den vao chan C, que do vao chan B";
            DLT_LOG << "Hien tuong: Kim khong nhich";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
        else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_FINGER)){
            DLT_LOG <<"TH P1: Que den vao chan C, que do vao chan E, dong thoi cham ngon tay vao chan B.";
            DLT_LOG << "Hien tuong: Kim len vi tri 40.";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            switch (this->pointerMode()) {
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
                m_multimeter->setProperty("nextRotation",QVariant(-10));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
                m_multimeter->setProperty("nextRotation",QVariant(-35));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
                m_multimeter->setProperty("nextRotation",QVariant(-40));
                break;
            case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
                m_multimeter->setProperty("nextRotation",QVariant(-44));
                break;
            default:
                m_multimeter->setProperty("nextRotation",QVariant(-45));
                break;
            }
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
        else if(posConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_BLACK) &&
                negaConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_RED) &&
                extConnectedWire == static_cast<int>(App_Enum::E_WIRE_TYPE_FINGER)){
            DLT_LOG <<"TH P2: Que do vao chan C, que den vao E, dong thoi cham ngon tay vao chan B.";
            DLT_LOG <<"Hien tuong: Kim khong nhich";
            m_multimeter->setProperty("runningAnimation",QVariant(false));
            m_multimeter->setProperty("nextRotation",QVariant(-45));
            m_multimeter->setProperty("runningAnimation",QVariant(true));
        }
    }
}

void ModelData::updateStateOfDeActviedMultimeter()
{
    DLT_LOG;
    m_multimeter->setProperty("runningAnimation",QVariant(false));
    m_multimeter->setProperty("nextRotation",QVariant(-45));
    m_multimeter->setProperty("runningAnimation",QVariant(true));
}

void ModelData::updateStateOfActviedMultimeter()
{
    DLT_LOG;
    if(this->pointerMode() >= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R) &&
            this->pointerMode() <= static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R)){
        this->updateActivedDevice(true,
                                  this->activedDeviced(),
                                  this->listModel().at(this->activedDeviced())->property("posConnectedWire").toInt(),
                                  this->listModel().at(this->activedDeviced())->property("negaConnectedWire").toInt(),
                                  this->listModel().at(this->activedDeviced())->property("extConnectedWire").toInt());
    }else{
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-45));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
    }
}


QObject *ModelData::resistor1()
{
    return m_resistor1;
}

QObject *ModelData::resistor2()
{
    return m_resistor2;
}

QObject *ModelData::capictor_normal()
{
    return m_capictor_normal;
}

QObject *ModelData::capictor_abnormal()
{
    return m_capictor_abnormal;
}

QObject *ModelData::cappictor_error()
{
    return m_cappictor_error;
}

QObject *ModelData::condutor_normal()
{
    return m_condutor_normal;
}

QObject *ModelData::condutor_error()
{
    return  m_condutor_error;
}

QObject *ModelData::diode()
{
    return m_diode;
}

QObject *ModelData::transistor()
{
    return m_transistor;
}

QObject *ModelData::multimeter()
{
    return m_multimeter;
}

QList<QObject *> ModelData::listModel()
{
    if(m_listModel.count() == 0){
        m_listModel.append(m_resistor1);
        m_listModel.append(m_resistor2);
        m_listModel.append(m_capictor_normal);
        m_listModel.append(m_capictor_abnormal);
        m_listModel.append(m_cappictor_error);
        m_listModel.append(m_condutor_normal);
        m_listModel.append(m_condutor_error);
        m_listModel.append(m_diode);
        m_listModel.append(m_transistor);
    }
    return m_listModel;
}

QString ModelData::fingerSource()
{
    return QString("file:///" + QDir::currentPath() + "/Image/finger.png");
}

QString ModelData::logoSource()
{
    return QString("file:///" + QDir::currentPath() + "/Image/logo.jpg");
}

int ModelData::pointerMode()
{
    return m_pointerMode;
}

void ModelData::setPointerMode(int _mode)
{
    if(m_pointerMode != _mode){
        DLT_LOG << _mode;
        m_pointerMode = _mode;
        emit pointerModeChanged();

        bool existActivedDevice =   m_activedDeviced >= static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_1) &&
                m_activedDeviced <= static_cast<int>(App_Enum::E_OBJECT_INDEX_TRANSISTOR);
        if(!existActivedDevice){
            DLT_LOG << "Don't have any active deviced";
            updateStateOfDeActviedMultimeter();
        }else{
            updateStateOfActviedMultimeter();
        }
    }
}

int ModelData::activedDeviced()
{
    return m_activedDeviced;
}

void ModelData::setActivedDeviced(int data)
{
    DLT_LOG << data;
    if(m_activedDeviced != data){
        m_activedDeviced = data;
        emit activedDevicedChanged();
    }

}

ModelData *ModelData::getInstance()
{
    if (!m_instantce) {
        try
        {
            m_instantce = new ModelData();
        }
        catch (std::exception& e)
        {
            DLT_LOG << "Exception " << e.what();
        }
    }
    return m_instantce;
}

void ModelData::initObjects()
{
    DLT_LOG;
    m_resistor1         = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_1),    "Resistor_1"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_RESISTOR   ), "file:///" + QDir::currentPath() + "/Image/Resistor_1.jpg", QPointF(1,70),   QPointF(139,72), QPointF(0,0));
    m_resistor2         = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_2),    "Resistor_2"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_RESISTOR   ), "file:///" + QDir::currentPath() + "/Image/Resistor_2.jpg", QPointF(0,73),   QPointF(140,72), QPointF(0,0));
    m_capictor_normal   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_1),    "Capictor_1"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_1.png", QPointF(54,139), QPointF(82,138), QPointF(0,0));
    m_capictor_abnormal = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_2),    "Capictor_2"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_2.jpg", QPointF(57,139), QPointF(83,139), QPointF(0,0));
    m_cappictor_error   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_3),    "Capictor_3"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_3.png", QPointF(48,137), QPointF(82,139), QPointF(0,0));
    m_condutor_normal   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_1),    "Conductor_1"  ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CONDUTOR   ), "file:///" + QDir::currentPath() + "/Image/Conductor_1.png",QPointF(0,131),  QPointF(140,59), QPointF(0,0));
    m_condutor_error    = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_2),    "Conductor_2"  ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CONDUTOR   ), "file:///" + QDir::currentPath() + "/Image/Conductor_2.png",QPointF(21,138), QPointF(121,138),QPointF(0,0));
    m_diode             = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_DIODE     ),    "Diode"        ,static_cast<int>(App_Enum::E_OBJECT_TYPE_DIODE      ), "file:///" + QDir::currentPath() + "/Image/Diode.png",      QPointF(0,72),   QPointF(139,74), QPointF(0,0));
    m_transistor        = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_TRANSISTOR),    "Transistor"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_TRANSISTOR ), "file:///" + QDir::currentPath() + "/Image/Transistor.png", QPointF(42,140), QPointF(70,140), QPointF(97,140));
    m_multimeter        = new MultimeterObject(static_cast<int>(App_Enum::E_OBJECT_INDEX_MULTIMETER),    "Multimeter"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_MULTIMETER ), "file:///" + QDir::currentPath() + "/Image/Multimeter_bg.png",
                                               "file:///" + QDir::currentPath() + "/Image/Multimeter_pointer.png",
                                               "file:///" + QDir::currentPath() + "/Image/positivePonter.png",
                                               "file:///" + QDir::currentPath() + "/Image/negativePonter.png",
                                               "file:///" + QDir::currentPath() + "/Image/mask.png",
                                               "file:///" + QDir::currentPath() + "/Image/line.png");
}
void ModelData::onCapNormalTimerTrigged()
{
    DLT_LOG;
    m_multimeter->setProperty("runningAnimation",QVariant(false));
    m_multimeter->setProperty("nextRotation",QVariant(-45));
    m_multimeter->setProperty("runningAnimation",QVariant(true));
}

void ModelData::onCapAbnormalTimerTrigged()
{
    DLT_LOG;
    switch (this->pointerMode()) {
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        DLT_LOG << "0.1";
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(44));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(0));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-35));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-43));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}
