#include<string>
#include "ContactType.h"
#include "Contact.h"
using std::string;

#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

class Acquaintance : public Contact {

public:
	string phoneNumber;

	Acquaintance(string nume, string numar_telefon);

	string GetName();

	ContactType GetContactType();

	void SetName(string nume);

	string getPhoneNumber();

	void setPhoneNumber(string numar_telefon);
};

#endif
