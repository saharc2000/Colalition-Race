#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) , mCoalitions(0)
{
    setCoalitions();
}

void Simulation::step()
{
    int n = mGraph.getNumVertices();
    for (int i=0;i<n;i++){
        Party &party = mGraph.getParty(i);
        party.step(*this);
    }   

    for(Agent &agent : mAgents){
        agent.step(*this);
    }
}

bool IsOverSixtyMandates(const vector<Coalition> &coalitions){
    for(const Coalition &c : coalitions){
        if(c.getMandates()>60){
            return true;
        }
    }
    return false;
}

bool AreAllPartiesJoined(const Graph &g){
    int n = g.getNumVertices();
    for (int i=0;i<n;i++){
        if(g.getParty(i).getState()!=Joined)
          return false;
    }
    return true;
}

bool Simulation::shouldTerminate() const
{ 
  return IsOverSixtyMandates(mCoalitions) || AreAllPartiesJoined(mGraph);  
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

void Simulation::addAgent(Agent &a){
    mAgents.push_back(a);
}

const vector<Coalition> &Simulation::getCoaliotions() const
{
    return mCoalitions;
}

void Simulation::setCoalitions(){
    for(const Agent &agent : mAgents){
        int id = agent.getPartyId();
        Party &p = mGraph.getParty(id);
        p.setAgentId(agent.getId());
        vector<int> vParty;
        vParty.push_back(p.getId());
        Coalition *c = new Coalition(agent.getId(),p.getMandates(),vParty);
        p.setCoalitionId(c->getId());
        mCoalitions.push_back(*c);
        delete c;
    }
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> coalitions;
    for (const Coalition &c : mCoalitions)
    {
        const vector<int> partiesId = c.getPartiesId();
        coalitions.push_back(partiesId);
    }
    return coalitions;
}

const Agent &Simulation::getAgentById(int id) const
{
    return mAgents[id];
}

const Coalition &Simulation::getCById(int id) const
{
    return mCoalitions[id];
}

void Simulation::addPartyToC(Party &party, int coalitionId)
{
    mCoalitions[coalitionId].addParty(party);
}