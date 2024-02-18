#include "prototype.h"
#include<iostream>
using namespace std;

void Resume::SetPersonInfo(const std::string &sex, const std::string &age)
{
    this->sex = sex;
    this->age = age;
}

void Resume::SetWorkExperience(const std::string &workDate, const std::string &company)
{
    workExp->SetWorkDate(workDate);
    workExp->SetCompay(company);
}

void Resume::Display()
{
    cout << sex << name << age << endl;
    cout << "工作经历： " << workExp->GetWrorkDate() << workExp->GetCompany() << endl;
}

Resume *Resume::Clone()
{
    Resume *wp = new Resume(workExp);//深度拷贝
    wp->name = this->name;
    wp->sex = this->sex;
    wp->age = this->age;
    return wp;
}

void test_prototype()
{
    Resume *a = new Resume("大鸟");
    a->SetPersonInfo("男","18");
    a->SetWorkExperience("2018-01-02","xx企业");
    Resume *b = a->Clone();
    b->SetWorkExperience("2020-07-09","yy企业");
    Resume *c = a->Clone();
    c->SetPersonInfo("女", "25");
    a->Display();
    b->Display();
    c->Display();
}
