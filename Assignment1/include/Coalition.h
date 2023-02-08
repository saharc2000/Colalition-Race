#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Coalition
{
public:
    Coalition();
    Coalition(int id,int mandates , vector<int> &partiesId);
    int getMandates() const;
    const vector<int> &getPartiesId() const;
    void addParty(Party &p);
    const int getId() const;

private:
    int mId;
    int mmandates;
    vector<int> mPartiesId;
};
