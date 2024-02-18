#pragma once
#include <string>
// 原型类（应该深拷贝，浅拷贝会改变原型状态）-------涉及浅拷贝和深拷贝的知识
class WorkExperience
{
public:
    WorkExperience() {}
    ~WorkExperience() {}

    WorkExperience(WorkExperience *work)//定义用来克隆自身的构造方法
    {
        this->workDate = work->workDate; // 要用深拷贝，引用和指针成员拷贝需特殊处理
        this->company = work->company;
    }
    void SetWorkDate(const std::string &workDate)
    {
        this->workDate = workDate;
    }
    void SetCompay(const std::string &company)
    {
        this->company = company;
    }
    std::string GetWrorkDate()
    {
        return this->workDate;
    }
    std::string GetCompany()
    {
        return this->company;
    }
    WorkExperience *clone()
    {
        return new WorkExperience(this); // 调用本类的构造函数克隆自己
    }

private:
    std::string workDate;
    std::string company;
};
// 原型类，声明一个克隆自身的接口
class Prototype
{
public:
    Prototype() {}
    virtual ~Prototype() {}
    virtual void SetPersonInfo(const std::string &sex, const std::string &age) = 0;
    virtual void Display() = 0;
    virtual Prototype *Clone() = 0;

protected:
    std::string name;
    std::string age;
    std::string sex;
    std::string timeArea;
    std::string company;
};
// 具体原型类，即concreteprototype类，本例中为简历的resume类，实现一个克隆自己的操作
class Resume : public Prototype
{
private:
    WorkExperience *workExp;//引用工作经历对象

public:
    ~Resume()
    {
        if (workExp != nullptr)
            delete workExp;
    }
     Resume(const std::string &name){
         this->name = name;
         workExp = new WorkExperience();//实例化工作经历对象
     }
    // 克隆需要的构造函数
    Resume(WorkExperience *workExp) 
    {
        this->workExp = workExp->clone();
    }
    void SetPersonInfo(const std::string &sex, const std::string &age) override;
    void SetWorkExperience(const std::string &workDate, const std::string &company);
    void Display() override;
    Resume *Clone() override;//c++11引入特性，协变返回类型
    //用协变返回类型可以提高代码的灵活性，允许在派生类中返回更具体的类型，而不需要进行显式的类型转换。
    //协变返回类型仅适用于指针或引用类型的返回，对于返回值类型的情况，仍然需要保持与基类相同的返回类型。
};
//client客户端
void test_prototype();