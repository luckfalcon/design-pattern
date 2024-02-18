#pragma once

class Eventhandler // void不可省略，否则会引起编译错误
{
public:
    using eP = void (*)();
    Eventhandler() : e(nullptr) {}
    Eventhandler(eP e) : e(e) {}
    void operator()()
    {
        e();
    }
private:
    eP e;
};