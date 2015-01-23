#include "ProjectTreeFiller.h"

#include "RootNode.h"
#include "ProjectNode.h"
#include "FileNode.h"
#include "ProjectTreeCreator.h"

#include <QDebug>

ProjectTreeFiller::ProjectTreeFiller(const QString &projectName, const FileCoverageDataList &fileCoverageDataList, Node *rootNode) :
    projectName(projectName),
    fileCoverageDataList(fileCoverageDataList),
    rootNode(rootNode)
{
}

void ProjectTreeFiller::execute()
{
    QMutableListIterator<FileCoverageData> it(fileCoverageDataList);
    while (it.hasNext()) {
        FileCoverageData &fileCoverageData = it.next();
        fileCoverageData.fileName.replace(projectName + QLatin1Char('/'), QLatin1String(""));
        it.setValue(fileCoverageData);
    }

    QStringList fileNames;
    foreach (const FileCoverageData &fileCoverageData, fileCoverageDataList)
        fileNames << fileCoverageData.fileName;

    const QString projectShortName = projectName.mid(projectName.lastIndexOf(QLatin1Char('/')) + 1);
    Node *projectNode = new ProjectNode(projectShortName, projectName, rootNode);
    ProjectTreeCreator projectTreeCreator(fileNames, projectNode);
    projectTreeCreator.execute();

    foreach (const FileCoverageData &fileCoverageData, fileCoverageDataList) {
        Node *leafNode = projectTreeCreator.getLeafNodeFromFullName(fileCoverageData.fileName, QLatin1Char('/') + projectShortName);
        if (leafNode) {
            FileNode *fileNode = static_cast<FileNode *>(leafNode);
            fileNode->setLineHitList(fileCoverageData.lineHitList);
        }
    }
}
