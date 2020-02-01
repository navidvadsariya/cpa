/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__

#include "ReadWriteable.h"
#include "Date.h"
#include "Menu.h"

namespace sdds {
	
	const int SDDS_CONSOLE = 1;
	const int SDDS_FILE = 2;

	class PubRecord : public ReadWriteable 
	{
		char* nameOfPublication;
		int shelfNumber;
		int media;
	protected:
		//sets name dynamically
		void name(const char* p_nameOfPublication);
		//returns name
		const char* name() const;

		void shelfNo(int value);
	public:
		//default constructor
		PubRecord();
		//copy constructor
		PubRecord(const PubRecord& p_pubRecord);
		//destructor
		virtual ~PubRecord();

		//virtual function that returns a char
		virtual char recID() const;
		//sets name dynamically
		void setName(const char* p_nameOfPublication);
		//copies all values in passed parameter
		void setPubRecord(const PubRecord& p_pubRecord);
		//copies value of the parameter
		void mediaType(int p_media);
		//returns value of media
		int mediaType() const;
		//returns shelfNumber
		int shelfNo() const;
		//reads shelfNumber
		void readShelfNo();
		//operator=(copies one class value to another)
		PubRecord& operator=(const PubRecord& p_pubRecord);
		//operator==
		bool operator==(char id) const;
		//operator==
		bool operator==(const char* p_name) const;
		//operator bool(returns true if empty)
		operator bool() const;

		//checks in book
		virtual void checkIn() = 0;
		//checks out book
		virtual void checkOut() = 0;		
	};
	
}
#endif // !

