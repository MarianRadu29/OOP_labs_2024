#include"AddressBook.h"
#include "Contact.h"
#include "ContactType.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include "Friend.h"
#include <iostream>
#include<string>
using std::string;
using std::vector;
using std::cout;

int main()
{   
    
    Friend* m = new Friend("Mariusik", "29-02-2004", "0723123123", "Liesti");
    Friend* c = new Friend("Cezarik", "01-10-2004", "0724375320", "Matca");
    Acquaintance* b = new Acquaintance("Bordei", "0712371234");
    Friend* ma = new Friend("Matei", "15-09-2004", "075673420", "Botosani");
    Colleague* co = new Colleague("Marian", "0723363220", "Software Developer", "Iasi");
    AddressBook book;
    book.AddContact(m);
    book.AddContact(c);
    book.AddContact(b);
    book.AddContact(ma);
    book.AddContact(co);
    vector<Friend*> f = book.ListFriends();
    for (Friend* i : f)
        cout << i->GetName() << ' ' << i->getDateOfBirth() << '\n';
}