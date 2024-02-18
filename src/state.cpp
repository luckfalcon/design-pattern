#include"state.h"
#include<iostream>
using namespace std;
void AMWorkState::writeProgram(Work *work)
{
    if (work->getHour() < 12)
    {
        cout << work->getHour() << " 点: "
             << "上午工作精神百倍！" << endl;
    }
    else
    {
        work->setState(new NoonWorkState());
        work->writeProgram();
    }
}

void Work::writeProgram()
{
    state->writeProgram(this);
}

void NoonWorkState::writeProgram(Work *work)
{
    if (work->getHour() < 13)
        cout << work->getHour() << " 点: "
             << "饿了，犯困，午休!" << endl;
    else
    {
        work->setState(new PMWorkState());
        work->writeProgram();
    }
}

void PMWorkState::writeProgram(Work *work)
{
    if (work->getHour() < 17)
        cout << work->getHour() << " 点: "
             << "下午状态还不错，继续努力！" << endl;
    else
    {
        work->setState(new EvenWorkState());
        work->writeProgram();
    }
}

void EvenWorkState::writeProgram(Work *work)
{
    if(work->getTask())
    {
        work->setState(new AfterWorkState());
        work->writeProgram();
    }
    else
    {
        if (work->getHour() < 21)
            cout << work->getHour() << " 点: "
                 << "加班，疲惫至极！" << endl;
        else
        {
            work->setState(new SleepWorkState());
            work->writeProgram();
        }
    }
}

void AfterWorkState::writeProgram(Work *work)
{
    cout << work->getHour() << " 点: "
         << "下班了回家了！" << endl;
}

void SleepWorkState::writeProgram(Work *work)
{
    cout << work->getHour() << " 点: "
         << "不行了，睡着了！" << endl;
}

void test_state()
{
    Work *w = new Work();
    w->setHour(9);
    w->writeProgram();
    w->setHour(10);
    w->writeProgram();
    w->setHour(12);
    w->writeProgram();
    w->setHour(13);
    w->writeProgram();
    w->setHour(14);
    w->writeProgram();
    w->setHour(17);
    w->SetTask(false);
    w->writeProgram();
    w->setHour(19);
    w->writeProgram();
    w->setHour(22);
    w->writeProgram();
}
