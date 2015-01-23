#pragma once

#include "LinePaintHandler.h"

class LineCleaner : public LinePaintHandler
{
public:
    LineCleaner(TextEditor::TextEditorWidget *textEdit);

protected:
    QColor getColorForValue(int value) const;
};
