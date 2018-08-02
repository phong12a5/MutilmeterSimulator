#ifndef DEFINEMODEL_H
#define DEFINEMODEL_H

#include <QObject>
#include "AppDefine.h"
#include <QDebug>


class DefineModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int WIDGET_WIDTH READ WIDGET_WIDTH CONSTANT)
    Q_PROPERTY(int WIDGET_HEIGHT READ WIDGET_HEIGHT CONSTANT)
    Q_PROPERTY(int multiImg_sourcwWidth READ multiImg_sourcwWidth CONSTANT)
    Q_PROPERTY(int multiImg_sourcwHeight READ multiImg_sourcwHeight CONSTANT)
    Q_PROPERTY(int multiPointerStartXPoint READ multiPointerStartXPoint CONSTANT)
    Q_PROPERTY(int multiPointerStartYPoint READ multiPointerStartYPoint CONSTANT)
    Q_PROPERTY(int multiPointerRaius READ multiPointerRaius CONSTANT)
    Q_PROPERTY(int multiMeterWidth READ multiMeterWidth CONSTANT)
    Q_PROPERTY(int indicatorXpoint READ indicatorXpoint CONSTANT)
    Q_PROPERTY(int indicatorYpoint READ indicatorYpoint CONSTANT)
    Q_PROPERTY(int maskXpoint READ maskXpoint CONSTANT)
    Q_PROPERTY(int maskYpoint READ maskYpoint CONSTANT)
    Q_PROPERTY(int maskWidth    READ maskWidth CONSTANT)
    Q_PROPERTY(int maskHeight   READ maskHeight CONSTANT)
private:
    int WIDGET_WIDTH(){return 150;}
    int WIDGET_HEIGHT(){return 150;}
    int multiImg_sourcwWidth(){return 2225;}
    int multiImg_sourcwHeight(){return 3305;}
    int multiPointerStartXPoint(){return 603;}
    int multiPointerStartYPoint(){return 2025;}
    int multiPointerRaius(){return 1020;}
    int multiMeterWidth(){return 450;}
    int indicatorXpoint(){return 1095;}
    int indicatorYpoint(){return 1525;}
    int maskXpoint(){return  765;}
    int maskYpoint(){return  1257;}
    int maskWidth(){return  679;}
    int maskHeight(){return  506;}

public:
    explicit DefineModel(QObject *parent = nullptr);

    static DefineModel* getInstance(){
        if (!m_instantce) {
            try
            {
                m_instantce = new DefineModel();
            }
            catch (std::exception& e)
            {
                DLT_LOG << "Exception " << e.what();
            }
        }
        return m_instantce;
    }

signals:

private:
    static DefineModel* m_instantce;

public slots:
};


#endif // DEFINEMODEL_H
