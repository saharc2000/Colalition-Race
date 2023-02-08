#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"

using std::string;
using std::vector;
class Coalition;
class Agent;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party &other);//copy constructor
    virtual ~Party();//destructor
    Party& operator=(const Party &other);//copy assignment operator
    Party(Party&& other);//move constructor 
    Party& operator=(Party&& other);//move assignment opertor

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    const vector<int> &getOffers() const;
    int getId() const;
    int getCoalitionId() const;
    void setCoalitionId(int id);
    void addOffers(int id); 
    int getAgentId() const;
    void setAgentId(int agentId);
  
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    vector<int> offers;
    int mCoalitionId;
    int mAgentId;
};
