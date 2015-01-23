#include "IconDecorator.h"

#include <coreplugin/fileiconprovider.h>

#include <QHash>

QIcon IconDecorator::getIconByName(const QString &name)
{
    static QHash<QString, QIcon> icons;
    if (icons.isEmpty()) {
        icons.insert(QLatin1String("Dir.Headers"), createIcon(QStyle::SP_DirIcon, QIcon(QLatin1String(":/icons/images/headers.png"))));
        icons.insert(QLatin1String("Dir.Sources"), createIcon(QStyle::SP_DirIcon, QIcon(QLatin1String(":/icons/images/sources.png"))));
        icons.insert(QLatin1String("Dir.Project"), createIcon(QStyle::SP_DirIcon, QIcon(QLatin1String(":/icons/images/qt_project.png"))));
        icons.insert(QLatin1String("Dir.Other"), createIcon(QStyle::SP_DirIcon, QIcon()));
        icons.insert(QLatin1String("File.Headers"), createIcon(QStyle::SP_FileIcon, QIcon(QLatin1String(":/icons/images/headers.png"))));
        icons.insert(QLatin1String("File.Sources"), createIcon(QStyle::SP_FileIcon, QIcon(QLatin1String(":/icons/images/sources.png"))));
    }

    return icons.value(name);
}

QIcon IconDecorator::createIcon(const QStyle::StandardPixmap &prototype, const QIcon &decorator)
{
    static const QSize desiredSize = QSize(16, 16);
    const QPixmap pixmap = Core::FileIconProvider::overlayIcon(prototype, decorator, desiredSize);
    QIcon icon;
    icon.addPixmap(pixmap);
    return icon;
}
