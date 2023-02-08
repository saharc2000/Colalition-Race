#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Agent;
class Simulation;
class Graph;

class SelectionPolicy { 
    public:
        virtual void select(Agent &a,Simulation &s) = 0;
        virtual ~SelectionPolicy();
        virtual SelectionPolicy* clone() = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        void select(Agent &a,Simulation &s) override;
        virtual ~MandatesSelectionPolicy(){};
        MandatesSelectionPolicy* clone() override;

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        void select(Agent &a,Simulation &s) override;
        virtual ~EdgeWeightSelectionPolicy(){};
        EdgeWeightSelectionPolicy* clone() override;
 };

