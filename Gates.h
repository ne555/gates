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

class BothTrue /*aka And*/ : public Gates
{
	public:
	BothTrue (Input a, Input b); // a binary gate, it has two inputs
	State out () const override
	{
		return a->number () == State::On // number() seems to be a bad name
		       and b->number () == State::On;
	}

	private:
	Input a, b; // it needs to store those inputs to be able to operate on them later
};

BothTrue::BothTrue (Input a, Input b)
: // constructor
  a (a), // initialization list
  b (b)
{
}


// another subclass
class Anyone /*aka Or*/ : public Gates
{
	public:
	Anyone (Input a, Input b); // again, a binary gate
	State out () const override
	{
		return a->number () == State::On or b->number () == State::On;
	}

	private:
	Input a, b;
}

// yet another one
class Opposite /*aka Not*/ : public Gates
{
	public:
	Opposite (Input a); // unary gate
	State out () const override
	{
		return a->number () == State::Off;
	}

	private:
	Input a;
}

#if 0
//one more
class JustOne /*aka Xor*/: public Gates{
public:
	JustOne(Input a, Input b):
	//just pseudo, you'll need std::make_shared
		result(
			Input(
				BothTrue( //~AB
					Input(Opposite(a)),
					b
				),
			),
			Input(
				BothTrue( //A~B
					a,
					Input(Opposite(b)
				)
			)
		)
	{}

	State out() const override{
		return result->out();
	}

private:
	Anyone result; //would implement ~AB + A~B
}
#endif
