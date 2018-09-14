// Headder file for Wk_ch3 program (program function not yet determined.)

#include <iostream>

template <class elemType>

class arrayListType{
public:
	const arrayListType<elemType>& operator= (const arrayListType<elemType>& );
    bool isEmpty() const{return (length == 0);};
    bool isFull() const{return (length == maxSize);};
    int listSize() const{return length;};
    int maxListSize() const{return maxSize;};
	void print() const;
    bool isItemAtEqual(int location, const elemType & item) const{return (list[location] == item);};
	void insertAt(int location, const elemType& insertItem);
	void insertEnd(const elemType& insertItem);
	void removeAt(int location, elemType& retItem);
	void retrieveAt(int location, elemType& retItem) const;
	void replaceAt(int location, const elemType& repItem);
    void clearList(){length = 0;};
	int seqSearch (const elemType& item) const;
	void insert(const elemType& insertItem);
	void remove(const elemType& removeItem);
	arrayListType(int size = 100);
	arrayListType(const arrayListType<elemType>& otherList);
	~arrayListType();
protected:
	elemType *list;
	int length;
	int maxSize;
};

class dateType{
public:
    void setDate(int month, int day, int year);
    int getDay() const{return dDay;};
    int getMonth() const{return dMonth;};
    std::string getMonthName() const{return months[dMonth-1];};
    int getYear() const{return dYear;}
    void setDay(int day);
    void setYear(int year);
    void setMonth(int month);
    void printDate() const;
    dateType(int month, int day, int year);
    dateType();
    bool isLeapYear();
    int daysInMonth();
    int daysPassed();
    int daysRemaining();
    void operator+(int days);
    int daysInMonth(int i);
private:
    int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
    int dMonth;
    int dDay;
    int dYear;
};

class extPersonType{
public:
    void print() const{std::cout << firstName <<" "<< midName <<" "<< lastName  << "\n";};
    void setName(std::string first, std::string last){firstName = first; lastName = last;};
    void setFirst(std::string first){firstName = first;};
    void setMid(std::string mid){midName = mid;};
    void setLast(std::string last){lastName = last;};
    bool checkFirst(std::string first){if(firstName == first)return 1; else return 0;};
    bool checkLast(std::string last){if(lastName == last)return 1; else return 0;};
    std::string getFirstName() const{return firstName;};
    std::string getLastName() const{return lastName;};
    extPersonType();
    extPersonType(std::string first, std::string last){firstName = first; lastName = last;};
private:
    std::string firstName;
    std::string lastName;
    std::string midName;
    std::string relation[3] = {"Family","Friend", "Business assosciate"};
    int relate;
};

class addressType{
public:
    addressType(){street="";city="";state="";zipCode=0;};
    addressType(std::string s, std::string c, std::string st, int zip){street=s;city=c;state=st;if(zip >=10000||zip<100000)zipCode=zip;else {std::cerr << "Invalid Zipcode.\nZipcode is set to '11111'\n";zipCode=11111;}};
    void setStreet(std::string s){street = s;};
    void setCity(std::string c){city = c;};
    void setState(std::string st){state = st;};
    void setZip(int zip){if(zip >=10000||zip<100000)zipCode=zip;else {std::cerr << "Invalid Zipcode.\nZipcode is set to '11111'\n";zipCode=11111;}};
    std::string getStreet(){return street;};
    std::string getCity(){return city;};
    std::string getState(){return state;};
    int getZip(){return zipCode;};
    void print(){std::cout <<"Address: "<<street<<"\n"<<city<<" "<<state<<".\n";};
    
private:
    std::string street;
    std::string city;
    std::string state;
    int zipCode;
};
