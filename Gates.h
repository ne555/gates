#ifndef GATES_H
#define GATES_H

#include "State.h"
#include "Input.h"

class Gates
{
	public:
	virtual State out () const = 0;
	virtual ~Gates () = default; // needed because there is a virtual member function
};
typedef std::shared_ptr<Gates> GatePoint;

class BothTrue /*aka And*/ : public Gates
{
	public:
	BothTrue (InputPoint a, InputPoint b); // a binary gate, it has two inputs
	State out () const override
	{
		if (a->number () == State::On // number() seems to be a bad name
		    and b->number () == State::On)
			return State::On;
		else
			return State::Off;
	}

	private:
	InputPoint a, b; // it needs to store those inputs to be able to operate on them later
};

inline BothTrue::BothTrue (InputPoint a, InputPoint b)
: // constructor
  a (a), // initialization list
  b (b)
{
}


// another subclass
class Anyone /*aka Or*/ : public Gates
{
	public:
	Anyone (InputPoint a, InputPoint b); // again, a binary gate
	State out () const override
	{
		return make_state(a->number () == State::On or b->number () == State::On);
	}

	private:
	InputPoint a, b;
};

// yet another one
class Opposite /*aka Not*/ : public Gates
{
	public:
	Opposite (InputPoint a); // unary gate
	State out () const override
	{
		return make_state(a->number () == State::Off);
	}

	private:
	InputPoint a;
};

#if 0
//one more
class JustOne /*aka Xor*/: public Gates{
public:
	JustOne(InputPoint a, InputPoint b):
	//just pseudo, you'll need std::make_shared
		result(
			InputPoint(
				BothTrue( //~AB
					InputPoint(Opposite(a)),
					b
				),
			),
			InputPoint(
				BothTrue( //A~B
					a,
					InputPoint(Opposite(b)
				)
			)
		)
	{}

	State out() const override{
		return result->out();
	}

private:
	Anyone result; //would implement ~AB + A~B
};
#endif
#endif
