#include "ModelData.h"

ModelData* ModelData::m_instantce = nullptr;


ModelData::ModelData(QObject *parent) : QObject(parent)
{
    m_pointerMode = 0;
    m_activedDeviced = -1;
    initObjects();
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
            handleActivedRes1(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_2):
            handleActivedRes2(posConnectedWire,negaConnectedWire);
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
            handleActivedConductorNormal(posConnectedWire,negaConnectedWire);
            break;
        case static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_2):
            handleActivedConductorError(posConnectedWire,negaConnectedWire);
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
        DLT_LOG << "RESET ANIMATION";
        m_multimeter->setProperty("nextRotation",QVariant(-45));
        m_multimeter->setProperty("animationDuration",QVariant(200));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        emit multimeterChanged();
    }
    
}

void ModelData::handleActivedRes1(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
    switch (this->pointerMode()) {
        case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-42));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-29));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(41));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(44.5));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}

void ModelData::handleActivedRes2(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
    switch (this->pointerMode()) {
        case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-45));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(-42));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_1K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(15.2));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    case static_cast<int>(App_Enum::E_MULTI_POINTER_MODE_10K_R):
        m_multimeter->setProperty("runningAnimation",QVariant(false));
        m_multimeter->setProperty("nextRotation",QVariant(41));
        m_multimeter->setProperty("animationDuration",QVariant(300));
        m_multimeter->setProperty("runningAnimation",QVariant(true));
        break;
    default:
        break;
    }
}

void ModelData::handleActivedCapNormal(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedCapAbnormal(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedCapError(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedConductorNormal(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedConductorError(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedDiode(int posConnectedWire, int negaConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire;
}

void ModelData::handleActivedTransistor(int posConnectedWire, int negaConnectedWire, int extConnectedWire)
{
    DLT_LOG << "posConnectedWire: " << posConnectedWire << " >> negaConnectedWire: " << negaConnectedWire << " >> extConnectedWire: " << extConnectedWire;
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

int ModelData::pointerMode()
{
    return m_pointerMode;
}

void ModelData::setPointerMode(int _mode)
{
    DLT_LOG << _mode;
    if(m_pointerMode != _mode){
        m_pointerMode = _mode;
        emit pointerModeChanged();
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
        if(!m_activedDeviced){

        }
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
    m_transistor        = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_TRANSISTOR),    "Transistor"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_TRANSISTOR ), "file:///" + QDir::currentPath() + "/Image/Transistor.png", QPointF(59,135), QPointF(71,135), QPointF(83,135));
    m_multimeter        = new MultimeterObject(static_cast<int>(App_Enum::E_OBJECT_INDEX_MULTIMETER),    "Multimeter"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_MULTIMETER ), "file:///" + QDir::currentPath() + "/Image/Multimeter_bg.png",
                                               "file:///" + QDir::currentPath() + "/Image/Multimeter_pointer.png",
                                               "file:///" + QDir::currentPath() + "/Image/positivePonter.png",
                                               "file:///" + QDir::currentPath() + "/Image/negativePonter.png",
                                               "file:///" + QDir::currentPath() + "/Image/mask.png",
                                               "file:///" + QDir::currentPath() + "/Image/line.png");
}
