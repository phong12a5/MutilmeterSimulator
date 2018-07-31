#include "ModelData.h"

ModelData* ModelData::m_instantce = nullptr;


ModelData::ModelData(QObject *parent) : QObject(parent)
{
    m_pointerMode = 0;
    initObjects();
}

ModelData::~ModelData()
{
    if(m_instantce != nullptr){
        delete  m_instantce;
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
    m_resistor1         = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_1),    "Resistor_1"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_RESISTOR   ), "file:///" + QDir::currentPath() + "/Image/Resistor_1.png");
    m_resistor2         = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_RESISTOR_2),    "Resistor_2"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_RESISTOR   ), "file:///" + QDir::currentPath() + "/Image/Resistor_2.png");
    m_capictor_normal   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_1),    "Capictor_1"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_1.png");
    m_capictor_abnormal = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_2),    "Capictor_2"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_2.png");
    m_cappictor_error   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CAPICTOR_3),    "Capictor_3"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CAPICTOR   ), "file:///" + QDir::currentPath() + "/Image/Capictor_3.png");
    m_condutor_normal   = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_1),    "Conductor_1"  ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CONDUTOR   ), "file:///" + QDir::currentPath() + "/Image/Conductor_1.png");
    m_condutor_error    = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_CONDUTOR_2),    "Conductor_2"  ,static_cast<int>(App_Enum::E_OBJECT_TYPE_CONDUTOR   ), "file:///" + QDir::currentPath() + "/Image/Conductor_2.png");
    m_diode             = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_DIODE     ),    "Diode"        ,static_cast<int>(App_Enum::E_OBJECT_TYPE_DIODE      ), "file:///" + QDir::currentPath() + "/Image/Diode.png");
    m_transistor        = new CommonObject    (static_cast<int>(App_Enum::E_OBJECT_INDEX_TRANSISTOR),    "Transistor"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_TRANSISTOR ), "file:///" + QDir::currentPath() + "/Image/Transistor.png");
    m_multimeter        = new MultimeterObject(static_cast<int>(App_Enum::E_OBJECT_INDEX_MULTIMETER),    "Multimeter"   ,static_cast<int>(App_Enum::E_OBJECT_TYPE_MULTIMETER ), "file:///" + QDir::currentPath() + "/Image/Multimeter_bg.png", "file:///" + QDir::currentPath() + "/Image/Multimeter_pointer.png");
}
