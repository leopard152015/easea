/*
 * CDistance.cpp
 *
 *  Created on: 31 jullet 2018
 *      Author: Anna Ouskova Leonteva
 */
#ifndef CDISTANCE_H
#define CDISTANCE_H

#include <float.h>
#include <CObjectiveComparator.h>
#include <math.h>
#include <limits>

/* This class is used for assign the  distance between individuals.
 * This version of libeasea include only crowding distance (CD) for 2 MOAE:
 * NSGAII and ASREA.
 * CD is assigned to all individuals in the populations
 * and is calculated for the individuals with the same rank.
 * It estimates density of individuals which are laid surrounding a particular
 * individual in the population.
 * In fact, CD is used for controlling the diversity of the individuals and
 * more value of it shows a better individual that is laid in a less crowded area.
 * More info about the calculations of CD can be found here:
 * https://pdfs.semanticscholar.org/6866/eb061ee8dc36c584b184f5b94be9ab674e0d.pdf
 */


template <typename TIndividual, typename TPopulation>
class CDistance {

public:
    CDistance(){};

 /* CD is assigned to all individuals (solutions) int the populations */
    void allocCrowdingDistance(const TPopulation * population, const int &nbObjs){

        int size = population->size();
        // first of all check the size of population
        if (size == 0)
            return;
        if (size == 1) {
            population->get(0)->setCrowdingDistance(std::numeric_limits<double>::max());
            return;
        }
        if (size == 2) {
            population->get(0)->setCrowdingDistance(std::numeric_limits<double>::max());
            population->get(1)->setCrowdingDistance(std::numeric_limits<double>::max());
            return;
        }
        // Make copy of population
        auto front = std::make_unique<TPopulation>(size);
        for (auto i = 0; i < size; ++i){
            front->add(population->get(i));
	    front->get(i)->setCrowdingDistance(0.0);
	}

        auto distance = double{0.0};

        for (auto i = 0; i<nbObjs; ++i) {
            auto c = std::make_unique<CObjectiveComparator<TIndividual>>(i);
            front->sort(c.get()); // Sorting of population

            auto minObj = front->get(0)->getObjective(i);
            auto maxObj = front->get(front->size()-1)->getObjective(i);

            //Assign crowding distance
            front->get(0)->setCrowdingDistance(std::numeric_limits<double>::max());
            front->get(size-1)->setCrowdingDistance(std::numeric_limits<double>::max());

            for (auto j = 1; j < size-1; ++j) {
                distance = front->get(j+1)->getObjective(i) - front->get(j-1)->getObjective(i);
                distance = distance / (maxObj - minObj);
                distance += front->get(j)->getCrowdingDistance();
                front->get(j)->setCrowdingDistance(distance);
            }
        }
        front->clear();
    };

};

#endif
