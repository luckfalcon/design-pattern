#pragma once
#include<string>
class Say
{
    public:
        Say(const std::string &w):speaker(w){}
        void say(const std::string &);

    private:
    std::string speaker;
};