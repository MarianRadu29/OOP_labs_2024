#include "Colleague.h"

Colleague::Colleague(string nume, string numar_telefon, string nume_job, string adresa) :phone_number(numar_telefon), job_title(nume_job), address(adresa)
{
	nume = name;
	// TODO - implement Colleague::Colleague
	//throw "Not yet implemented";
}

string Colleague::GetName() {
	return name;
	// TODO - implement Colleague::GetName
	//throw "Not yet implemented";
}

ContactType Colleague::GetContactType() {
	return ContactType::COLLEAGUE;
	// TODO - implement Colleague::GetContactType
	//throw "Not yet implemented";
}

string Colleague::GetPhoneNumber() {
	return phone_number;
	// TODO - implement Colleague::GetPhoneNumber
	//throw "Not yet implemented";
}

string Colleague::GetJobTitle() {
	return job_title;
	// TODO - implement Colleague::GetJobTitle
//	throw "Not yet implemented";
}

string Colleague::GetAddress() {
	return address;
	// TODO - implement Colleague::GetAddress
	//throw "Not yet implemented";
}

void Colleague::SetName(string nume) {
	name = nume;
	// TODO - implement Colleague::SetName
	//throw "Not yet implemented";
}

void Colleague::SetPhoneNumber(string numar_telefon) {
	phone_number = numar_telefon;
	// TODO - implement Colleague::SetPhoneNumber
	//throw "Not yet implemented";
}

void Colleague::SetJobTitle(string nume_job) {
	job_title = nume_job;
	// TODO - implement Colleague::SetJobTitle
	//throw "Not yet implemented";
}

void Colleague::SetAddress(string adresa) {
	address = adresa;
	// TODO - implement Colleague::SetAddress
	//	throw "Not yet implemented";
}
