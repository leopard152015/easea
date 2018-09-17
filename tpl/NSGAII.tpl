\TEMPLATE_START
/**
 This is program entry for NSGA-II template for EASEA
 NSGA-II (Non-dominated Sorting Genetic Algorithm 2) is multi
 objective genetic algorithm that uses the non-dominated sorting
 scheme and a crowding distance scheme to rank individuals. 
 The crowding distance is a secondary measure and used to 
 favor an even distribution of points along the Pareto front.
 An individual with a lower rank is considered to have a higher
 fitness than an individual with higher rank.
 An individual with rank = 1 has a higher probability of
 producing offspring in the next generation.
 Ranking complexity O(mn²).
 
 Reference: 
 K. Deb and A. Pratap and S. Agarwal and T. Meyarivan,
 A Fast and Elitist Multiobjective Genetic Algorithm: NSGA-II,
 IEEE Transactions on Evolutionary Computation, 2002, 6, 182-197.
*/

\ANALYSE_PARAMETERS
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <string>

#include "COptionParser.h"
#include "CRandomGenerator.h"
#include "CEvolutionaryAlgorithm.h"
#include "global.h"
#include "EASEAIndividual.hpp"


/** Global variables for the whole algorithm */
CIndividual** pPopulation = NULL;
CIndividual*  bBest = NULL;
float* pEZ_MUT_PROB = NULL;
float* pEZ_XOVER_PROB = NULL;
unsigned *EZ_NB_GEN;
unsigned *EZ_current_generation;
int EZ_POP_SIZE;
int OFFSPRING_SIZE;


CEvolutionaryAlgorithm* EA;

int main(int argc, char** argv){

	LOG_MSG(msgType::INFO, "NSGAII starting....");
    try{
        parseArguments("EASEA.prm",argc,argv);
	    ParametersImpl p;
	    p.setDefaultParameters(argc,argv);

	    EvolutionaryAlgorithmImpl* ea = p.newEvolutionaryAlgorithm();

	    // set input parameters
	    ea->setInputParameter("parentPopulationSize",&p.parentPopulationSize);
        ea->setInputParameter("offspringPopulationSize",&p.offspringPopulationSize);
        ea->setInputParameter("numberOfGenerations", &p.nbGen);

	    EA = ea;

	    EASEAInit(argc,argv);
  
        auto tmStart = std::chrono::system_clock::now();
	    
        ea->runEvolutionaryMultiObjectivesLoop();
        
        std::chrono::duration<double> tmDur = std::chrono::system_clock::now() - tmStart;
        
        ostringstream msg;
        msg <<  "Total execution time (in sec.): " << tmDur.count();
        LOG_MSG(msgType::INFO, msg.str());

	    //EASEAFinal(pop);

	    delete ea;

    }catch (const Exception& e){
        ostringstream msg;
        msg  << e.what() << std::endl;
        LOG_MSG(msgType::INFO, msg.str());
        exit(1);
    }
    
    LOG_MSG(msgType::INFO, "NSGAII successfully completed.");

	return 0;
}

\START_CUDA_GENOME_CU_TPL

#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
#include <map>
#include <iostream>

#include "CRandomGenerator.h"
//#include "CPopulation.h"
#include "COptionParser.h"
#include "CStoppingCriterion.h"
#include "CEvolutionaryAlgorithm.h"
#include "CBT2Selection.h"
#include "CSBXCrossover.h"
#include "CPolynomialMutation.h"
#include "CCrowdingComparator.h"
#include "CDistance.h"
#include "CRanking.h"

#include "CQMetrics.h"
#include "CQMetricsHV.h"
#include "CQMetricsGD.h"
#include "CQMetricsIGD.h"

#include "global.h"
#include "CIndividual.h"

using namespace std;

#include "EASEAIndividual.hpp"
bool INSTEAD_EVAL_STEP = false;


   
CRandomGenerator* globalRandomGenerator;
extern CEvolutionaryAlgorithm* EA;
#define STD_TPL

\INSERT_USER_DECLARATIONS
\ANALYSE_USER_CLASSES

\INSERT_USER_CLASSES

\INSERT_USER_FUNCTIONS

\INSERT_INITIALISATION_FUNCTION
\INSERT_FINALIZATION_FUNCTION

void evale_pop_chunk(CIndividual** population, int popSize){
  \INSTEAD_EVAL_FUNCTION
}

void EASEAInit(int argc, char** argv){
	\INSERT_INIT_FCT_CALL
}

void EASEAFinal(CPopulation* pop){
	\INSERT_FINALIZATION_FCT_CALL;
}

void AESAEBeginningGenerationFunction(CEvolutionaryAlgorithm* evolutionaryAlgorithm){
	\INSERT_BEGIN_GENERATION_FUNCTION
}

void AESAEEndGenerationFunction(CEvolutionaryAlgorithm* evolutionaryAlgorithm){
	\INSERT_END_GENERATION_FUNCTION
}

void AESAEGenerationFunctionBeforeReplacement(CEvolutionaryAlgorithm* evolutionaryAlgorithm){
	\INSERT_GENERATION_FUNCTION_BEFORE_REPLACEMENT
}
/***************************************************/

/***************************************************/
/*            IndividualImpl class 				   */
/***************************************************/
IndividualImpl::IndividualImpl() : CIndividual() {
  \GENOME_CTOR 
  \INSERT_EO_INITIALISER
// Setting initial values
    fitness = 0.0;
    valid = false;
    isImmigrant = false;
   
    setCrowdingDistance(0.0);
    setRank(0); 
    objective_ = new double[nbObj_];
    if( objective_ == nullptr)
        LOG_ERROR(errorCode::memory, "memory wasn't allocated for CIndividuals");

    if (upperBound_ == nullptr || lowerBound_ == nullptr)
        LOG_ERROR(errorCode::value, "upper or lower bound of CIndividual's variable is not defined");
     
    variable_ = new CVariable*[nbVar_];
    if (variable_ == nullptr)
        LOG_ERROR(errorCode::memory, "memory wasn't allocated for CVariables");
  

    for (auto i=0; i < nbVar_; i++){
        variable_[i] = new CDoubleType(lowerBound_[i],upperBound_[i]);
        if (variable_[i] == nullptr)
            LOG_ERROR(errorCode::memory, "memory wasn't allocated for CDoubleType");
    }
}

IndividualImpl::IndividualImpl(IndividualImpl *genome): CIndividual(){ 
    
    nbObj_ = genome->getNumberOfObjectives();
    nbVar_ = genome->getNumberOfVariables();
    
    objective_ = new double[nbObj_];
    if( objective_ == nullptr)
        LOG_ERROR(errorCode::memory, "memory wasn't allocated for CIndividual");
    setAllObjectives(objective_, genome->objective_);

    variable_ = new CVariable*[nbVar_];
    setAllVariables(variable_, genome->variable_);
    
    setCrowdingDistance(genome->getCrowdingDistance());
    setRank(genome->getRank());
}

CIndividual* IndividualImpl::clone(){
	return new IndividualImpl(*this);
}

IndividualImpl::~IndividualImpl(){
  \GENOME_DTOR

    if(objective_ != nullptr)
        delete[]objective_ ;
  
    if (variable_ != nullptr){
        for (auto i = 0; i < nbVar_; i++){
            if( variable_[i] != nullptr )
            delete variable_[i] ;
        } 

        delete [] variable_ ;
    }
    if (upperBound_ != nullptr) 
            delete []upperBound_;
    if (lowerBound_ != nullptr) 
            delete []lowerBound_;

}

float IndividualImpl::evaluate(){
    valid = true;
    \INSERT_EVALUATOR
}

void IndividualImpl::boundChecking(){
	\INSERT_BOUND_CHECKING
}

string IndividualImpl::toString() {
    string aux = "";

    for (auto i = 0; i < nbVar_; i++) {
        std::ostringstream stringStream;
        stringStream << this->getIndividualVariables()[i]->toString() ;
        aux = aux + stringStream.str() + " ";
    }
    aux = aux + " | " ;
     for (auto i = 0; i < nbObj_; i++) {
        std::ostringstream stringStream;
        stringStream << this->getObjective(i) ;
        aux = aux + stringStream.str() +  " ";
    }

    return aux;
} 

string IndividualImpl::serialize(){
    ostringstream AESAE_Line(ios_base::app);
    \GENOME_SERIAL
    AESAE_Line << this->fitness;
    return AESAE_Line.str();
}

void IndividualImpl::deserialize(string Line){
    istringstream AESAE_Line(Line);
    string line;
    \GENOME_DESERIAL
    AESAE_Line >> this->fitness;
    this->valid=true;
    this->isImmigrant=false;
}

CIndividual* IndividualImpl::crossover(CIndividual** ps){
	// ********************
	// Generic part
	IndividualImpl** tmp = (IndividualImpl**)ps;
	IndividualImpl parent1(*this);
	IndividualImpl parent2(*tmp[0]);
	IndividualImpl child(*this);

	// ********************
	// Problem specific part
  	\INSERT_CROSSOVER

	child.valid = false;
	return new IndividualImpl(child);
}

void IndividualImpl::printOn(std::ostream& os) const{
	\INSERT_DISPLAY
}

unsigned IndividualImpl::mutate( float pMutationPerGene ){
    this->valid=false;

    // ********************
    // Problem specific part
    \INSERT_MUTATOR
}


/***************************************************/
/*            ParametersImpl class 				   */
/***************************************************/


void ParametersImpl::setDefaultParameters(int argc, char** argv){

	nbGen = setVariable("nbGen",(int)\NB_GEN);
	parentPopulationSize = setVariable("popSize",(int)\POP_SIZE);
	offspringPopulationSize = setVariable("nbOffspring",(int)\OFF_SIZE);
    
/*
	generationalCriterion = new CGenerationalCriterion(setVariable("nbGen",(int)\NB_GEN));
	controlCStopingCriterion = new CControlCStopingCriterion();
	timeCriterion = new CTimeCriterion(setVariable("timeLimit",\TIME_LIMIT));
*/	
	
	printStats = setVariable("printStats",\PRINT_STATS);
	generateCSVFile = setVariable("generateCSVFile",\GENERATE_CSV_FILE);
	generatePlotScript = setVariable("generatePlotScript",\GENERATE_GNUPLOT_SCRIPT);
	
	plotStats = setVariable("plotStats",\PLOT_STATS);
	printInitialPopulation = setVariable("printInitialPopulation",1);
	printFinalPopulation = setVariable("printFinalPopulation",1);
    savePopulation = setVariable("savePopulation",\SAVE_POPULATION);
    startFromFile = setVariable("startFromFile",\START_FROM_FILE);

    remoteIslandModel = 0;
	outputFilename = (char*)"EASEA";
}

EvolutionaryAlgorithmImpl* ParametersImpl::newEvolutionaryAlgorithm(){

/*	pEZ_MUT_PROB = &pMutationPerGene;
	pEZ_XOVER_PROB = &pCrossover;
	EZ_NB_GEN = (unsigned*)setVariable("nbGen",\NB_GEN);
	EZ_current_generation=0;
	EZ_POP_SIZE = parentPopulationSize;
	OFFSPRING_SIZE = offspringPopulationSize;
*/
	EvolutionaryAlgorithmImpl* ea = new EvolutionaryAlgorithmImpl(this);
    
    return ea;
}


/***************************************************/
/*            EvolutionaryAlgorithmImpl class 	   */
/***************************************************/

void EvolutionaryAlgorithmImpl::initializeParentPopulation(){
 /*       if(this->params->startFromFile){
          ifstream AESAE_File("EASEA.pop");
          string AESAE_Line;
          for( unsigned int i=0 ; i< this->params->parentPopulationSize ; i++){
                  getline(AESAE_File, AESAE_Line);
                  this->population->addIndividualParentPopulation(new IndividualImpl(),i);
                  ((IndividualImpl*)this->population->parents[i])->deserialize(AESAE_Line);
          }

        }
        else{
          for( unsigned int i=0 ; i< this->params->parentPopulationSize ; i++){
                  this->population->addIndividualParentPopulation(new IndividualImpl(),i);
          }
        }
        this->population->actualParentPopulationSize = this->params->parentPopulationSize;
*/}

void EvolutionaryAlgorithmImpl::setInputParameter(string name, void *value){
	inputParameters[name] = value;
}

void * EvolutionaryAlgorithmImpl::getInputParameter(string name){
	return inputParameters[name];
}

void EvolutionaryAlgorithmImpl::runEvolutionaryMultiObjectivesLoop(){
	
  	auto evaluations = int{0};

	PopulationImpl * population;
	PopulationImpl * offspringPopulation;
	PopulationImpl * unionPopulation;
  
    // read the parameters
    int maxEvaluations = *(int *)getInputParameter("numberOfGenerations");
    int parentPopulationSize = *(int *)getInputParameter("parentPopulationSize");
    int offspringPopulationSize = *(int *) getInputParameter("offspringPopulationSize");
 

    auto distance = new CDistance<IndividualImpl,PopulationImpl>();
    population = new PopulationImpl(parentPopulationSize);

   // Crossover Operator Initialization
    double xoverProbability = getCrossoverProbability();
    double xoverDistributionId = getCrossoverDistributionId();
    auto crossoverOperator = make_unique<CSBXCrossover<IndividualImpl>>(xoverProbability, xoverDistributionId);

    double mutationProbability = getMutationProbability();
    double mutationDistributionId= getMutationDistributionId();
    auto mutationOperator = make_unique<CPolynomialMutation<IndividualImpl>>(mutationProbability,
    mutationDistributionId);
    
    auto selectionOperator = make_unique<CBT2Selection<IndividualImpl,PopulationImpl>>();

   // Create Random Initial population
    LOG_MSG(msgType::INFO, "Starting Random Initialization of Population...");
    for (int i = 0; i < parentPopulationSize; i++) {
        IndividualImpl * newIndividual = new IndividualImpl();
        newIndividual->evaluate(); // Evaluate ini_pop
        //newIndividual->evaluateConstraints(newIndividual);
        evaluations++;
        population->add(newIndividual);
    } 
    LOG_MSG(msgType::INFO, "Random Initialization of Population is finished");
    
    while (evaluations < maxEvaluations) {

        // Create the offSpring solutionSet
        offspringPopulation = new PopulationImpl(offspringPopulationSize);
        
        IndividualImpl ** parents = new IndividualImpl*[2];
    
        for (auto i = 0; i < (parentPopulationSize / 2); i++) {

            if (evaluations < maxEvaluations) {
                //obtain parents
                parents[0] = selectionOperator->run(population);
                parents[1] = selectionOperator->run(population);

                IndividualImpl ** offSpring = crossoverOperator->run(parents);

                mutationOperator->run(offSpring[0]);
                mutationOperator->run(offSpring[1]);

                offSpring[0]->evaluate();
                //offSpring[0]->evaluateConstraints();
                offSpring[1]->evaluate();
                //offSpring[1]->evaluateConstraints();
                offspringPopulation->add(offSpring[0]);
                offspringPopulation->add(offSpring[1]);
                evaluations += 2;

                delete[] offSpring;

            }
        } 
        delete[] parents;

        // Create the union of individuals (solutions)
        unionPopulation = population->join(offspringPopulation);
        delete offspringPopulation;
    
        // Ranking the union
        auto ranking = new CRanking<IndividualImpl, PopulationImpl>(unionPopulation);

        int remain = parentPopulationSize;
        int index = 0;
        PopulationImpl * front = nullptr;
        for (auto i=0; i < population->size(); i++) 
            delete population->get(i);
        
        population->clear();
    
        // Obtain the next front
        front = ranking->getSubfront(index);
        
        while ((remain > 0) && (remain >= front->size())) {
            //Assign crowding distance to individuals
            distance->allocCrowdingDistance(front, getNumberOfObjectives());
      
            //Add the individuals of this front
            for (auto k = 0; k < front->size(); k++) 
                population->add(new IndividualImpl(front->get(k)));
      
            //Decrement remain
            remain = remain - front->size();

            //Obtain the next front
            index++;
            if (remain > 0) 
                front = ranking->getSubfront(index);
        }
        // Remain is less than front(index).size, insert only the best one
        if (remain > 0) {  // front contains individuals to insert
            distance->allocCrowdingDistance(front, getNumberOfObjectives());
            CComparator<IndividualImpl> * c = new CCrowdingComparator<IndividualImpl>();
            front->sort(c);
            delete c;
            for (auto k = 0; k < remain; k++) 
                population->add(new IndividualImpl(front->get(k)));  
            remain = 0;
        } 
      
        delete ranking;
        delete unionPopulation;
    } 

    delete distance;

    // Return the first non-dominated front
    auto ranking = new CRanking<IndividualImpl, PopulationImpl>(population);
    PopulationImpl * result = new PopulationImpl(ranking->getSubfront(0)->size());
    for (auto i=0; i < ranking->getSubfront(0)->size(); i++) 
        result->add(new IndividualImpl(ranking->getSubfront(0)->get(i)));
  
	LOG_MSG(msgType::INFO,"Variables values are in file variables");
	result->printVariablesToFile("variables");
	LOG_MSG(msgType::INFO,"Objectives values are in file solutions");
	result->printObjectivesToFile("solutions");

    delete ranking;
    delete population;
#ifdef QMETRICS  
    auto metrics = make_unique<CQMetrics>("solutions",PARETO_TRUE_FILE,2);
    auto hv = metrics->getMetric<CQMetricsHV>();
    auto gd = metrics->getMetric<CQMetricsGD>();
    auto igd = metrics->getMetric<CQMetricsIGD>();
    std::ostringstream statInfo;
    statInfo << "Quality Metrics: " << std::endl
    << "HyperVolume = " << hv << std::endl
    << "Generational distance = " << gd << std::endl
    << "Inverted generational distance  = " << igd << std::endl;
    auto statistics = (statInfo.str());
    LOG_MSG(msgType::INFO, statistics);
#endif


/*
  return result;*/
}

EvolutionaryAlgorithmImpl::EvolutionaryAlgorithmImpl(Parameters* params) : CEvolutionaryAlgorithm(params){
	
}

EvolutionaryAlgorithmImpl::~EvolutionaryAlgorithmImpl(){

}

/***************************************************/
/*            PopulationImpl class 	               */
/***************************************************/

PopulationImpl::PopulationImpl() {
      
} 

PopulationImpl::PopulationImpl (int maxSize) : capacity_(maxSize){
    
}

PopulationImpl::~PopulationImpl(){
    for (auto i : pop_vect) 
        delete i;
}

PopulationImpl * PopulationImpl::join(PopulationImpl *another) {
    PopulationImpl *result =
        new PopulationImpl(pop_vect.size()+another->size());
    for (auto i=0; i < pop_vect.size(); ++i) 
        result->add(new IndividualImpl(this->get(i)));
  
    for (auto i=0; i < another->size(); ++i) 
        result->add(new IndividualImpl(another->get(i)));
  
    return result;
} 



bool PopulationImpl::add(int index, IndividualImpl * indiv) {
    if (index < 0) 
        LOG_ERROR(errorCode::value, "index of PopulationImpl is out of range");

    pop_vect.insert(pop_vect.begin()+index, indiv);
    return true;
}

IndividualImpl * PopulationImpl::get(int ind){
    if (ind < 0 || ind >= pop_vect.size())
        LOG_ERROR(errorCode::value, "index of PopulationImpl is out of range")

    return pop_vect[ind];
}

bool PopulationImpl::add(IndividualImpl * indiv) {
    if (pop_vect.size() >= capacity_)
        LOG_ERROR(errorCode::value, "maximum capacity of PopulationImpl has been reached");

    pop_vect.emplace_back(indiv);

    return true;
}


void PopulationImpl::sort(CComparator<IndividualImpl> * comparator){
  if (comparator == nullptr)
     LOG_ERROR(errorCode::target_specific, " there is no criterium for comparing");

  for (auto i = 0; i < pop_vect.size(); ++i) {
    for (auto j = i+1; j < pop_vect.size(); ++j) {
      if ((comparator->compare(pop_vect[i],pop_vect[j]))==1) {
    //      swap<IndividualImpl>(pop_vect[i], pop_vect[j]);
          std::swap(pop_vect[i], pop_vect[j]);
      }
    }
  }
}

void PopulationImpl::printVariablesToFile(string file) {
    std::ofstream out(file.c_str());
    for (auto i : pop_vect)
        out << i->toString() << endl ;

    out.close();
}

void PopulationImpl::printObjectivesToFile(string file){
    std::ofstream out(file.c_str());
    cout.setf(ios::fixed);

    for (auto i : pop_vect) {
        int nbObj = i->getNumberOfObjectives();
        for (auto obj = 0; obj < nbObj; obj++)
            out << i->getObjective(obj) << " ";

        out << endl;
    }
    out.close();
}


\START_CUDA_GENOME_H_TPL

#ifndef PROBLEM_DEP_H
#define PROBLEM_DEP_H

//#include "CRandomGenerator.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <limits>
#include <map>
#include <CIndividual.h>
#include <CVariable.h>
#include <CLogger.h>
#include <Parameters.h>
#include <CDoubleType.h>
#include <CPermutation.h>

#include <CComparator.h>

using namespace std;

class CRandomGenerator;
class CSelectionOperator;
class CGenerationalCriterion;
class CEvolutionaryAlgorithm;
class PopulationImpl;
class Parameters;

extern int EZ_POP_SIZE;
extern int OFFSPRING_SIZE;

\INSERT_USER_CLASSES_DEFINITIONS





/***************************************************/
/*            IndividualImpl class 				  */
/**************************************************/
class IndividualImpl : public CIndividual {

public: // in EASEA the genome is public (for user functions,...)
	// Class members
  	\INSERT_GENOME
  
public:
	IndividualImpl();
	IndividualImpl(IndividualImpl *genome);
   ~IndividualImpl();
	float evaluate();
	double *getDescisionVariables();

	// Not used in this version of lib EASEA
    CIndividual* crossover(CIndividual** p2);
	void optimiser(int currentIteration);
	void printOn(std::ostream& O) const;
	CIndividual* clone();
	string toString(); 
	unsigned mutate(float pMutationPerGene);
	void boundChecking();
    string serialize();
    void deserialize(string AESAE_Line);
};


class PopulationImpl {
private:
int capacity_;
std::vector<IndividualImpl*> pop_vect;
public:
    PopulationImpl();
    PopulationImpl(int maxSize);
    ~PopulationImpl();
    PopulationImpl * join(PopulationImpl * another);
    bool add(IndividualImpl * indiv);
  	bool add(int index, IndividualImpl * indiv);
    IndividualImpl *get(int index);
    inline auto size() const { return pop_vect.size(); }
    void clear(){ pop_vect.clear(); }
    void sort(CComparator<IndividualImpl> * comparator);
    void printObjectivesToFile(string path);
    void printVariablesToFile(string file);	
};




/**
 * @TODO ces functions devraient s'appeler weierstrassInit, weierstrassFinal etc... (en gros EASEAFinal dans le tpl).
 *
 */

void EASEAInit(int argc, char** argv);
//void EASEAFinal(CPopulation* pop);
void EASEABeginningGenerationFunction(CEvolutionaryAlgorithm* evolutionaryAlgorithm);
void EASEAEndGenerationFunction(CEvolutionaryAlgorithm* evolutionaryAlgorithm);
void EASEAGenerationFunctionBeforeReplacement(CEvolutionaryAlgorithm* evolutionaryAlgorithm);


class EvolutionaryAlgorithmImpl: public CEvolutionaryAlgorithm {
private:
	std::map<string, void *> inputParameters;
public:
    PopulationImpl *population;
	EvolutionaryAlgorithmImpl(Parameters* params);
	EvolutionaryAlgorithmImpl();
	~EvolutionaryAlgorithmImpl();
	void runEvolutionaryMultiObjectivesLoop();
	void setInputParameter(string name, void *value);
    void * getInputParameter(string name);
	void initializeParentPopulation();
};

class ParametersImpl : public Parameters {
public:
	void setDefaultParameters(int argc, char** argv);
	EvolutionaryAlgorithmImpl* newEvolutionaryAlgorithm();
};

#endif 

\START_CUDA_MAKEFILE_TPL

UNAME := $(shell uname)

#ifeq($(shell uname -o 2>/dev/null),Msys)
#	OS := MINGW
#endif

ifneq ("$(OS)","")
	EZ_PATH=../../
endif

EASEALIB_PATH=$(EZ_PATH)libeasea/

CXXFLAGS = -std=c++14 -fpermissive -fopenmp -O3 -g -Wall -fmessage-length=0 -I$(EASEALIB_PATH)include 

OBJS = EASEA.o EASEAIndividual.o 

LIBS = -lpthread -fopenmp
ifneq ("$(OS)","")
	LIBS += -lw2_32 -lwinmm -L"C:\MinGW\lib"
endif

#USER MAKEFILE OPTIONS :
\INSERT_MAKEFILE_OPTION#END OF USER MAKEFILE OPTIONS

TARGET =	EASEA

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS) -g $(EASEALIB_PATH)libeasea.a  $(LIBS)

	
#%.o:%.cpp
#	$(CXX) -c $(CXXFLAGS) $^

all:	$(TARGET)
clean:
ifneq ("^$(OS)","")
	-del $(OBJS) $(TARGET).exe
else
	rm -f $(OBJS) $(TARGET)
endif
easeaclean:
ifneq ("$(OS)","")
	-del $(TARGET).exe *.o *.cpp *.hpp EASEA.png EASEA.dat EASEA.prm EASEA.mak Makefile EASEA.vcproj EASEA.csv EASEA.r EASEA.plot EASEA.pop
else	
	rm -f $(TARGET) *.o *.cpp *.hpp EASEA.png EASEA.dat EASEA.prm EASEA.mak Makefile EASEA.vcproj EASEA.csv EASEA.r EASEA.plot EASEA.pop
endif
	
\START_EO_PARAM_TPL#****************************************
#                                         
#  EASEA.prm
#                                         
#  Parameter file generated by STD.tpl AESAE v1.0
#                                         
#***************************************
# --seed=0   # -S : Random number seed. It is possible to give a specific seed.

######    Evolution Engine    ######
--popSize=\POP_SIZE # -P : Population Size
--nbOffspring=\OFF_SIZE # -O : Nb of offspring (percentage or absolute)

######	  Stopping Criterions    #####
--nbGen=\NB_GEN #Nb of generations
--timeLimit=\TIME_LIMIT # Time Limit: desactivate with (0) (in Seconds)

######    Evolution Engine / Replacement    ######
--elite=\ELITE_SIZE  # Nb of elite parents (absolute)
--eliteType=\ELITISM # Strong (1) or weak (0) elitism (set elite to 0 for none)
--survivingParents=\SURV_PAR_SIZE # Nb of surviving parents (percentage or absolute)
--survivingOffspring=\SURV_OFF_SIZE  # Nb of surviving offspring (percentage or absolute)
--selectionOperator=\SELECTOR_OPERATOR # Selector: Deterministic, Tournament, Random, Roulette 
--selectionPressure=\SELECT_PRM
--reduceParentsOperator=\RED_PAR_OPERATOR 
--reduceParentsPressure=\RED_PAR_PRM
--reduceOffspringOperator=\RED_OFF_OPERATOR 
--reduceOffspringPressure=\RED_OFF_PRM
--reduceFinalOperator=\RED_FINAL_OPERATOR
--reduceFinalPressure=\RED_FINAL_PRM

######    Local Optimisation    ######
--optimiseIterations=\NB_OPT_IT
--baldwinism=\BALDWINISM # True (1) or False (0) baldwinism : keep optimised genome

#####	Stats Ouput 	#####
--printStats=\PRINT_STATS #print Stats to screen
--plotStats=\PLOT_STATS #plot Stats
--printInitialPopulation=0 #Print initial population
--printFinalPopulation=0 #Print final population
--generateCSVFile=\GENERATE_CSV_FILE
--generatePlotScript=\GENERATE_GNUPLOT_SCRIPT
--generateRScript=\GENERATE_R_SCRIPT

#### Population save    ####
--savePopulation=\SAVE_POPULATION #save population to EASEA.pop file
--startFromFile=\START_FROM_FILE #start optimisation from EASEA.pop file

#### Remote Island Model ####
--remoteIslandModel=\REMOTE_ISLAND_MODEL #To initialize communications with remote AESAE's
--ipFile=\IP_FILE
--migrationProbability=\MIGRATION_PROBABILITY #Probability to send an individual every generation
--serverPort=\SERVER_PORT
\TEMPLATE_END
