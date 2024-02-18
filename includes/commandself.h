#pragma once

class Recieve
{
public:
    void action();
};
class Command
{
public:
    virtual ~Command() {}
    Command(Recieve *recieve) : recieve(recieve) {}
    virtual void execute() = 0;

protected:
    Recieve *recieve;
};
class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Recieve *recieve) : Command(recieve) {}
    ~ConcreteCommand()
    {
        if (recieve != nullptr)
            delete recieve;
    }
    void execute() override;
};

class Invoke
{
public:
    Invoke() {}
    ~Invoke()
    {
        if (command != nullptr)
            delete command;
    }
    void setCommand(Command *command);
    void executeCommand();

private:
    Command *command;
};
void test_command();