#include "ProjectTreeCreator.h"

#include "Node.h"
#include "TreeCreator.h"
#include <QDebug>

static const char *SPLIT_SEPARATOR = "/";

ProjectTreeCreator::ProjectTreeCreator(const QStringList &fileNames, Node *rootNode) :
    rootNode(rootNode ? rootNode : new Node()),
    fileNames(fileNames)
{
}

void ProjectTreeCreator::execute()
{
    TreeCreator treeCreator(fileNames, rootNode);
    treeCreator.execute();
}

Node *ProjectTreeCreator::getRootNode() const
{
    return rootNode;
}

Node *ProjectTreeCreator::getLeafNodeFromFullName(const QString &fullName, const QString &projectShortName) const
{
    const QList<Node *> &leafs = rootNode->findLeafs(fullName.split(QLatin1Char('/')).last());

    foreach (Node *leaf, leafs)
        if (leaf->getFullName() == projectShortName + QLatin1String(SPLIT_SEPARATOR) + fullName)
            return leaf;   

    return 0;
}
