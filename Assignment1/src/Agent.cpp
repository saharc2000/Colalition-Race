#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
}
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone())
{

}

Agent::~Agent()
{
    if (mSelectionPolicy) delete mSelectionPolicy;
}

Agent &Agent::operator=(const Agent &other)
{
    if (this != &other)
    {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
    }
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy->clone();
    return *this;
}

Agent::Agent(Agent &&other) :  mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()) 
{
}

Agent &Agent::operator=(Agent &&other)
{
    if(mSelectionPolicy) delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}

int Agent::getId() const
{
    return mAgentId;
}

void Agent::setId(int id){
    mAgentId=id;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setPartyId(int id){
    mPartyId=id;
}

void Agent::step(Simulation &sim)
{    
    mSelectionPolicy->select(*this, sim);
}

SelectionPolicy *Agent::getPolicy() const
{
    return mSelectionPolicy;
}
