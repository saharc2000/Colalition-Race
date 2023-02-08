#pragma once

class Party;
class Simulation;

class JoinPolicy {
    public:
        virtual void join(Party &p,Simulation &s) = 0;
        virtual ~JoinPolicy() {};
        virtual JoinPolicy* clone() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        void join(Party &p,Simulation &s) override;
        virtual ~MandatesJoinPolicy(){};
        MandatesJoinPolicy* clone() override;

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        void join(Party &p,Simulation &s) override;
        virtual ~LastOfferJoinPolicy(){};
        LastOfferJoinPolicy* clone() override;
};