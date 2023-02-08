#pragma once

#include "Graph.h"
#include "SelectionPolicy.h"

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent &other);//copy constructor
    virtual ~Agent();//destructor
    Agent& operator=(const Agent &other);//copy assignment operator
    Agent(Agent&& other);//move constructor 
    Agent& operator=(Agent&& other);//move assignment opertor

    int getPartyId() const;
    void setPartyId(int id);
    int getId() const;
    void setId(int id);
    void step(Simulation &);
    SelectionPolicy* getPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
