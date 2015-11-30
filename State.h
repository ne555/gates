#ifndef STATE_H
#define STATE_H
#include <iostream>
enum class State
{
	On,
	Off,
	Unknown,
};

inline std::ostream& operator<<(std::ostream& out, State s)
{
	if (s == State::On)
		out << "On";
	else if (s == State::Off)
		out << "Off";
	else
		out << "Unknown";
}
inline State make_state (bool b)
{
	if (b) return State::On;
	return State::Off;
}
#endif
