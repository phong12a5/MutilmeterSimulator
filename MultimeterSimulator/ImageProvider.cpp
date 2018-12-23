#include "ImageProvider.h"

ImageProvider* ImageProvider::m_instantce = nullptr;

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    int width = 100;
    int height = 50;

    if (size)
        *size = QSize(width, height);
    QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                   requestedSize.height() > 0 ? requestedSize.height() : height);
    pixmap.fill(QColor(id).rgba());
    return pixmap;
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QString rsrcid = ":/" + id;
    QImage image(rsrcid);
    QImage result;

    DLT_LOG << image.isNull();
    if (requestedSize.isValid()) {
        result = image.scaled(requestedSize, Qt::KeepAspectRatio);
    } else {
        result = image;
    }
    *size = result.size();
    return result;
}

ImageProvider *ImageProvider::getInstance()
{
    if (!m_instantce) {
        try
        {
            m_instantce = new ImageProvider();
        }
        catch (std::exception& e)
        {
            DLT_LOG << "Exception " << e.what();
        }
    }
    return m_instantce;
}


