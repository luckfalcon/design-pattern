#include "templatemethod.h"
#include<iostream>
using namespace std;
void TemplateMethod::operation1()
{
    cout << "do operation 1" << endl;
}

void TemplateMethod::operation3()
{
    cout << "do operation 3" << endl;
}

void TemplateMethod::templateMethod()
{
    operation1();
    if (operation2())
        operation3();
    operation4();
}

bool ConcreteTemplateMethod::operation2()
{
    return true;
}

void ConcreteTemplateMethod::operation4()
{
    cout << "do operation 4" << endl;
}

void test_templateMethod()
{
    TemplateMethod *tm = new ConcreteTemplateMethod();
    tm->templateMethod();
}
