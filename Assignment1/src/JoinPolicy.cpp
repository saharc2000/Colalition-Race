#include "JoinPolicy.h"
#include "Simulation.h"

MandatesJoinPolicy* MandatesJoinPolicy::clone(){
    return new MandatesJoinPolicy;
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy;
}

void add(Party &pToJoin,Party &joiningParty,Simulation &s){
    int coalitionId = pToJoin.getCoalitionId();
    s.addPartyToC(joiningParty,coalitionId);
    joiningParty.setCoalitionId(coalitionId);
    joiningParty.setState(Joined);
    int id = s.getAgents().size();
    const Agent &a = s.getAgentById(pToJoin.getAgentId());
    Agent newAgent(a);
    newAgent.setId(id);
    newAgent.setPartyId(joiningParty.getId());
    int x = newAgent.getId();
    s.addAgent(newAgent);
    joiningParty.setAgentId(x);
}

void MandatesJoinPolicy::join(Party &joiningParty,Simulation &s){
    const vector<int> &offers = joiningParty.getOffers();
    int maxMandates = 0;
    int maxMandatesId = -1;
    Graph &g = s.getGraph();
    for (int a : offers){
        int coalitionId = g.getParty(a).getCoalitionId();
        int coalitionMandates =  s.getCById(coalitionId).getMandates();
        if(maxMandates < coalitionMandates){
            maxMandates = coalitionMandates;
            maxMandatesId = a;
        }
    }
    
    Party &pToJoin = g.getParty(maxMandatesId);
    add(pToJoin,joiningParty,s);
}

void LastOfferJoinPolicy::join(Party &joiningParty,Simulation &s){
    const vector<int> &offers = joiningParty.getOffers();
    int last = offers.back();
    Graph &g = s.getGraph();
    Party &pToJoin = g.getParty(last);
    add(pToJoin,joiningParty,s);
}