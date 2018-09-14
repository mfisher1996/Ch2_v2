// Implementation file for Wk_ch3.hpp classes and methods.

#include "Wk_ch3.hpp"


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
    assert(list != NULL);
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
    assert(list != NULL); //terminate if unable to allocate
    //memory space
    for (int j = 0; j < length; j++) 
    list [j] = otherList.list[j];
}
