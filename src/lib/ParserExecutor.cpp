#include "ParserExecutor.h"

#include "ProjectTreeManager.h"
#include "Parser.h"

#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/project.h>

#include <QDebug>

ParserExecutor::ParserExecutor(ProjectTreeManager *projectTreeManager, QObject *parent) :
    Executor(parent),
    projectTreeManager(projectTreeManager)
{
}

void ParserExecutor::execute()
{
    using namespace ProjectExplorer;

    Project *project = ProjectExplorerPlugin::instance()->currentProject();
    const QStringList &fileNames = project->files(Project::ExcludeGeneratedFiles);
    const QRegExp rx(QLatin1String(".*\\.(h|cpp)"));
    const QString resultFileName = QString(QLatin1String("%1/coverage/result.info")).arg(project->projectDirectory());
    QFile file(resultFileName);
    QTextStream stream(&file);
    if (!file.open(QIODevice::ReadOnly)) {
        emit error();
    }

    const QString &content = stream.readAll();

    Parser parser(fileNames.filter(rx), content);
    parser.execute();

    projectTreeManager->addProject(project->projectDirectory(), parser.getFileCoverageDataList());
    emit finished();
}
