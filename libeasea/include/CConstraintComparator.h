
/*
 * CConstraintComparator .h
 *
 *  Created on: 2 aout 2018
 *      Author: Anna Ouskova Leonteva
 */

#ifndef CCONSTRAINTCOMPARATOR
#define CCONSTRAINTCOMPARATOR

#include <CComparator.h>

/* This class for constraint comparating */

template <typename TIndividual>
class CConstraintComparator : public CComparator<TIndividual> {

public:
  int compare(TIndividual * o1,TIndividual * o2){
  double overall1, overall2;
  overall1 = o1->getConstraint();
  overall2 = o2->getConstraint();

  if ((overall1 < 0) && (overall2 < 0)) {
    if (overall1 > overall2){
      return -1;
    } else if (overall2 > overall1){
      return 1;
    } else {
      return 0;
    }
  } else if ((overall1 == 0) && (overall2 < 0)) {
    return -1;
  } else if ((overall1 < 0) && (overall2 == 0)) {
    return 1;
  } else {
    return 0;
  }

};

};

#endif