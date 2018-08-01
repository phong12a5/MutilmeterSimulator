#ifndef MODELDATA_H
#define MODELDATA_H

#include <QObject>
#include <QMap>
#include <AppDefine.h>
#include <QDebug>
#include <QDir>
#include "App_Enum.h"

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

    void setIdx(int _idx){
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

class MultimeterObject: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int idx READ idx WRITE setIdx NOTIFY idxChanged)
    Q_PROPERTY(QString objectName READ objectName WRITE setObjectName NOTIFY objectNameChanged)
    Q_PROPERTY(int objectType READ objectType WRITE setObjectType NOTIFY objectTypeChanged)
    Q_PROPERTY(QString soureBg READ soureBg WRITE setSoureBg NOTIFY soureBgChanged)
    Q_PROPERTY(QString sourcePointer READ sourcePointer WRITE setSourcePointer NOTIFY sourcePointerChanged)
    Q_PROPERTY(bool activedPositive READ activedPositive WRITE setActivedPositive NOTIFY activedPositiveChanged)
    Q_PROPERTY(bool activedNegative READ activedNegative WRITE setActivedNegative NOTIFY activedNegativeChanged)
    Q_PROPERTY(QString redSourceImg READ redSourceImg WRITE setRedSourceImg NOTIFY redSourceImgChanged)
    Q_PROPERTY(QString blackSourceImg READ blackSourceImg WRITE setBlackSourceImg NOTIFY blackSourceImgChanged)

signals:
    void idxChanged();
    void objectNameChanged();
    void objectTypeChanged();
    void soureBgChanged();
    void sourcePointerChanged();
    void activedPositiveChanged();
    void activedNegativeChanged();
    void redSourceImgChanged();
    void blackSourceImgChanged();

public:
    MultimeterObject(int _idx, QString _objectName, int _objectType, QString _soureBg, QString _sourcePointer, QString _redSourceImg, QString _blackSourceImg):
    m_idx(_idx),
    m_objectName(_objectName),
    m_objectType(_objectType),
    m_sourceBg(_soureBg),
    m_sourcePointer(_sourcePointer),
    m_activedPositive(false),
    m_activedNegative(false),
    m_redSourceImg(_redSourceImg),
    m_blackSourceImg(_blackSourceImg)
    {
    }
    ~MultimeterObject(){}

    int idx(){ return  m_idx;}
    QString objectName(){ return m_objectName;}
    int objectType(){return m_objectType;}
    QString soureBg(){return m_sourceBg;}
    QString sourcePointer(){return m_sourcePointer;}
    bool activedPositive(){return m_activedPositive;}
    bool activedNegative(){return m_activedNegative;}
    QString redSourceImg(){return m_redSourceImg;}
    QString blackSourceImg(){return m_blackSourceImg;}

    void setIdx(int _idx){
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
    void setSoureBg(QString _soureBg){
        if(_soureBg != m_sourceBg){
            m_sourceBg = _soureBg;
            emit soureBgChanged();
        }
    }
    void setSourcePointer(QString _soucePointer){
        if(_soucePointer != m_sourcePointer){
            m_sourcePointer =_soucePointer;
            emit sourcePointerChanged();
        }
    }
    void setActivedPositive(bool _activedPositive){
        if(_activedPositive != m_activedPositive){
            m_activedPositive = _activedPositive;
            emit activedPositiveChanged();
        }
    }

    void setActivedNegative(bool _activedNegative){
        if(_activedNegative != m_activedNegative){
            m_activedNegative = _activedNegative;
            emit activedNegativeChanged();
        }
    }
    void setRedSourceImg(QString _redSourceImg ){
        if(m_redSourceImg != _redSourceImg){
            m_redSourceImg = _redSourceImg;
            emit redSourceImgChanged();
        }
    }
    void setBlackSourceImg(QString _blackSourceImg ){
        if(m_blackSourceImg != _blackSourceImg){
            m_blackSourceImg = _blackSourceImg;
            emit blackSourceImgChanged();
        }
    }


private:
    int m_idx;
    QString m_objectName;
    int m_objectType;
    QString m_sourceBg;
    QString m_sourcePointer;
    bool m_activedPositive;
    bool m_activedNegative;
    QString m_redSourceImg;
    QString m_blackSourceImg;
};

class ModelData : public QObject
{
    Q_OBJECT
public:
    explicit ModelData(QObject *parent = nullptr);
    ~ModelData();

    Q_PROPERTY(QObject* resistor1           READ resistor1         NOTIFY resistor1Changed)
    Q_PROPERTY(QObject* resistor2           READ resistor2         NOTIFY resistor2Changed)
    Q_PROPERTY(QObject* capictor_normal     READ capictor_normal   NOTIFY capictor_normalChanged)
    Q_PROPERTY(QObject* capictor_abnormal   READ capictor_abnormal NOTIFY capictor_abnormalChanged)
    Q_PROPERTY(QObject* cappictor_error     READ cappictor_error   NOTIFY cappictor_errorChanged)
    Q_PROPERTY(QObject* condutor_normal     READ condutor_normal   NOTIFY condutor_normalChanged)
    Q_PROPERTY(QObject* condutor_error      READ condutor_error    NOTIFY condutor_errorChanged)
    Q_PROPERTY(QObject* diode               READ diode             NOTIFY diodeChanged)
    Q_PROPERTY(QObject* transistor          READ transistor        NOTIFY transistorChanged)
    Q_PROPERTY(QObject* multimeter          READ multimeter        NOTIFY multimeterChanged)

    Q_PROPERTY(int pointerMode      READ pointerMode    WRITE setPointerMode    NOTIFY pointerModeChanged)

private:

    static ModelData* m_instantce;

    QObject* m_resistor1;
    QObject* m_resistor2;
    QObject* m_capictor_normal;
    QObject* m_capictor_abnormal;
    QObject* m_cappictor_error;
    QObject* m_condutor_normal;
    QObject* m_condutor_error;
    QObject* m_diode;
    QObject* m_transistor;
    QObject* m_multimeter;

    int m_pointerMode;

public:
    static ModelData* getInstance();
    void initObjects();

    QObject* resistor1();
    QObject* resistor2();
    QObject* capictor_normal();
    QObject* capictor_abnormal();
    QObject* cappictor_error();
    QObject* condutor_normal();
    QObject* condutor_error();
    QObject* diode();
    QObject* transistor();
    QObject* multimeter();
    int pointerMode();
    void setPointerMode(int _mode);


signals:
    void resistor1Changed();
    void resistor2Changed();
    void capictor_normalChanged();
    void capictor_abnormalChanged();
    void cappictor_errorChanged();
    void condutor_normalChanged();
    void condutor_errorChanged();
    void diodeChanged();
    void transistorChanged();
    void multimeterChanged();
    void pointerModeChanged();

public slots:
};

#endif // MODELDATA_H
