#include "ImageProvider.h"

ImageProvider* ImageProvider::m_instantce = nullptr;

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    DLT_LOG << "id: " << id << " -- requestedSize: " << requestedSize;
    QString rsrcid = id;
    QPixmap image(rsrcid);
    QPixmap result;

    if(image.isNull()){
        DLT_LOG << "Image with id" << id << "is null, defaulting to image1";
    }

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


