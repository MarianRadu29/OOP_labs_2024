#include "AddressBook.h"

Contact* AddressBook::SearchContactByName(string name) {
	for (auto contact : Contacts)
		if (contact->GetName() == name)//in felul asta cautam primul contact din lista adaugat care are numele name
			return contact;
	return nullptr;
	// TODO - implement AddressBook::SearchContactByName
	//throw "Not yet implemented";
}

vector<Friend*> AddressBook::ListFriends() {
	vector<Friend*> result;
	for (Contact* contact : Contacts)
		if (contact->GetContactType() == ContactType::FRIEND)
			result.push_back(dynamic_cast<Friend*>(contact));
	return result;
	// TODO - implement AddressBook::ListFriends
	//throw "Not yet implemented";
}

void AddressBook::DeleteContactByName(string name) {
	for (vector<Contact*>::iterator it = Contacts.begin(); it != Contacts.end();)
		if ((*it)->GetName() == name)
			it = Contacts.erase(it);//ne returneaza iteratatorul urmator al lui "it" initial
		else
			it++;
	// TODO - implement AddressBook::DeleteContactByName
	//throw "Not yet implemented";
}

void AddressBook::AddContact(Contact* contact) {
	Contacts.push_back(contact);
	// TODO - implement AddressBook::AddContact
	//throw "Not yet implemented";
}
