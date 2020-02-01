/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#include <iostream>
#include "Book.h"
#include "Utils.h"


using namespace std;
namespace sdds {
	//default constructor
	Book::Book() : PubRecord()
	{
		isbn = 0;
		membershipId = 0;
	}
	//copy constructor
	Book::Book(const Book& book):PubRecord(book)
	{
		isbn = book.isbn;
		membershipId = 0;
		date = book.date;
	}
	//assignment operator
	Book& Book::operator=(const Book& book) {
		if (this != &book) {
			name(book.name());
			shelfNo(book.shelfNo());
			mediaType(book.mediaType());
			isbn = book.isbn;
			membershipId = 0;
			date = book.date;
		}
		return *this;
	}
	//returns ID (B)
	char Book::recID() const
	{
		return 'B';
	}
	//returns member ID
	int Book::memberId() const
	{
		return membershipId;
	}
	//checks in
	void Book::checkIn()
	{
		membershipId = 0;
		write();
		cout  << " checked in!" << endl;
	}
	//check book out
	void Book::checkOut()
	{
		bool keepgoing = true;
		cout << "Enter Member id: ";
		input(membershipId, 10000, 99999, "Invalid Member ID, Enter again: ");
		while (keepgoing) {
			cout << "Enter return date: ";
			cin >> date;
			if (date) {
				Date todayDate;
				if(todayDate <= date){
					if ((date - todayDate) <= 30) {
						keepgoing = false;
					}
					else {
						cout << "The return date must be earlier than 30 days away from today." << endl;
					}
				}
				else
				{
					cout << "Please enter a future date." << endl;
				}
			}
			else
			{
				cout << "Failed, invalid Year, month or day." << endl;
			}
		}
	}
	//reads input
	istream& Book::read(istream& is)
	{
		if (mediaType() == SDDS_CONSOLE) {
			membershipId = 0;
			char b_name[41];
			cout << "Book Name: ";
			input(b_name, 40, "Book name too long, Enter again: ");
			setName(b_name);

			long long int b_isbn = 0;
			bool keepGoing = true;
			cout << "ISBN: ";
			
			while (keepGoing){
				is >> b_isbn;
				if (b_isbn >999999999999 && b_isbn < 10000000000000) {
					keepGoing = false;
				}
				else
				{
					cout << "Invalid ISBN, Enter again: ";
				}
			} 
			isbn = b_isbn;

			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			char b_name[41];
			long long int b_isbn = 0;
			int b_memberId = 0;
			int b_shelfNo = 0;
			char tab = '\t';

			is.getline(b_name, 40, tab);
			is >> b_isbn;
			is >> b_shelfNo;
			is >> b_memberId;
			if (b_memberId != 0) {
				is.ignore();
				is >> date;
			}
			is.ignore();	// ignore newline char at end of each line

			setName(b_name);
			isbn = b_isbn;
			membershipId = b_memberId;
			shelfNo(b_shelfNo);
		}
		return is;
	}
	//displays book
	ostream& Book::write(ostream& os) const
	{
		if (mediaType() == SDDS_CONSOLE) {
			os.setf(ios::left);
			os.width(41);
			os.fill(' ');
			os <<left<< name();
			os.unsetf(ios::left);
			os.setf(ios::right);
			os << isbn<<"  "<<shelfNo();
			os.unsetf(ios::right);
			if (membershipId != 0) {
				os << " " << membershipId << "   ";
				os << date;
			}
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << "\t" << isbn << "\t" << shelfNo() << "\t" << membershipId;
			if (membershipId != 0) {
				os << "\t";
				os << date;
			}
			
			os << endl;
		}
		return os;
	}
}