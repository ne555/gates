#include "Gates.h"
#include "Input.h"
#include <memory>
#include <iostream>

int main ()
{
	InputPoint
		in1 = std::make_shared<Input> (true),
		in2 = std::make_shared<Input> (true);
	GatePoint
		g = std::make_shared<BothTrue> (in1, in2);

	std::cout << g->out () << '\n';
}
