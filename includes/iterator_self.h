 #pragma once
// #include <list>
// #include<string>
// /*

// */
// // class object//boject = string
// // {
// // };
// // 迭代器抽象类
// class Iterator_self
// {
// public:
//     virtual std::string *first_self() = 0;
//     virtual std::string *next_self() = 0;
//     virtual bool isDone_self() = 0;
//     virtual std::string *currentItem_self() = 0;
// };

// // 聚集抽象类
// class Aggregate_self
// {
// public:
//     virtual Iterator_self *CreateIterator_self() = 0;
// };

// class ConcreteAggregate_self;
// // 具体迭代器类
// class ConcreteIterator_self : public Iterator_self
// {
// public:
//     ConcreteIterator_self(ConcreteAggregate_self *aggregate) : aggregate(aggregate), current(0) {}
//     std::string *first_self() override;
//     std::string *next_self() override;
//     bool isDone_self() override;
//     std::string *currentItem_self() override;

// private:
//     ConcreteAggregate_self *aggregate;
//     int current;
// };
// // 具体聚集类
// class ConcreteAggregate_self : public Aggregate_self
// {
// public:
//     ConcreteAggregate_self() : items(new std::list<std::string>()) {}

//     Iterator_self *CreateIterator_self() override;
//     int getCount();
//     std::string *getThis(int index);
//     void setThis(int index, std::string *value);
// private:
//     std::list<std::string> *items;
// };


// void test_iterator();
