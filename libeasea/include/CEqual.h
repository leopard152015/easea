/*
 *
 *
 *  Created on: 31 jullet 2018
 *      Author: Anna Ouskova Leonteva
 */
#ifndef CEQUAL_H
#define CEQUAL_H

#include "CComparator.h"


template<typename TIndividual>
class CEqual : public CComparator<TIndividual> {


public:
int compare(TIndividual * ind1, TIndividual *ind2){

  if (ind1 == nullptr)
    return 1;
  else if (ind2 == nullptr)
    return -1;

  auto dominate1{0} ; 
  auto dominate2{0} ; 

  int flag;
  double value1, value2;
  for (int i = 0; i < ind1->getNumberOfObjectives(); i++) {
    CComparator<TIndividual> * c = new CObjectiveComparator<TIndividual>(i);
    flag = c->compare(ind1, ind2);
    delete c;
    value1 = ind1->getObjective(i);
    value2 = ind2->getObjective(i);

    if (value1 < value2) {
      flag = -1;
    } else if (value1 > value2) {
      flag = 1;
    } else {
      flag = 0;
    }

    if (flag == -1) {
      dominate1 = 1;
    }

    if (flag == 1) {
      dominate2 = 1;
    }
  }
  if (dominate1== 0 && dominate2 ==0) {
    return 0; //No one dominate the other
  }
  if (dominate1 == 1) {
    return -1; // solution1 dominate
  } else if (dominate2 == 1) {
    return 1;    // solution2 dominate
  }

  return 2;

};
};
#endif
