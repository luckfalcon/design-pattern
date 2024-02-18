#include "commandself.h"
#include <iostream>
#include <string>
using namespace std;
void Recieve::action()
{
    cout << "执行请求" << endl;
}
void ConcreteCommand::execute()
{
    recieve->action();
}

void Invoke::setCommand(Command *command)
{
    this->command = command;
}

void Invoke::executeCommand()
{
    command->execute();
}

void test_command()
{
    Recieve *r = new Recieve();
    Command *cmd = new ConcreteCommand(r);
    Invoke *i = new Invoke();
    i->setCommand(cmd);
    i->executeCommand();
}
