#pragma once
#include <string>

/*
整体与部分关系，将部分抽出来单独设置不同状态下的行为
*/
class Work;
class State
{
public:
    State() {}
    virtual ~State() {}
    virtual void writeProgram(Work *work) = 0;
};

class AMWorkState : public State
{
public:
    void writeProgram(Work *work) override;
};
class NoonWorkState : public State
{

public:
    void writeProgram(Work *work) override;
};
class PMWorkState : public State
{

public:
    void writeProgram(Work *work) override;
};
class EvenWorkState : public State
{

public:
    void writeProgram(Work *work) override;
};

class AfterWorkState : public State
{

public:
    void writeProgram(Work *work) override;
};
class SleepWorkState : public State
{

public:
    void writeProgram(Work *work) override;

};
class Work // 工作包含两部分，第一部分工作状态，第二部分是工作不同工作状态下的行为
{
public:
    Work() : state(new AMWorkState()) {}//工作初始状态
    void setState(State *state)         {//设置工作状态
        this->state = state;
    }
    ~Work(){
        if (state != nullptr)
        delete state;
    }
    
    void setHour(double hour){  //工作状态转换的凭据属性
        this->hour = hour;
    }
    double getHour(){return hour;}
    void SetTask(bool finish){
        this->finished = finish;
    }
    bool getTask(){return finished;}
    void writeProgram();
protected:
    State *state;
    double hour;
    bool finished;
};
void test_state();