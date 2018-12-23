#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include "AppDefine.h"

class ImageProvider : public QQuickImageProvider
{
public:
    explicit ImageProvider();
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
    static ImageProvider* getInstance();
signals:

private:
    static ImageProvider* m_instantce;

public slots:
};

#endif // IMAGEPROVIDER_H
