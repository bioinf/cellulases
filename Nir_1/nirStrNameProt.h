#ifndef _NIR_STR_NAME_PROT_
#define _NIR_STR_NAME_PROT_

#include <QString>

QString makeProtID(int id);
QString makeProtToABC(int id);
int     makeMask(QString s);
int     makeProtFromABC(QChar ch);

#endif //_NIR_STR_NAME_PROT_