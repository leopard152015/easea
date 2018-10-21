/*
 *  Created on: 31 jullet 2018
 *      Author: Anna Ouskova Leonteva
 */
#ifndef CCROWDINGARCHIVE_H
#define CCROWDINGARCHIVE_H


#include <memory>
#include "CPseudoRandom.h"
#include "CPermutation.h"
#include "CDominanceComparator.h"
#include "CDistance.h"
#include "CCrowdingDistanceComparator.h"
#include "CEqual.h"
#include "CArchive.h"
#include "CPopulation.h"
#include "CComparator.h"

/* This class is implements the Archive Object */
template<typename TIndividual, typename TPopulation>
class CCrowdingArchive : public TPopulation {
private:
    int maxSize_;
    int objectives_;
    CComparator<TIndividual> *dominance_;
    CComparator<TIndividual> *equals_;
    CComparator<TIndividual> *crowdingDistance_;
    CDistance<TIndividual, TPopulation> *distance_;

public:
    CCrowdingArchive(int maxSize, int numberOfObjectives) {
        maxSize_          = maxSize;
        objectives_       = numberOfObjectives;
        dominance_        = new CDominanceComparator<TIndividual>();
        equals_           = new CEqual<TIndividual>();
        crowdingDistance_ = new CCrowdingDistanceComparator<TIndividual>();
        distance_         = new CDistance<TIndividual, TPopulation>();
    };

    ~CCrowdingArchive(){
        delete dominance_;
        delete equals_;
        delete crowdingDistance_;
        delete distance_;

    };

    bool add(TIndividual *individual){
        auto flag = int{0};
        auto i = int{0};
        TIndividual * aux; //An temporal individual 

        while (i < TPopulation::pop_vect.size()){
            aux = TPopulation::pop_vect[i]; // get current individual

            flag = dominance_->compare(individual,aux); //
            if (flag == 1)                // The new individual is dominated
                return false;                // Reject the new individual
            else if (flag == -1){        // An individual in the archive is dominated
                delete aux; // Remove it from the population
                TPopulation::pop_vect.erase (TPopulation::pop_vect.begin()+i);
            } else {
                //if (equals_->compare(aux,individual)==0) {
                // There are equals individuals in the population
                //    return false; // Reject the new individual
            //    }
                i++;
            }
        }
        // Inserting new individaul in archive
        bool res = true;
        TPopulation::pop_vect.push_back(individual);
        if (TPopulation::size() > maxSize_) { // Checking if archive is full
            distance_->allocCrowdingDistance(this,objectives_);
            int indexWorst_ = TPopulation::indexWorst(crowdingDistance_);
            if (individual == TPopulation::pop_vect[indexWorst_])
                res = false;
            else
                delete TPopulation::pop_vect[indexWorst_];

            TPopulation::remove(indexWorst_);
        }
        return res;
    };

};
#endif
