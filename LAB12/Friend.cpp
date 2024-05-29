#include "Friend.h"

Friend::Friend(string nume, string data_nastere, string numar_telefon, string adresa) : DateOfBirth(data_nastere), PhoneNumber(numar_telefon), Address(adresa)
{
	this->name = nume;
}

string Friend::GetName() {
	return name;
	// TODO - implement Friend::GetName
	//throw "Not yet implemented";
}

ContactType Friend::GetContactType() {
	return ContactType::FRIEND;
	// TODO - implement Friend::GetContactType
	//throw "Not yet implemented";
}

void Friend::SetName(string nume) {
	name = nume;
	// TODO - implement Friend::SetName
	//throw "Not yet implemented";
}

string Friend::getDateOfBirth() {
	return this->DateOfBirth;
}

void Friend::setDateOfBirth(string data_nasterii) {
	this->DateOfBirth = data_nasterii;
}

string Friend::getPhoneNumber() {
	return this->PhoneNumber;
}

void Friend::setPhoneNumber(string numar_telefon) {
	this->PhoneNumber = numar_telefon;
}

string Friend::getAddress() {
	return this->Address;
}

void Friend::setAddress(string adresa) {
	this->Address = adresa;
}
