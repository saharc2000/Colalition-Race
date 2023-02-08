#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<Coalition> &getCoaliotions() const;
    void setCoalitions();
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addAgent(Agent &a);
    Graph &getGraph();
    const Agent &getAgentById(int id) const;
    void addPartyToC(Party &party,int coalitionId);
    const Coalition &getCById(int id) const;
    
private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};
