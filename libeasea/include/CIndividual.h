/*
 * CIndividual.h
 *
 *  Created on: 23 juin 2009
 *      Author: maitre
 */

#ifndef CINDIVIDUAL_H_
#define CINDIVIDUAL_H_

class CRandomGenerator;
#include <iostream>

class CIndividual {
public:
	bool valid;
	float fitness;
	static CRandomGenerator* rg;
public:
	CIndividual();
	//CIndividual(const CIndividual& indiv);
	virtual ~CIndividual();
	virtual float evaluate() = 0;
	virtual void printOn(std::ostream& O) const = 0;
	virtual size_t mutate(float pMutationPerGene) = 0;
	virtual CIndividual* crossover(CIndividual** p2) = 0;
	virtual CIndividual* clone() = 0;


	static size_t getCrossoverArrity(){ return 2; }
	float getFitness(){ return this->fitness; }


};

#endif /* CINDIVIDUAL_H_ */
