
/*
 * CRanking .h
 *
 *  Created on: 31 jullet 2018
 *      Author: Anna Ouskova Leonteva
 */
#ifndef CRANKING_H
#define CRANKING_H

#include <CDominanceComparator.h>
#include <CBT2Selection.h>
#include <CConstraintComparator.h>
#include <vector>
#include <memory>
#include <algorithm>
#include "CLogger.h"

/* In this class 2 schemes of individal's ranking are implemented.
 * The first one gets a object of population. Then it's individuals (solutions) are
 * ranked according the algorithm NSGAII.
 * The second ranking scheme is corresponded to algorithm ASREA, which gets a object
 * of population and object of archive population.
 * For both cases, as a result a set of fronts with ranks is taken.
 * The first rank number is 0 and this front contains the non-dominated
 * individuals. The next one has a rank number = 1 and etc.
 */

template <typename TIndividual, typename TPopulation>
class CRanking {

private:
  TPopulation * population_;
  TPopulation ** ranking_;
  int nbSubfronts_;
  CDominanceComparator<TIndividual> *dominance_;
  CConstraintComparator<TIndividual> *constraint_;

public:
    CRanking (TPopulation * &population) : population_{population},
  	    dominance_ { new CDominanceComparator<TIndividual>()},
  	    constraint_ { new CConstraintComparator<TIndividual>()}{

        // dominating[i] contains the number of individuals dominating i
        auto dominating = std::make_unique<int[]>(population_->size());
  	    if (dominating == nullptr)
 	        LOG_ERROR(errorCode::memory, "memory wasn't allocated!");
        // iDominate[k] contains the list of solutions dominated by k
  	    vector<int> * iDominate = new vector<int>[population_->size()];

  	    // front[i] contains the list of individuals belonging to the front i
  	    vector<int> * front = new vector<int>[population_->size()+1];

  	    // flagDominate is an auxiliar variable
  	    auto flagDominate = int{0};

  	    // Fast non dominated sorting algorithm
  	    for (auto p = 0; p < population_->size(); p++)
    		dominating[p] = 0;
     //   std::sort(population_->begin(),population_->end());
        // For all q individuals , calculate if p dominates q or vice versa
        for (auto p = 0; p < (population_->size() - 1); p++) {
            for (auto q = p + 1; q < population_->size(); q++) {
                flagDominate =constraint_->compare(population_->get(p), population_->get(q));
                if (flagDominate == 0)
                    flagDominate =dominance_->compare(population_->get(p), population_->get(q));
                if (flagDominate == -1) {
                    iDominate[p].emplace_back(q);
                    dominating[q]++;
                } else if (flagDominate == 1) {
                    iDominate[q].emplace_back(p);
                    dominating[p]++;
                }
            }
        }
        for (auto p = 0; p < population_->size(); p++) {
        // If nobody dominates p, p belongs to the first front
            if (dominating[p] == 0) {
                front[0].emplace_back(p);
                population_->get(p)->setRank(0);
            }
        }
        // Obtain the rest of fronts
        auto i= int{0};
        vector<int>::iterator it1, it2;
        while (front[i].size()!=0) {
            i++;
            for (it1=front[i-1].begin(); it1<front[i-1].end(); it1++) {
                for (it2=iDominate[*it1].begin(); it2 < iDominate[*it1].end();it2++) {
                    dominating[*it2]--;
                    if (dominating[*it2]==0) {
                        front[i].emplace_back(*it2);
                        population_->get(*it2)->setRank(i);
                    }
                }
            }
        }
        ranking_ = new TPopulation*[i];
        if (ranking_ == nullptr)
            LOG_ERROR(errorCode::memory, "memory wasn't allocated!");
        //0,1,2,....,i-1 are front, then i fronts

        nbSubfronts_ = i;

        for (auto j = 0; j < i; j++) {
            ranking_[j] = new TPopulation(front[j].size());
            for (it1=front[j].begin(); it1<front[j].end(); it1++)
                ranking_[j]->add(new TIndividual(population_->get(*it1)));
        }

      //  delete [] dominating;
        delete [] iDominate;
        delete [] front;
    };

    CRanking (TPopulation * population, TPopulation * archive) : population_{population} {
        dominance_   = new CDominanceComparator<TIndividual>();
        constraint_  = new CConstraintComparator<TIndividual>();

        // dominating[i] contains the number of solutions dominating i
        auto dominating = std::make_unique<int[]>(population_->size());
        if (dominating == nullptr)
            LOG_ERROR(errorCode::memory, "memory wasn't allocated!");

         // iDominate[k] contains the list of solutions dominated by k
        vector<int> * iDominate = new vector<int>[population_->size()];

        // front[i] contains the list of individuals belonging to the front i
        vector<int> * front = new vector<int>[population_->size()+1];

        // flagDominate is an auxiliar variable
        auto flagDominate = int{0};
        auto selection = new CBT2Selection<TIndividual, TPopulation>();

        // Fast non dominated sorting algorithm
        for (auto p = 0; p < population_->size(); p++)
            dominating[p] = 0;

        auto idx = int{0};
        for (auto p = 0; p < (population_->size() ); p++) {
            for (auto q = 0; q < archive->size(); q++){
                flagDominate =dominance_->compare(population_->get(p), population_->get(q));
                if (flagDominate == 1)
                    dominating[p]= dominating[p]+1;
            }
        }
        // Obtain the rest of fronts
        auto i = int{1};
        vector<int>::iterator it1, it2;
        for (auto p = 0; p < (population_->size() ); p++) {
            if (dominating[p] == 0)
                front[0].emplace_back(p);
                population_->get(p)->setRank(1+dominating[p]);
        }
        ranking_ = new TPopulation*[i];
        if (ranking_ == nullptr)
            LOG_ERROR(errorCode::memory, "memory wasn't allocated!");

        nbSubfronts_ = i;

        for (auto j = 0; j < i; j++) {
            ranking_[j] = new TPopulation(front[j].size());
            for (it1=front[j].begin(); it1<front[j].end(); it1++)
                ranking_[j]->add(new TIndividual(population_->get(*it1)));
        }

        delete [] iDominate;
        delete [] front;
    };


    ~CRanking(){
        for (auto i = 0; i < nbSubfronts_; i++) {
            delete ranking_[i];
        }
        delete [] ranking_;
        delete dominance_;
        delete constraint_;
    };

    TPopulation * getSubfront(int rank){ return ranking_[rank];};
    int getNumberOfSubfronts(){  return nbSubfronts_; };

};
#endif;
