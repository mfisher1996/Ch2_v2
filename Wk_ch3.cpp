// Implementation file for Wk_ch3.hpp classes and methods.

#include "Wk_ch3.hpp"
#include <fstream>

template <class elemType>
void arrayListType<elemType>::print() const{
    for(int i = 0; i < length; i++ )
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem){
    if(location < 0 || location > maxSize)
        std::cerr << "The position of the item to be inserted is \nout of range" <<std::endl;
    else
        if(length>= maxSize)
            std::cerr << "Cannot insert in a full list" << std::endl;
        else{
            for (int i = length; i > location; i--)
                list[i] = list[i-1];
            list[location] = insertItem;
            length++;
        }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem){
    if (length  >= maxSize)
        std::cerr << "Cannot insert into full list" << std::endl;
    else{
        list[length] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location, elemType& retItem){
    if (location < 0 || location >= length)
        std::cerr << "The position of the item to be inserted is \nout of range" <<std::endl;
    else{
        if (length!= location)             // If the location is the end of the list the element will be
            list[location] = list[length]; // removed when the length is deincremented. Else replace the
        length--;                          // current loction with element at length and deincrement.
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType & retItem) const{
    if (location < 0 || location >= length)
        std::cerr << "The position of the item to be inserted is \nout of range" <<std::endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem){
    if (location < 0 || location >= length)
        std::cerr << "The position of the item to be inserted is \nout of range" <<std::endl;
    else
        list[location] = repItem;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size){
    if (size<0){
        std::cerr << "The array size must be positive. Creating \nan array of size 100.";
        maxSize = 100;
    }
    else
        maxSize = size;
    length = 0;
    
    list = new elemType[maxSize];
    
}

template <class elemType>
arrayListType<elemType>::~arrayListType(){
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
     //terminate if unable to allocate
    //memory space
    for (int j = 0; j < length; j++) 
    list [j] = otherList.list[j];
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length; loc++)
    if (list[loc] == item)
    {
        found = true;
        break;
    }
    if (found)
        return loc;
    else
        return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    if (length == 0) //list is empty
    list[length++] = insertItem; //insert the item and
    //increment the length
    else if (length == maxSize)
        std::cerr << "Cannot insert in a full list." << std::endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1) //the item to be inserted
        //does not exist in the list
        list[length++] = insertItem;
        else
            std::cerr << "the item to be inserted is already in the \nlist. No duplicates are allowed." << std::endl;
    }
}

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    if (length == 0)
        std::cerr << "Cannot delete from an empty list." << std::endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
        removeAt(loc);
        else
            std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}





// Date type: defined to be used in quesiton 9

dateType::dateType(){
    dYear= 2001;
    dMonth = 1;
    dDay = 1;
}
bool dateType::isLeapYear(){
    if(dYear%4==0)
    return 1;
    else
    return 0;
}
void dateType::setYear(int year){
    if(year <= 0 || year > 2999)
    std::cout << year << " is not a valid year.\n";
    else
    dYear = year;
}

void dateType::setMonth(int month){
    if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
    }
    else
    dMonth = month;
}

void dateType::setDay(int day){
    if(day <= 0)
    std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[dMonth-1] && !isLeapYear())
    std::cout << "There are not " << day << " days in month " << dMonth << ".\n";
    else if (isLeapYear() && dMonth == 2 && day > 29)
    std::cout << "There are only 29 days in month " << dMonth << " this year.\n";
    else
    dDay = day;
}
void dateType::setDate(int month, int day, int year){
    if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
    }
    else
    dMonth = month;
    if(year <= 0 || year > 2999)
    std::cout << year << " is not a valid year.\n";
    else
    dYear = year;
    if(day <= 0)
    std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[month-1] && !isLeapYear())
    std::cout << "There are not " << day << " days in month " << month << ".\n";
    else if (isLeapYear() && month == 2 && day > 29)
    std::cout << "There are only 29 days in month " << month << " this year.\n";
    else
    dDay = day;
    
    
}

dateType::dateType(int month, int day, int year){
    if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
    }
    else
    dMonth = month;
    
    if(year <= 0 || year > 2999)
    std::cout << year << " is not a valid year.\n";
    else
    dYear = year;
    
    if(day <= 0)
    std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[month-1] && !isLeapYear())
    std::cout << "There are not " << day << " days in month " << month << ".\n";
    else if (isLeapYear() && month == 2 && day > 29)
    std::cout << "There are only 29 days in month " << month << " this year.\n";
    else
    dDay = day;
    
    
}

int dateType::daysInMonth(){
    if (!isLeapYear())
    return monthDay[dMonth - 1];
    else if(dMonth == 2)
    return 29;
    else
    return monthDay[dMonth - 1];
}
int dateType::daysInMonth(int i){
    if (!isLeapYear())
    return monthDay[i];
    else if(i == 1)
    return 29;
    else
    return monthDay[dMonth - 1];
}
int dateType::daysPassed(){
    int sum = 0;
    for(int i = 0; i < dMonth-1; i++)
    sum = sum + daysInMonth(i);
    sum = sum + dDay;
    return sum;
}

int dateType::daysRemaining(){
    if(isLeapYear())
    return 365 - daysPassed();
    else
    return 364 - daysPassed();
}
void dateType::operator +(int days){
    int sum = dDay + days;
    while(sum > daysInMonth()){
        sum = sum - daysInMonth();
        if(dMonth!=12)
        dMonth++;
        else{
            dMonth = 1;
            dYear++;
        }
        
    }
    dDay = sum;
}
bool dateType::operator >(dateType date){
    if(date.getYear()<=dYear){
        if(date.getMonth() < dMonth)
                return true;
        else if(date.getMonth()==dMonth)
            if(date.getDay() <dDay)
                return true;
    }
    return false;
}
bool dateType::operator <(dateType date){
    if(date.getYear()>=dYear){
        if(date.getMonth() > dMonth)
            return true;
        else if(date.getMonth()==dMonth)
            if(date.getDay() > dDay)
                return true;
    }
    return false;
}
void dateType::printDate() const {
    std::cout << months[dMonth-1] <<" " << dDay <<", " <<dYear <<std::endl;
}

//*************QUESTION 9 ANSERS********************

//i.

/*
 example.txt should be formatted:
    'first name\n
    last name\n
    phone#\n
    relation in int\n
    StreetAdd\n
    City\n
    state\n
    Zipcode\n
    Birthmonth\n
    birthday\n
    birthyear\n
    nextpersonFirstName\n'
 
 */

void addressBookType::loadBook(std::string name){
    std::ifstream disk;
    disk.open(name);
    std::string input;
    int in;
    addressType * add;      // These two pointers are not entirerly neccisary but are used to store the memory location
    dateType * birth;       // of the dateType and addressType data members in extPearsonType.
    
    do{
        if(disk.eof())break;
        length++;
        disk >> input;
        if(disk.eof())break;
        list[length].setFirst(input);
        input = "";
        disk >> input;
        list[length].setLast(input);
        disk >> in;
        list[length].setNumber(in);
        disk >> in;
        list[length].setRelate(in);
        input = "";
        disk >> input;
        add = &list[length].getAdd();
        add->setStreet(input);
        input = "";
        disk >> input;
        add->setCity(input);
        input = "";
        disk >> input;
        add->setState(input);
        disk >> in;
        add->setZip(in);
        birth = &list[length].getBirt();
        disk >> in;
        birth->setMonth(in);
        disk >> in;
        birth->setDay(in);
        disk >> in;
        birth->setYear(in);
    }while(!disk.eof());
}

// ii.
extPersonType addressBookType::search(std::string lastN){       // returns the first person type that matches the last name given.
    for(int i=0;i<length;i++)
        if(list[i].getLastName()==lastN)
            return list[i];
    std::cerr << "Last name not found in list.\nReturning blank personType\n";
    extPersonType per;
    return per;
}

// iv.
void addressBookType::print(int month){
    std::cout << "The contacts you have born in month " << month << " are:\n";
    for(int i=0;i<length;i++)
        if(list[i].getBirt().getMonth()==month){
            std::cout << list[i].getFirstName() << " " << list[i].getLastName() << ".\n";
    }
}

void addressBookType::print(dateType date1, dateType date2){
    
    for(int i =0;i<length;i++){
        if (list[i].getBirt() > date1 && list[i].getBirt() < date2)
        std::cout << list[i].getFirstName() <<" "<<list[i].getLastName()<<"\n";
        
    }
}
// v.
void addressBookType::print(std::string relation){
    std::cout <<"All contacts with relationship: "<<relation <<" are as follows:\n";
    for (int i=0;i<length;i++)
        if(list[i].getRelate()==relation)
            std::cout << list[i].getFirstName() <<" "<< list[i].getLastName()<<"\n";
}

// vi.
void addressBookType::print(std::string name1, std::string name2){
    std::cout << "Peole in your contacts with a name after " << name1 << " and before " << name2 <<":\n";
    for(int i=0;i<length;i++)
    if(list[i].getLastName()>name1&&list[i].getLastName()<name2)
        std::cout << list[i].getFirstName() <<" "<<list[i].getLastName()<<"\n";
}

// Implementation for safeArray methods that coudn't be declared inline.

safeArray::safeArray(int begin, int finish){
    start = begin;
    end = finish;
    length = 0;
    while(begin<finish)
    {
        length++;
        begin++;
    }
    list = new int[length];
    
}

int safeArray::check(int loc){
    if(loc < start||loc > end){
        std::cerr << "The number "<< loc <<" is outside of the bounds of this array.\nReturning 0.\n";
        return 0;
    }else if(loc == end){
        std::cerr << "The number "<< loc <<" is at the end of this array.\nReturning 0.\n";
        return 0;
    }
    else{
        for(int i=0;i<length;i++)
            if(i==loc-start)
                return i;
    }
    std::cerr << "There was some problem.\n";
    return 0;
}

void safeArray::set(int loc, int x){
    int i = check(loc);
    list[i]=x;
}

int safeArray::get(int loc){
    int i=check(loc);
    return list[i];
}

void safeArray::print(){
    std::cout << "The current list:\n";
    for(int i=0;i<length;i++)
        std::cout << list[i] << " ";
    std::cout << "\n";
}

