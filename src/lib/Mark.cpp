#include "Mark.h"

#include "MarkManager.h"

Mark::Mark(const QString &fileName, int lineNumber, int type, MarkManager *manager) :
    TextMark(fileName, lineNumber),
    manager(manager),
    type(type)
{
    setPriority(TextEditor::TextMark::NormalPriority);
    QIcon icon = type != 0 ? QIcon(QLatin1String(":/icons/images/plus.png")) : QIcon(QLatin1String(":/icons/images/minus.png"));
    setIcon(icon);
}

int Mark::getType() const
{
    return type;
}

void Mark::updateLineNumber(int lineNumber)
{
    TextMark::updateLineNumber(lineNumber);
}

void Mark::updateBlock(const QTextBlock &block)
{
    TextMark::updateBlock(block);
}

void Mark::updateFileName(const QString &fileName)
{
    TextMark::updateFileName(fileName);
}

void Mark::removedFromEditor()
{
    TextMark::removedFromEditor();
}
