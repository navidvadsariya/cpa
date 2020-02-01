/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#include <iostream>
#include "Magazine.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	//default constructor
	Magazine::Magazine() :PubRecord()
	{
		volume = 0;
		issueNumber = 0;
	}
	//copy constructor
	Magazine::Magazine(const Magazine& m_magazine) : PubRecord(m_magazine)
	{
		volume = m_magazine.volume;
		issueNumber = m_magazine.issueNumber;
	}
	//returns ID (M)
	char Magazine::recID()const
	{
		 return 'M'; 
	}
	//checks in Magazines
	void Magazine::checkIn()
	{
		cout << "Magazines cannot be checked in or out!"<<endl;
	}
	//check Magazines out
	void Magazine::checkOut()
	{
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	//reads Magazines values
	istream& Magazine::read(istream& is)
	{
		if (mediaType() == SDDS_CONSOLE) {
			char name[40];
			cout << "Magazine Name: ";
			input(name, 40, "Magazine name too long, Enter again: ");
			setName(name);

			int m_volume = 0;
			cout << "Volume: ";
			input(m_volume,1,99,"Invalid Volume number, Enter again: ");
			volume = m_volume;

			int m_issue = 0;
			cout << "Issue: ";
			input(m_issue, 1, 99, "Invalid Issue number, Enter again: ");
			issueNumber = m_issue;

			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			char name[41];
			int m_volume = 0;
			int m_issue = 0;
			int m_shelfNo = 0;
			char tab = '\t';

			is.getline(name, 40, tab);
			is >> m_volume;
			is >> m_issue;
			is >> m_shelfNo;
			is.ignore();	// ignore newline char at end of each line
			setName(name);
			volume = m_volume;
			issueNumber = m_issue;
			shelfNo(m_shelfNo);	
		}
		return is;
	}
	//displays Magazines
	ostream& Magazine::write(ostream& os) const
	{
		if (mediaType() == SDDS_CONSOLE) {
			
			
			os.width(41);
			os.setf(ios::left);
			os.fill(' ');
			os << left<< name() << "       ";
			os.unsetf(ios::left);


			os.setf(ios::right);
			os.fill('0');
			os.width(2);
			os << volume << "(";
			os.width(2);
			os << issueNumber << ")  ";
			os.fill(' ');
			os << shelfNo();
			os.unsetf(ios::right);
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << "\t" << volume << "\t" << issueNumber << "\t" << shelfNo() << endl;
		}
		return os;
	}
}
