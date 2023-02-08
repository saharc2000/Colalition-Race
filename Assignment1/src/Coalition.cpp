#include "Coalition.h"
Coalition::Coalition():mId(-1), mmandates(0),mPartiesId(0)
{

}
Coalition::Coalition(int id, int mandates ,vector<int> &parties): mId(id), mmandates(mandates), mPartiesId(parties) 
{

}

int Coalition::getMandates() const
{
   return mmandates;
}

const vector<int>& Coalition::getPartiesId() const
{
    return mPartiesId;
}

void Coalition::addParty(Party &p)
{
    mmandates += p.getMandates();
    mPartiesId.push_back(p.getId());
}

const int Coalition::getId() const
{
   return mId;
}

