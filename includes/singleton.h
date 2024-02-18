#pragma once
#include<string>

class Singleton
{
public:
    static Singleton *getInstance();
    void show();
private:
Singleton(const std::string &name):name(name){}
std::string name;
static Singleton *instance;
};
void test_singleton();
//多线程单例模式
