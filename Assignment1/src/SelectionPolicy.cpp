#include "SelectionPolicy.h"
#include "Graph.h"
#include "Simulation.h"
#include "Party.h"

SelectionPolicy::~SelectionPolicy(){ }

MandatesSelectionPolicy* MandatesSelectionPolicy::clone(){
    return new MandatesSelectionPolicy;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone(){
    return new EdgeWeightSelectionPolicy;
}

void addOfferToParty(Party &p, int partyId)
{
    p.addOffers(partyId);
        if(p.getState() == Waiting){
            p.setState(CollectingOffers);
        }
}

bool areConnected(Party &offerParty, Party & partyToOffer,Simulation &s)
{
    const Graph &g = s.getGraph();
    return g.getEdgeWeight(offerParty.getId(), partyToOffer.getId())>0;
}

bool isAlreadyOffered (Party &offerParty, Party & partyToOffer,Simulation &s)
{   //TODO: change to const refference?
    Graph &g = s.getGraph();
    const vector<int> &offers = partyToOffer.getOffers();
    for(int o: offers){
        Party &party = g.getParty(o);
        if( party.getCoalitionId()==offerParty.getCoalitionId()) {
            return false;
        }
    }
    return true;
}

bool isLegelToOffer(Party &offerParty, Party &partyToOffer,Simulation &s)
{ 
    return partyToOffer.getState()!=Joined && areConnected(offerParty,partyToOffer,s) && isAlreadyOffered(offerParty,partyToOffer,s);
}

void MandatesSelectionPolicy::select(Agent &a,Simulation &s){
    int maxMandates = -1;
    int maxMandatesId = -1;
    Graph &g = s.getGraph();
    Party &offerParty = g.getParty(a.getPartyId());
    for (int i=0; i<g.getNumVertices(); i++)
    {   
        Party &partyToOffer = g.getParty(i);
        if(isLegelToOffer(offerParty,partyToOffer,s))
        {
            int madates = g.getMandates(i);
            if(maxMandates < madates)
            {
                maxMandates = madates;
                maxMandatesId = i;
            }
        }
    }
    if (maxMandatesId != -1)
    {
        Party &party = g.getParty(maxMandatesId);
        addOfferToParty(party,offerParty.getId());
    }
    
    
}

void EdgeWeightSelectionPolicy::select(Agent &a,Simulation &s){
    int maxWeight = -1;
    int maxWeightId = -1;
    Graph &g = s.getGraph();
    Party &offerParty = g.getParty(a.getPartyId());

    for (int i=0; i<g.getNumVertices(); i++)
    {   
        Party &partyToOffer = g.getParty(i);
        if(isLegelToOffer(offerParty,partyToOffer, s))
        {
            int weight = g.getEdgeWeight(offerParty.getId(),partyToOffer.getId());
            if(maxWeight < weight)
            {
                maxWeight = weight;
                maxWeightId = i;
            }
        }
    }
    if(maxWeightId !=-1){
        Party &party = g.getParty(maxWeightId);
        addOfferToParty(party,offerParty.getId());
    }
}

