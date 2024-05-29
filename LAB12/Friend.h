#include"Contact.h"
#include"ContactType.h"
#include<string>
using std::string;

#ifndef FRIEND_H
#define FRIEND_H

class Friend :public Contact {
private:
	string DateOfBirth;
	string PhoneNumber;
	string Address;

public:
	Friend(string nume, string data_nastere, string numar_telefon, string adresa);

	string GetName();

	ContactType GetContactType();

	void SetName(string nume);

	string getDateOfBirth();

	void setDateOfBirth(string data_nasterii);

	string getPhoneNumber();

	void setPhoneNumber(string numar_telefon);

	string getAddress();

	void setAddress(string adresa);

};

#endif
