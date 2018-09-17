/*
 * CDominanceComparator.h
 *
 *  Created on: 31 jullet 2018
 *      Author: Anna Ouskova Leonteva
 */

#ifndef CDOMINANCECOMPARATOR_H
#define CDOMINANCECOMPARATOR_H

#include <CComparator.h>
#include <CConstraintComparator.h>

/* This is class is used for comparing two individuals (solutions) by dominance.
 * It gets two objects of individauls as the inputs parameters.
 * The result of comaration is -1, if the first individual dominates to second
 * individual. The result = 1, if the second individual dominates to first one.
 * And the result = 0 in case of two individuals are equals.
 */

template<typename TIndividual>
class CDominanceComparator : public CComparator<TIndividual> {

private:
    CComparator<TIndividual> * c_;

public:
    CDominanceComparator(){
        c_ = new CConstraintComparator<TIndividual>();
    };

    ~CDominanceComparator(){
         delete c_;
    };

    int compare(TIndividual *ind1, TIndividual *ind2){
        if (ind1==nullptr)
            return 1;
        else if (ind2 == nullptr)
            return -1;

        auto dominate1 = int{0}; // individual1 dominates
        auto dominate2 = int{0} ; // individual2 dominates


        auto flag = int{0}; // result of the comparison

        if (ind1->getConstraint()!= ind2->getConstraint() &&
            ((ind1->getConstraint() < 0) || (ind2->getConstraint() < 0))){

            auto returnValue = int{c_->compare(ind1,ind2)};
            return returnValue;
        }
        // If individuals have the equal number of  constraints.
	// it's allowed to compare dominance
        auto value1 = double{0.0};
        auto value2 = double{0.0};
        for (auto i = 0; i < ind1->getNumberOfObjectives(); i++) {
            value1 = ind1->getObjective(i);
            value2 = ind2->getObjective(i);
            if (value1 < value2)
                flag = -1;
            else if (value1 > value2)
                flag = 1;
            else
                flag = 0;

            if (flag == -1)
                dominate1 = 1;

            if (flag == 1)
                dominate2 = 1;
        }

        if (dominate1 == dominate2)
            return 0; // individual1 = individual2

        if (dominate1 == 1)
            return -1; //individual1 dominate

        return 1;    // individual2 dominate
    };
};

#endif
