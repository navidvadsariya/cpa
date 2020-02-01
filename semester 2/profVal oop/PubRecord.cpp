/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include  <cstring>
#include "PubRecord.h"
using namespace std;
namespace sdds {
	//sets name dynamically
	void PubRecord::name(const char* p_nameOfPublication)
	{
		setName(p_nameOfPublication);
	}
	//returns name
	const char* PubRecord::name() const
	{
		return nameOfPublication;
	}
	//default constructor
	PubRecord::PubRecord()
	{
		nameOfPublication = nullptr;
		shelfNumber = 0;
		media = SDDS_CONSOLE;
	}
	//copy constructor
	PubRecord::PubRecord(const PubRecord& p_pubRecord)
	{
		setPubRecord(p_pubRecord);
	}
	//virtual function that returns a char
	char PubRecord::recID() const
	{
		return 'p';
	}
	//sets name dynamically
	void PubRecord::setName(const char* p_nameOfPublication)
	{
		if (p_nameOfPublication != nullptr && strlen(p_nameOfPublication) != 0) {
			nameOfPublication = new char[strlen(p_nameOfPublication) + 1];
			strcpy(nameOfPublication, p_nameOfPublication);
		}
		else {
			nameOfPublication = nullptr;
		}
	}
	//destructor
	PubRecord::~PubRecord()
	{
		if (nameOfPublication != nullptr && strlen(nameOfPublication) != 0) {
			delete[] nameOfPublication;
		}
	}
	//copies all values in passed parameter
	void PubRecord::setPubRecord(const PubRecord& p_pubRecord)
	{
		setName(p_pubRecord.nameOfPublication);
		shelfNumber = p_pubRecord.shelfNumber;
		media = p_pubRecord.media;
	}
	//operator=(copies one class value to another)
	PubRecord& PubRecord::operator=(const PubRecord& p_pubRecord)
	{
		this->setPubRecord(p_pubRecord);
		return *this;
	}
	//copies value of the parameter
	void PubRecord::mediaType(int p_media)
	{
		media = p_media;
	}
	//returns value of media
	int PubRecord::mediaType()const
	{
		return media;
	}
	//returns shelfNumber
	int PubRecord::shelfNo() const
	{
		return shelfNumber;
	}
	//reads shelfNumber
	void PubRecord::readShelfNo()
	{
		bool done = false;
		do {
			cin >> shelfNumber;
			if (shelfNumber > 99 && shelfNumber < 1000) {
				done = true;
			}
		} while (!done && cout << "Invalid Shelf Number, Enter again: ");
	}
	//operator==
	bool PubRecord::operator==(char id)const
	{
		return recID() == id;
	}
	//operator==
	bool  PubRecord::operator==(const char* p_name) const
	{
		char* p;
		p = strstr(nameOfPublication, p_name);
		return p;
	}
	//operator bool(returns true if empty)
	PubRecord::operator bool() const
	{
		return (nameOfPublication != nullptr);
	}
	void PubRecord::shelfNo(int value)
	{
		shelfNumber = value;
	}
}