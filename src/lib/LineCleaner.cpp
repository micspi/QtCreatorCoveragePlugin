#include "LineCleaner.h"

LineCleaner::LineCleaner(TextEditor::TextEditorWidget *textEdit) :
    LinePaintHandler(textEdit, QMap<int, int>())
{
}

QColor LineCleaner::getColorForValue(int value) const
{
    Q_UNUSED(value);
    return QColor(Qt::white);
}
