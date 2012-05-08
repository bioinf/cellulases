#ifndef _NIR_FAMILY_INFO_
#define _NIR_FAMILY_INFO_

#include <QVector>
#include <QFile>
#include <QTextStream>

#include "nirStrNameProt.h"

class FamilyInfo
{
public:
  // id  - id of family
  FamilyInfo(int id, QVector<int>* vnProtNew = NULL);

  bool                  bLoadSstate; // true - if information is loaded from file
  int                   nProt; // nubmer of proteins
  QVector<int>          vProtActMask; // vector of protein activities (mask)
  /*static*/ QVector<int>*  vnProt;

  void loadHydrolytic(int id, int n);
};



#endif //_NIR_FAMILY_INFO_