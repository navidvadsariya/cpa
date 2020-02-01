#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	// default constructor
	MenuItem::MenuItem()
	{
		description = nullptr;
	}
	// one argument constructor
	MenuItem::MenuItem(const char* desc)
	{
		setDesc(desc);
	}
	// virtual destructor
	MenuItem::~MenuItem()
	{
			delete[] description;
	}
	// overload operator bool
	MenuItem::operator bool()
	{
		return (description != nullptr);
	}
	// overload operator const char*
	MenuItem::operator const char* ()
	{
		return description;
	}
	// allocates memory for description
	void MenuItem::setDesc(const char* desc)
	{
		if (desc != nullptr) {
			description = new char[strlen(desc) + 1];
			strcpy(description, desc);
		}
		else {
			description = nullptr;
		}
	}
	// displays description and returns standard output
	ostream& MenuItem::display(ostream& os)const
	{
		if (description != nullptr) {
			os << description;
		}
		return os;
	}

	// default constructor
	Menu::Menu()
	{
		setEmpty();
	}
	// one argument constructor
	Menu::Menu(const char* m_title)
	{
		title.setDesc(m_title);
		setEmpty();
	}
	Menu::~Menu()
	{
		if (noOfItems > 0)
		{
			for (unsigned int i = 0; i < noOfItems; i++)
			{
				delete menuItem[i];
			}
		}
	}
	// sets Menu object to safe empty state
	void Menu::setEmpty()
	{
		noOfItems = 0;
	}
	// displays the title of the menu
	ostream& Menu::displayTitle(ostream& os)const
	{
		if (title.description != nullptr) {
			title.display(os);
		}
		return os;
	}
	// displays the menu item(s)
	ostream& Menu::displayEntireMenu(ostream& os)const
	{
		if (title.description != nullptr && strlen(title.description) != 0) {
			displayTitle(os);
			os << ":" << endl;
		}
		for (unsigned int i = 0;i < MAX_MENU_ITEMS && menuItem[i]->description != nullptr;i++) {
			os << " " << (i + 1) << "- ";
			menuItem[i]->display(os);
			os << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;
	}
	// overloaded insertion operator
	Menu& Menu::operator<<(const char* item)
	{
		if (noOfItems < MAX_MENU_ITEMS) {
			bool done = true;

			for (unsigned int i = 0; i < MAX_MENU_ITEMS && done; i++) {
				if (menuItem[i] == nullptr) {
					menuItem[i]->setDesc(item);
					noOfItems++;
					done = false;
				}
			}
		}
		return *this;
	}
	// returns menu selection
	int Menu::getSelection() const
	{
		unsigned int choice = 0;
		bool done = true;
		displayEntireMenu();
		while (done)
		{
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				flushKeyboard();
				cout << "Invalid Selection, try again: ";
			}
			else if (choice <= noOfItems)
			{
				done = false;
			}
			else
			{
				cout << "Invalid Selection, try again: ";
			}
		}
		cin.ignore();
		return choice;
	}
	// overloaded operator
	int Menu::operator~()const
	{
		return  getSelection();
	}
	// overloaded operator
	Menu::operator int()
	{
		return noOfItems;
	}
	// overloaded operator
	Menu::operator unsigned int()
	{
		return noOfItems;
	}
	// overloaded bool operator
	Menu::operator bool() const
	{
		return (noOfItems >= 1);
	}
	// overloaded output operator
	ostream& operator<<(ostream& os, const Menu& menu)
	{
		menu.displayTitle(os);
		return os;
	}
	// overloaded [] operator
	const char* Menu::operator[](int index) const
	{
		return menuItem[index]->description;
	}

}