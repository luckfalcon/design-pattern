#include "Chain_of_Responsibility.h"
#include <iostream>
using namespace std;

void CommonManager::requestApplications(Request *request)
{
    if (request->getRequestType() == "请假" && request->getNumber() <= 2)
    {
        cout << name << " " << request->getRequstContent() << " : " << request->getNumber() << " 被批准！" << endl;
    }
    else if (superior != nullptr)
    {
        superior->requestApplications(request);
    }
}

void Majordomo::requestApplications(Request *request)
{
    if (request->getRequestType() == "请假" && request->getNumber() <= 5)
    {
        cout << name << " " << request->getRequstContent() << " : " << request->getNumber() << "被批准！" << endl;
    }
    else if (superior != nullptr)
    {
        superior->requestApplications(request);
    }
}

void GeneralManager::requestApplications(Request *request)
{
    if (request->getRequestType() == "请假")
    {
        cout << name << " " << request->getRequstContent() << " : " << request->getNumber() << " 被批准！" << endl;
    }
    else if (request->getRequestType() == "加薪" && request->getNumber() <= 500)
    {
        cout << name << " " << request->getRequstContent() << " : " << request->getNumber() << " 被批准！" << endl;
    }
    else if (request->getRequestType() == "加薪" && request->getNumber() > 500)
    {
        cout << name << " " << request->getRequstContent() << " : " << request->getNumber() << " 再说吧！" << endl;
    }
}

void test_Chain_of_Responsibility()
{
    // 建立不同审批级别对象
    CommonManager *jinli = new CommonManager("金利");
    Majordomo *zongjian = new Majordomo("宗剑");
    GeneralManager *zhongjinli = new GeneralManager("钟精励");
    // 设置请求传递链
    jinli->setSuperior(zongjian);
    zongjian->setSuperior(zhongjinli);
    // 设置请求 类型，内容，数量
    Request *request = new Request();
    request->setRequestType("请假");
    request->setRequstContent("小菜请假");
    request->setNumber(1);
    // 分配请求给开始职位
    jinli->requestApplications(request);
    //--------------------------------------------
    Request *request2 = new Request();
    request2->setRequestType("请假");
    request2->setRequstContent("小菜请假");
    request2->setNumber(4);
    // 分配请求给开始职位
    jinli->requestApplications(request2);
    //------------------------------------
    Request *request3 = new Request();
    request3->setRequestType("加薪");
    request3->setRequstContent("小菜请求加薪");
    request3->setNumber(500);
    // 分配请求给开始职位
    jinli->requestApplications(request3);
    //------------------------------------
    Request *request4 = new Request();
    request4->setRequestType("加薪");
    request4->setRequstContent("小菜请求加薪");
    request4->setNumber(1000);
    // 分配请求给开始职位
    jinli->requestApplications(request4);
    //------------------------------------
    Request *request5 = new Request();
    request5->setRequestType("加薪");
    request5->setRequstContent("小菜请求加薪");
    request5->setNumber(5000);
    zhongjinli->requestApplications(request5); // 直接跳过没有权限的级别，找到可以处理的级别
}
