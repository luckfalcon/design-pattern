 #include"iterator_self.h"
// #include<iostream>
// using namespace std;
// std::string *ConcreteIterator_self::first_self()
// {
//     return &(*aggregate)[0];
// }

// std::string *ConcreteIterator_self::next_self()
// {
//     std::string *ret = nullptr;
//     current++;
//     if(current<aggregate.count())
//     {
//         ret = &(*agrregate)[current];
//     }
//     return ret;
// }

// bool ConcreteIterator_self::isDone_self()
// {
//     return current >= aggregate.count() ? true : false;
// }

// std::string *ConcreteIterator_self::currentItem_self()
// {
//     return  &(*agrregate)[current];
// }

// Iterator_self *ConcreteAggregate_self::CreateIterator_self()
// {
//     return new ConcreteIterator_self(this);
// }

// int ConcreteAggregate_self::getCount()
// {
//     return items->count();
// }

// std::string *ConcreteAggregate_self::getThis(int index)
// {
//     return &(*items)[index];
// }

// void ConcreteAggregate_self::setThis(int index, std::string *value)
// {
//     items->insert(index, *value);
// }

// void test_iterator()
// {
//     ConcreteAggregate_self *a = new ConcreteAggregate_self();
//     (*a)[0]="大鸟";
//     (*a)[1]="小菜";
//     (*a)[2]="行李";
//     (*a)[3]="老外";
//     (*a)[4]="公交内部员工";
//     (*a)[5]="小偷";
//     Iterator_self *i = new ConcreteIterator_self(a);
//     object *item = i->first_self();
//     while(!i->isDone_self())
//     {
//         cout<<i->currentItem_self()
//         i->next_self();
//     }
// }
