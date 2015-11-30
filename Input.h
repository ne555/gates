#ifndef INPUT_H
#define INPUT_H

#include <memory>
#include "State.h"

class Input
{
	public:
	Input (bool number);
	Input (std::shared_ptr<Gates>& g);
	State number () const;

	private:
	std::shared_ptr<Gates> gatespriv;
	State numberpriv; //!< fixed value when no gate is present
};

typedef std::shared_ptr<Input> InputPoint;
#endif
