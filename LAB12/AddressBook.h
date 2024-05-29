#include "Contact.h"
#include "ContactType.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include "Friend.h"
#include <vector>
#include <string>
using  std::vector;
using std::string;
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H



class AddressBook {

private:
	vector<Contact*> Contacts;
	
public:
	Contact* SearchContactByName(string name);

	vector<Friend*> ListFriends();

	void DeleteContactByName(string name);

	void AddContact(Contact* contact);
};

#endif
