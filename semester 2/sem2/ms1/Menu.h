#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include<iostream>

namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu;
	
	class MenuItem
	{
        char* description;
		friend Menu;
		// default constructor
		MenuItem();
		// overloaded constructor
		MenuItem(const char* desc);
		// virtual destructor
		virtual ~MenuItem();
		// overload operator bool
		operator bool();
		// overload operator const char*
		operator const char* ();
		// displays description and returns standard output
		std::ostream& display(std::ostream& os = std::cout)const;
		// allocates memory for description
		void setDesc(const char* desc);
		//Prevents copying and assigning to another class
		MenuItem(const MenuItem& temp_obj) = delete;
		//Prevents copying and assigning to another class
		MenuItem& operator=(const MenuItem& temp_obj) = delete;
	};
	class Menu
	{
		MenuItem title;
		MenuItem menuItem[MAX_MENU_ITEMS];
		unsigned int noOfItems;

	public:
		// default constructor
		Menu();
		// destructor
		~Menu();
		// overloaded constructor
		Menu(const char* m_title);
		//Prevents copying and assigning to another class
		Menu(const Menu& temp_obj) = delete;
		//Prevents copying and assigning to another class
		Menu& operator=(const Menu& temp_obj) = delete;
		// sets Menu object to safe empty state
		void setEmpty();
		// displays the title of the menu
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		// displays the menu item(s)
		std::ostream& displayEntireMenu(std::ostream& os = std::cout)const;
		// overloaded insertion operator
		Menu& operator<<(const char* item);
		// overloaded operator
		int operator~();
		// overloaded operator
		operator int();
		// overloaded operator
		operator unsigned int();
		// overloaded bool operator
		operator bool();
		// overloaded [] operator
		const char* operator[](int index) const;
		// returns menu selection
		int getSelection();
	};
	// overloaded output operator
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif