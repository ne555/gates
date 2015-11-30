#include <iostream>
enum class State
{
	On,
	Off,
	Unknown,
};

std::ostream& operator<<(std::ostream&, State);
