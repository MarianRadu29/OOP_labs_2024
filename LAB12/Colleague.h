#include "Contact.h"
#include "ContactType.h"
#include<string>
using std::string;
#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class Colleague : public Contact {

private:
	string phone_number;
	string job_title;
	string address;

public:
	Colleague(string nume, string numar_telefon, string nume_job, string adresa);

	string GetName();

	ContactType GetContactType();

	string GetPhoneNumber();

	string GetJobTitle();

	string GetAddress();

	void SetName(string nume);

	void SetPhoneNumber(string numar_telefon);

	void SetJobTitle(string nume_job);

	void SetAddress(string adresa);
};

#endif
