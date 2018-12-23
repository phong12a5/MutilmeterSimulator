#ifndef MODELDATA_H
#define MODELDATA_H

#include <QObject>
#include <QMap>
#include <AppDefine.h>
#include <QDebug>
#include <QDir>
#include "App_Enum.h"
#include <QPointF>
#include <QTimer>
#include <QString>
#include "ImageProvider.h"

#if defined (WEB_ENV)
#define FOLDER_PREFIX QString("image://ImgProvider/")
#else
#define FOLDER_PREFIX "file:///"+QDir::currentPath()
#endif

class CommonObject: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int idx READ idx WRITE setIdx NOTIFY idxChanged)
    Q_PROPERTY(QString objectName READ objectName WRITE setObjectName NOTIFY objectNameChanged)
    Q_PROPERTY(int objectType READ objectType WRITE setObjectType NOTIFY objectTypeChanged)
    Q_PROPERTY(QString sourceImage READ sourceImage WRITE setSourceImage NOTIFY sourceImageChanged)
    Q_PROPERTY(QVariant positivePoint READ positivePoint  NOTIFY positivePointChanged)
    Q_PROPERTY(QVariant negativePoint READ negativePoint  NOTIFY negativePointChanged)
    Q_PROPERTY(QVariant extendPoint READ extendPoint  NOTIFY extendPointChanged)
    Q_PROPERTY(int posConnectedWire     READ posConnectedWire   WRITE setPosConnectedWire   NOTIFY posConnectedWireChanged)
    Q_PROPERTY(int negaConnectedWire    READ negaConnectedWire  WRITE setNegaConnectedWire  NOTIFY negaConnectedWireChanged)
    Q_PROPERTY(int extConnectedWire     READ extConnectedWire   WRITE setExtConnectedWire   NOTIFY extConnectedWireChanged)
    Q_PROPERTY(bool onOffState          READ onOffState         WRITE setOnOffState         NOTIFY onOffStateChanged)

signals:
    void idxChanged();
    void objectNameChanged();
    void objectTypeChanged();
    void sourceImageChanged();
    void positivePointChanged();
    void negativePointChanged();
    void extendPointChanged();
    void posConnectedWireChanged() ;
    void negaConnectedWireChanged();
    void extConnectedWireChanged() ;
    void onOffStateChanged();

public:
    CommonObject(int _idx, QString _objectName, int _objectType, QString _sourceImage, QPointF _positivePoint, QPointF _negativePoint, QPointF _extendPoint):
    m_idx(_idx),
    m_objectName(_objectName),
    m_objectType(_objectType),
    m_sourceImage(_sourceImage),
    m_positivePoint(_positivePoint),
    m_negativePoint(_negativePoint),
    m_extendPoint(_extendPoint)
    {
        m_posConnectedWire = static_cast<int>(App_Enum::E_WIRE_TYPE_NONE);
        m_negaConnectedWire = static_cast<int>(App_Enum::E_WIRE_TYPE_NONE);
        m_extConnectedWire = static_cast<int>(App_Enum::E_WIRE_TYPE_NONE);
        m_onOffState = false;
    }
    ~CommonObject(){}

    int idx(){ return  m_idx;}
    QString objectName(){ return m_objectName;}
    int objectType(){return m_objectType;}
    QString sourceImage(){return m_sourceImage;}
    QVariant positivePoint(){return QVariant(m_positivePoint);}
    QVariant negativePoint(){return QVariant(m_negativePoint);}
    QVariant extendPoint(){return QVariant(m_extendPoint);}
    int posConnectedWire (){return m_posConnectedWire ;}
    int negaConnectedWire(){return m_negaConnectedWire;}
    int extConnectedWire (){return m_extConnectedWire ;}
    bool onOffState(){return m_onOffState;}

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
    void setPosConnectedWire (int data){
        DLT_LOG << data;
        if(m_posConnectedWire != data){
            m_posConnectedWire = data;
            emit posConnectedWireChanged();
        }
    }

    void setNegaConnectedWire(int data){
        DLT_LOG << data;
        if(m_negaConnectedWire != data){
            m_negaConnectedWire = data;
            emit negaConnectedWireChanged();
        }
    }
    void setExtConnectedWire (int data){
        DLT_LOG << data;
        if(m_extConnectedWire != data){
            m_extConnectedWire = data;
            emit extConnectedWireChanged();
        }
    }

    void setOnOffState(bool data){
        if(data != m_onOffState){
            m_onOffState = data;
            emit onOffStateChanged();
        }
    }
private:
    int m_idx;
    QString m_objectName;
    int m_objectType;
    QString m_sourceImage;
    QPointF m_positivePoint;
    QPointF m_negativePoint;
    QPointF m_extendPoint;
    int m_posConnectedWire ;
    int m_negaConnectedWire;
    int m_extConnectedWire ;
    bool m_onOffState;
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
    Q_PROPERTY(QString maskSource READ maskSource CONSTANT)
    Q_PROPERTY(QString line READ line CONSTANT)
    Q_PROPERTY(int currentRotation READ currentRotation WRITE setCurrentRotation NOTIFY currentRotationChanged)
    Q_PROPERTY(int nextRotation READ nextRotation WRITE setNextRotation NOTIFY nextRotationChanged)
    Q_PROPERTY(bool runningAnimation READ runningAnimation WRITE setRunningAnimation NOTIFY runningAnimationChanged)
    Q_PROPERTY(int animationDuration READ animationDuration WRITE setAnimationDuration NOTIFY animationDurationChanged)

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
    void currentRotationChanged();
    void nextRotationChanged();
    void runningAnimationChanged();
    void animationDurationChanged();

public:
    MultimeterObject(int _idx, QString _objectName, int _objectType, QString _soureBg, QString _sourcePointer, QString _redSourceImg, QString _blackSourceImg, QString _maskSource,QString _line):
    m_idx(_idx),
    m_objectName(_objectName),
    m_objectType(_objectType),
    m_sourceBg(_soureBg),
    m_sourcePointer(_sourcePointer),
    m_activedPositive(false),
    m_activedNegative(false),
    m_redSourceImg(_redSourceImg),
    m_blackSourceImg(_blackSourceImg),
    m_maskSource(_maskSource),
    m_line(_line)
    {
        m_nextRotation = -45;
        m_currentRotation = -45;
        m_runningAnimation = false;
        m_animationDuration = 500;
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
    QString maskSource(){return m_maskSource;}
    int currentRotation(){return m_currentRotation;}
    int nextRotation(){return m_nextRotation;}
    bool runningAnimation(){return m_runningAnimation;}
    int animationDuration(){return m_animationDuration;}
    QString line(){return m_line;}

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

    void setNextRotation(int _nextRotation){
        if(m_nextRotation != _nextRotation){
            m_nextRotation = _nextRotation;
            emit nextRotationChanged();
        }
    }

    void setCurrentRotation(int _currentRotation){
        if(m_currentRotation != _currentRotation){
            m_currentRotation = _currentRotation;
            emit currentRotationChanged();
        }
    }

    void setRunningAnimation(bool _runningAnimation){
        DLT_LOG << _runningAnimation;
        if(m_runningAnimation != _runningAnimation){
            m_runningAnimation = _runningAnimation;
            emit runningAnimationChanged();
        }
    }

    void setAnimationDuration(int _animationDuration){
        if(m_animationDuration != _animationDuration){
            m_animationDuration = _animationDuration;
            emit animationDurationChanged();
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
    QString m_maskSource;
    QString m_line;
    int m_currentRotation;
    int m_nextRotation;
    bool m_runningAnimation;
    int m_animationDuration;
};

class ModelData : public QObject
{
    Q_OBJECT
public:
    explicit ModelData(QObject *parent = nullptr);
    ~ModelData();

    Q_PROPERTY(QObject* resistor1           READ resistor1          NOTIFY resistor1Changed)
    Q_PROPERTY(QObject* resistor2           READ resistor2          NOTIFY resistor2Changed)
    Q_PROPERTY(QObject* capictor_normal     READ capictor_normal    NOTIFY capictor_normalChanged)
    Q_PROPERTY(QObject* capictor_abnormal   READ capictor_abnormal  NOTIFY capictor_abnormalChanged)
    Q_PROPERTY(QObject* cappictor_error     READ cappictor_error    NOTIFY cappictor_errorChanged)
    Q_PROPERTY(QObject* condutor_normal     READ condutor_normal    NOTIFY condutor_normalChanged)
    Q_PROPERTY(QObject* condutor_error      READ condutor_error     NOTIFY condutor_errorChanged)
    Q_PROPERTY(QObject* diode               READ diode              NOTIFY diodeChanged)
    Q_PROPERTY(QObject* transistor          READ transistor         NOTIFY transistorChanged)
    Q_PROPERTY(QObject* multimeter          READ multimeter         NOTIFY multimeterChanged)
    Q_PROPERTY(QObject* greenLed            READ greenLed           NOTIFY greenLedChanged)
    Q_PROPERTY(QObject* redLed              READ redLed             NOTIFY redLedChanged)
    Q_PROPERTY(QObject* powerSocket         READ powerSocket        NOTIFY powerSocketChanged)
    Q_PROPERTY(int pointerMode              READ pointerMode        WRITE setPointerMode    NOTIFY pointerModeChanged)
    Q_PROPERTY(int activedDeviced           READ activedDeviced     WRITE setActivedDeviced NOTIFY activedDevicedChanged)
    Q_PROPERTY(QList<QObject*> listModel    READ listModel          NOTIFY listModelChanged)
    Q_PROPERTY(QString fingerSource         READ fingerSource       NOTIFY fingerSourceChanged)
    Q_PROPERTY(QString logoSource           READ logoSource         NOTIFY logoChanged)
    Q_PROPERTY(QString rstBtnSource         READ rstBtnSource       NOTIFY rstBtnSourceChanged)

    Q_PROPERTY(bool resetAdj                READ resetAdj           WRITE setResetAdj           NOTIFY resetAdjChanged)
    Q_PROPERTY(bool bothWireAtSamePos       READ bothWireAtSamePos  WRITE setBothWireAtSamePos  NOTIFY bothWireAtSamePosChanged)

    Q_INVOKABLE void updateActivedDevice(bool actived, int index, int posConnectedWire, int negaConnectedWire, int extConnectedWire);
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
    QObject* m_greenLed;
    QObject* m_redLed;
    QObject* m_powerSocket;
    QList<QObject*> m_listModel;
    QTimer m_capNormalTimer;
    QTimer m_capAbnormalTimer;
    int m_pointerMode;
    int m_activedDeviced;
    bool m_resetAdj;
    bool m_bothWireAtSamePos;

private:
    void handleActivedRes1();
    void handleActivedRes2();
    void handleActivedCapNormal(int posConnectedWire, int negaConnectedWire);
    void handleActivedCapAbnormal(int posConnectedWire, int negaConnectedWire);
    void handleActivedCapError(int posConnectedWire, int negaConnectedWire);
    void handleActivedConductorNormal();
    void handleActivedConductorError();
    void handleActivedDiode(int posConnectedWire, int negaConnectedWire);
    void handleActivedTransistor(int posConnectedWire, int negaConnectedWire, int extConnectedWire);
    void handleActivedGreenLed(int posConnectedWire, int negaConnectedWire, int extConnectedWire);
    void handleActivedRedLed(int posConnectedWire, int negaConnectedWire, int extConnectedWire);
    void handleActivedPowerSocket(int posConnectedWire, int negaConnectedWire, int extConnectedWire);
    void updateStateOfDeActviedMultimeter();
    void updateStateOfActviedMultimeter();
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
    QObject* redLed();
    QObject* powerSocket();
    QObject* greenLed();
    QObject* multimeter();
    QList<QObject *> listModel();
    QString fingerSource();
    QString logoSource();
    int pointerMode();
    void setPointerMode(int _mode);
    int activedDeviced();
    void setActivedDeviced(int data);
    QString rstBtnSource();
    bool resetAdj();
    void setResetAdj(bool data);
    bool bothWireAtSamePos();
    void setBothWireAtSamePos(bool data);

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
    void redLedChanged();
    void powerSocketChanged();
    void greenLedChanged();
    void multimeterChanged();
    void pointerModeChanged();
    void activedDevicedChanged();
    void listModelChanged();
    void fingerSourceChanged();
    void logoChanged();
    void rstBtnSourceChanged();
    void resetAdjChanged();
    void bothWireAtSamePosChanged();

public slots:
    void onCapNormalTimerTrigged();
    void onCapAbnormalTimerTrigged();
};

#endif // MODELDATA_H
