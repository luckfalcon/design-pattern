#pragma once
#include<string>
//核心思想：实现装扮子类的方法中要先调用父类的同名方法，再运行子类，从而实现装扮
/*组织结构
              Component(抽象类)--> +operation()
    定义一个对象接口，可以给这个对象动态添加职责
        ---------------------------------
        |                                |
    ConcreteComponent                  Decorator
    +opertion()                        +operation(),-component           
                                     --------------------
                                     |                   |
                                ConcreteDecoratorA       B    
*/

class Person    //ConcreteComponent
{
    public:
        Person(const std::string &name):PersonName(name){}
        Person() = default;
        virtual void show();
    private:
    std::string PersonName;
};
class Finery:public Person//服饰类 Decorator
{
    public:
    Finery():Component(nullptr){}
    //打扮
    void Decorate(Person *component);
    void show()override;
    protected://供子类调用
    Person *Component;//基类指针实现多态

};
class Tshirts:public Finery//具体服饰类 ConcreteDecorator
{
    public:
    void show()override;

};
class BigTrouser:public Finery
{
    public:
    void show()override;
};
void test_decorator();