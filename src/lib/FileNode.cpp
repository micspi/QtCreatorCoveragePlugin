#include "FileNode.h"

#include "IconDecorator.h"

#include <coreplugin/fileiconprovider.h>

#include <QObject>

FileNode::FileNode(const QString &name, Node *parent) :
    Node(name, parent)
{
}

QVariant FileNode::getData() const
{
    if (lineHitList.isEmpty())
        return QLatin1String("-");

    int linesCovered = 0;
    foreach (const LineHit &lineHit, lineHitList)
        if (lineHit.hit > 0)
            linesCovered++;

    double linesCoveredPercentage = linesCovered *100 / (double)lineHitList.size();
    return QObject::tr("%1%").arg(QString::number(linesCoveredPercentage, 'f', 1));
}

QIcon FileNode::getIcon() const
{
    const QString &fullName = getFullName();
    if (fullName.contains(QLatin1String("/Headers/")))
        return IconDecorator::getIconByName(QLatin1String("File.Headers"));
    if (fullName.contains(QLatin1String("/Sources/")))
        return IconDecorator::getIconByName(QLatin1String("File.Sources"));

    return Node::getIcon();
}

LineHitList FileNode::getLineHitList() const
{
    return lineHitList;
}

void FileNode::setLineHitList(const LineHitList &lineHitList)
{
    this->lineHitList = lineHitList;
}
