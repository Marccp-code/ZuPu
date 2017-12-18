#ifndef FILEOPERATE_H
#define FILEOPERATE_H
#include <QWidget>
#include "tree.h"
#include <QDebug>

class FileOperate : public QWidget
{
    Q_OBJECT
public:
    void FileSave(Tree*);
    void FileClean(QString);
    void FileCreate(Tree*,QString);
    void FileRead(Tree* &,QString);

};


#endif // FILEOPERATE_H
