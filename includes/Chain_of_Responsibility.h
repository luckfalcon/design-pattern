#pragma once
#include <string>

class Request
{
public:
    void setRequestType(const std::string &type) { requestType = type; }
    std::string getRequestType() { return requestType; }
    void setRequstContent(const std::string &content) { requestContent = content; }
    std::string getRequstContent() { return requestContent; }
    void setNumber(int num) { number = num; }
    int getNumber() { return number; }

private:
    std::string requestType;
    std::string requestContent;
    int number;
};
// 管理者类
class Manager
{
protected:
    std::string name;
    Manager *superior; // 管理者的上级
public:
    Manager(const std::string &name) : name(name), superior(nullptr) {}
    virtual ~Manager() {}
    // 设置管理者的上级
    void setSuperior(Manager *superior) { this->superior = superior; }
    // 申请请求
    virtual void requestApplications(Request *request) = 0; // 请求链
};
// 经理
class CommonManager : public Manager
{
public:
    CommonManager(const std::string &name) : Manager(name) {}
    ~CommonManager()
    {
        if (superior != nullptr)
            delete superior;
    }
    void requestApplications(Request *request) override;
};
// 总监
class Majordomo : public Manager
{
public:
    Majordomo(const std::string &name) : Manager(name) {}
    ~Majordomo()
    {
        if (superior != nullptr)
            delete superior;
    }
    void requestApplications(Request *request) override;
};
// 总经理
class GeneralManager : public Manager
{
public:
    GeneralManager(const std::string &name) : Manager(name) {}
    ~GeneralManager()
    {
        if (superior != nullptr)
            delete superior;
    }
    void requestApplications(Request *request) override;
};
void test_Chain_of_Responsibility();