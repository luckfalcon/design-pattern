#include "singleton.h"
#include <iostream>
using namespace std;

Singleton *Singleton::instance = nullptr;

Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Singleton("I am Singleton!");//多线程安全问题，需要加双重锁
    }
    return instance;
}

void Singleton::show()
{
    cout << name << endl;
}

void test_singleton()
{
    Singleton *s1 = Singleton::getInstance();
    s1->show();
    Singleton *s2 = Singleton::getInstance();
    s2->show();
    if (s1 == s2)
        cout << "the two subjects are the same one!" << endl;
    else
        cout << "the two subjects are different!" << endl;
}
// 多线程单例模式

// Singleton *Singleton::getInstance()
// {
//     if (instance == nullptr)//双重锁
//         lock(synToot)
//         {
//             if(instance == nullptr)//单锁
//             {
//                 instance = new Singleton("I am Singleton!");
//             }
//             return instance;
//         }
// }
