#ifndef STATE_H
#define STATE_H
#include <iostream>
enum class State
{
	On,
	Off,
	Unknown,
};

std::ostream& operator<<(std::ostream&, State);
inline State make_state(bool b){
	if(b) return State::On;
	return State::Off;
}
#endif
