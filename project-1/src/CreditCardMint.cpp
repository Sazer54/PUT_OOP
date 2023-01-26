#include <iostream>
#include "singletons/System.h"

int main()
{
	System::instance().beginLoop();
}
