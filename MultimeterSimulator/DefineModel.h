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

private:
    int WIDGET_WIDTH(){return 150;}
    int WIDGET_HEIGHT(){return 120;}
    int multiImg_sourcwWidth(){return 2225;}
    int multiImg_sourcwHeight(){return 3305;}
    int multiPointerStartXPoint(){return 603;}
    int multiPointerStartYPoint(){return 2025;}
    int multiPointerRaius(){return 1020;}

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
