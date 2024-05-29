#include "Acquaintance.h"

Acquaintance::Acquaintance(string nume, string numar_telefon): phoneNumber(numar_telefon)
{
	name = nume;
	// TODO - implement Acquaintance::Acquaintance
	//throw "Not yet implemented";
}

string Acquaintance::GetName() {
	return name;
	// TODO - implement Acquaintance::GetName
	//throw "Not yet implemented";
}

ContactType Acquaintance::GetContactType() {
	return ContactType::ACQUAINTANCE;
	// TODO - implement Acquaintance::GetContactType
	//throw "Not yet implemented";
}

void Acquaintance::SetName(string nume) {
	name = nume;
	// TODO - implement Acquaintance::SetName
	//throw "Not yet implemented";
}

string Acquaintance::getPhoneNumber() {
	return this->phoneNumber;
}

void Acquaintance::setPhoneNumber(string numar_telefon) {
	this->phoneNumber = numar_telefon;
}
