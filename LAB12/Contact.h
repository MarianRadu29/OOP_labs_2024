#include<string>
#include "ContactType.h"
using std::string;

#ifndef CONTACT_H
#define CONTACT_H

class Contact {

protected:
	string name;

public:
	virtual string GetName() = 0;

	virtual ContactType GetContactType() = 0;
};

#endif
