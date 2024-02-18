#include "say.h"
#include<iostream>
using namespace std;
void Say::say(const std::string &content)
{
    cout << speaker << " says: " << content << endl;
}