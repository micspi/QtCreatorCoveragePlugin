#pragma once

#include <texteditor/textmark.h>

class MarkManager;
class Mark : public TextEditor::TextMark
{
    int type;
public:
    Mark(const QString &fileName, int lineNumber, int type);

    int getType() const;

    void updateLineNumber(int lineNumber);
    void updateBlock(const QTextBlock &block);
    void updateFileName(const QString &fileName);
    void removedFromEditor();
};
