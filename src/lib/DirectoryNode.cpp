#include "DirectoryNode.h"

#include "IconDecorator.h"

DirectoryNode::DirectoryNode(const QString &name, Node *parent) :
    Node(name, parent)
{
}

QIcon DirectoryNode::getIcon() const
{
    const QString &name = getName();
    if (name == QLatin1String("Headers"))
        return IconDecorator::getIconByName(QLatin1String("Dir.Headers"));
    if (name == QLatin1String("Sources"))
        return IconDecorator::getIconByName(QLatin1String("Dir.Sources"));

    return IconDecorator::getIconByName(QLatin1String("Dir.Other"));
}
