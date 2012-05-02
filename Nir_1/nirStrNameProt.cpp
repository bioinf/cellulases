#include "nirStrNameProt.h"

QString makeProtID(int id)
{
  if (id < 10)
    return "0"+QString::number(id);
  else
    return QString::number(id);
}
int     makeMask(QString s)
{
  int j, curr, mask = 0;
  for (int i = 0; i < 6; ++i)
  {
    j = i*2+1;
    if(s.at(j) == '0')
      curr = 1;
    else
      curr = 2;
    mask += curr <<(2*i);
  }
  return mask;
}
QString   makeProtToABC(int id)
{
  if (id < 10)
    return QString::number(id);
  else
    return ('A'+id-10);
}
int   makeProtFromABC(QChar ch)
{
  QChar ch0('0');
  QChar chA('A');
  if (ch <= '9' && ch >= '0')
    return ch.toAscii() - ch0.toAscii();
  else
    return ch.toAscii() - chA.toAscii() + 10;
}