#ifndef MODELDATA_H
#define MODELDATA_H

#include <QObject>

enum class OBJECT_INDEX: int{
    E_OBJECT_INDEX_RESISTOR_1 = 0,
    E_OBJECT_INDEX_RESISTOR_2,
    E_OBJECT_INDEX_CAPICTOR_1,
    E_OBJECT_INDEX_CAPICTOR_2,
    E_OBJECT_INDEX_CAPICTOR_3,
    E_OBJECT_INDEX_CONDUTOR_1,
    E_OBJECT_INDEX_CONDUTOR_2,
    E_OBJECT_INDEX_DIODE     ,
    E_OBJECT_INDEX_TRANSISTOR,
};

enum class OBJECT_TYPE: int{
    E_OBJECT_TYPE_RESISTOR = 0,
    E_OBJECT_TYPE_CAPICTOR,
    E_OBJECT_TYPE_CONDUTOR,
    E_OBJECT_TYPE_DIODE,
    E_OBJECT_TYPE_TRANSISTOR,
};

typedef struct init_data{
    int idx;
    QString objectName;
    int objectType;
    QString sourceImage;

} INIT_DATA;

const QMap<OBJECT_INDEX, INIT_DATA> TABLE_CAMERA {
    {OBJECT_INDEX::E_OBJECT_INDEX_RESISTOR_1,   {OBJECT_INDEX::E_OBJECT_INDEX_RESISTOR_1,"Resistor_1"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_RESISTOR  , "CAMERA_00_RESP" ,"CAMERA_00_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_RESISTOR_2,   {OBJECT_INDEX::E_OBJECT_INDEX_RESISTOR_2,"Resistor_2"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_RESISTOR  , "CAMERA_01_RESP" ,"CAMERA_01_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_1,   {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_1,"Capictor_1"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_CAPICTOR  , "CAMERA_02_RESP" ,"CAMERA_02_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_2,   {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_2,"Capictor_2"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_CAPICTOR  , "CAMERA_03_RESP" ,"CAMERA_03_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_3,   {OBJECT_INDEX::E_OBJECT_INDEX_CAPICTOR_3,"Capictor_3"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_CAPICTOR  , "CAMERA_04_RESP" ,"CAMERA_04_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_CONDUTOR_1,   {OBJECT_INDEX::E_OBJECT_INDEX_CONDUTOR_1,"Conductor_1"  , (int)OBJECT_TYPE::E_OBJECT_TYPE_CONDUTOR  , "CAMERA_05_RESP" ,"CAMERA_05_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_CONDUTOR_2,   {OBJECT_INDEX::E_OBJECT_INDEX_CONDUTOR_2,"Conductor_2"  , (int)OBJECT_TYPE::E_OBJECT_TYPE_CONDUTOR  , "CAMERA_06_RESP" ,"CAMERA_06_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_DIODE     ,   {OBJECT_INDEX::E_OBJECT_INDEX_DIODE     ,"Diode"        , (int)OBJECT_TYPE::E_OBJECT_TYPE_DIODE     , "CAMERA_07_RESP" ,"CAMERA_07_REQ" }},
    {OBJECT_INDEX::E_OBJECT_INDEX_TRANSISTOR,   {OBJECT_INDEX::E_OBJECT_INDEX_TRANSISTOR,"Transistor"   , (int)OBJECT_TYPE::E_OBJECT_TYPE_DIODE     , "CAMERA_08_RESP" ,"CAMERA_08_REQ" }},
};

class CommonObject: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int idx READ idx WRITE setIdx NOTIFY idxChanged)
    Q_PROPERTY(QString objectName READ objectName WRITE setObjectName NOTIFY objectNameChanged)
    Q_PROPERTY(int objectType READ objectType WRITE setObjectType NOTIFY objectTypeChanged)
    Q_PROPERTY(QString sourceImage READ sourceImage WRITE setSourceImage NOTIFY sourceImageChanged)

signals:
    void idxChanged();
    void objectNameChanged();
    void objectTypeChanged();
    void sourceImageChanged();

public:
    CommonObject(int _idx, QString _objectName, int _objectType, QString _sourceImage):
    m_idx(_idx),
    m_objectName(_objectName),
    m_objectType(_objectType),
    m_sourceImage(_sourceImage)
    {
    }
    ~CommonObject(){}

    int idx(){ return  m_idx;}
    QString objectName(){ return m_objectName;}
    int objectType(){return m_objectType;}
    QString sourceImage(){return m_sourceImage;}

    void setObjectName(int _idx){
        if(_idx != m_idx){
            m_idx = _idx;
            emit idxChanged();
        }
    }
    void setObjectName(QString _objectName){
        if(_objectName != m_objectName){
            m_objectName = _objectName;
            emit objectNameChanged();
        }
    }
    void setObjectType(int _objectType){
        if(_objectType != m_objectType){
            m_objectType = _objectType;
            emit objectTypeChanged();
        }
    }
    void setSourceImage(QString _sourceImage){
        if(_sourceImage != m_sourceImage){
            m_sourceImage = _sourceImage;
            emit sourceImageChanged();
        }
    }

private:
    int m_idx;
    QString m_objectName;
    int m_objectType;
    QString m_sourceImage;
};

class ModelData : public QObject
{
    Q_OBJECT
public:
    explicit ModelData(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MODELDATA_H
