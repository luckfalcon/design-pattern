#pragma once

#include <string>

class PersonProduct
{
public:
    PersonProduct() {}
    ~PersonProduct() {}
    PersonProduct(const std::string &name) : name(name) {}
    void setHead(const std::string &head)
    {
        this->head = head;
    }
    void setBody(const std::string &body)
    {
        this->body = body;
    }
    void setHand(const std::string &hand)
    {
        this->hand = hand;
    }
    void setFoot(const std::string &foot)
    {
        this->foot = foot;
    }
    void show();

private:
    std::string name;
    std::string head;
    std::string body;
    std::string hand;
    std::string foot;
};
class PersonBuilder // 抽象类，定义product实现的各个抽象接口
{
public:
    PersonBuilder(){}; // 抽象类
    virtual ~PersonBuilder(){};
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildHand() = 0;
    virtual void buildFoot() = 0;
    virtual PersonProduct *getPersonProduct() = 0;
};
class PersonThinBuilder : public PersonBuilder
{
public:
    PersonThinBuilder(const std::string &name) : pp(new PersonProduct(name)) {}
    ~PersonThinBuilder()
    {
        if (pp != nullptr)
            delete pp;
    }
    void buildHead() override;
    void buildBody() override;
    void buildHand() override;
    void buildFoot() override;
    PersonProduct *getPersonProduct() override
    {
        return pp;
    }

private:
    PersonProduct *pp;
};
class PersonFatBuilder : public PersonBuilder
{
public:
    PersonFatBuilder(const std::string &name) : pp(new PersonProduct(name)) {}
    ~PersonFatBuilder()
    {
        if (pp != nullptr)
            delete pp;
    }
    void buildHead() override;
    void buildBody() override;
    void buildHand() override;
    void buildFoot() override;
    PersonProduct *getPersonProduct() override
    {
        return pp;
    }

private:
    PersonProduct *pp;
};
class PersonDirector
{
public:
    void createPerson(PersonBuilder *pb);
};
void test_builder();