#include"reference-pointer.h"
#include<iostream>
using namespace std;

void Reference::print_n()
{
    cout << "this reference's n = " << n << endl;
}

void Pointer::print_n()
{
    cout << "this pointer's n = " << n << endl;
}

void test_point_reference()
{
    Base *bp = new Pointer(2);
    bp->print_n();
    Reference r(3);
    Base &br = r;
    br.print_n();
}
