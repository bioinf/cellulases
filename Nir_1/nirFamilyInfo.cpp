#include "nirFamilyInfo.h"


FamilyInfo::FamilyInfo(int id, QVector<int>* vnProtNew)
{
  if (vnProtNew != NULL)
  {
    vnProt = vnProtNew;
  }
  // EROOR
  if (!(id >= 0 && id <= 9))
    return;

  loadHydrolytic(id, vnProt->at(id));

}

void FamilyInfo::loadHydrolytic(int id, int n)
{
  QString s;
  int    mask;

  for (int j = 0; j < n; ++j)
  {
    QFile fileNote("Data_Note/n_" + QString::number(id) + makeProtID(j) + ".txt");
    fileNote.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream strmNote(&fileNote);
    s = strmNote.readLine(50); // Hydrolytic Activity
    s = strmNote.readLine(50); // [C X S M A L]
    s = strmNote.readLine(50); // [* * * * * *]
    mask = makeMask(s);

    vProtActMask.push_back(mask);
    fileNote.close();
  }
}


