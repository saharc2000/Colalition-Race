#include "Party.h"
#include "Coalition.h"
#include "Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0), offers(0),  mCoalitionId (-1), mAgentId (-1)
{
}

Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), timer(other.timer), offers(other.offers),mCoalitionId(other.mCoalitionId),mAgentId(other.mAgentId)
{

}

Party::~Party()
{
    if(mJoinPolicy) delete mJoinPolicy;
}

Party &Party::operator=(const Party &other)
{
    if(this != &other)
    {
        if(mJoinPolicy) delete mJoinPolicy;
    }
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy->clone();
    mState = other.mState;
    timer = other.timer;
    offers = other.offers;
    mCoalitionId = other.mCoalitionId;
    mAgentId = other.mAgentId;
    return *this;
    }

Party::Party(Party &&other):mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer), offers(other.offers),mCoalitionId(other.mCoalitionId),mAgentId(other.mAgentId)
{
    other.mJoinPolicy = nullptr;
}

Party &Party::operator=(Party &&other)
{
    if(mJoinPolicy) delete mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy =other.mJoinPolicy;
    mState = other.mState;
    timer = other.timer;
    offers = other.offers;
    mCoalitionId = other.mCoalitionId;
    mAgentId = other.mAgentId;
    other.mJoinPolicy = nullptr;
    return *this;
}


State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

int Party::getId() const
{
    return mId;
}

int Party::getCoalitionId() const
{
    return mCoalitionId;
}

void Party::setCoalitionId(int id)
{
    mCoalitionId = id;
}

const string & Party::getName() const
{
    return mName;
}

const vector<int> &Party::getOffers() const 
{
    return offers;
}

void Party::addOffers(int id) 
{
     offers.push_back(id);
}

int Party::getAgentId() const
{
    return mAgentId;
}

void Party::setAgentId(int agentId)
{
    mAgentId = agentId;
}

void Party::step(Simulation &s)
{
    if(mState == CollectingOffers){
        if(timer<3){
            timer++;
        if(timer==3)
            mJoinPolicy->join(*this,s);     
        }
    }
}

