/*
 * MovieRate.cpp
 *
 *  Created on: 4 באפר׳ 2020
 *      Author: Pinhas
 */

#include "MovieRate.h"

MovieRate::MovieRate():name(),rate(NULL){}
MovieRate::MovieRate(const string& name , Vector* v):name(name), rate(v){}

//MovieRate::MovieRate(MovieRate* other){
//	MovieRate(other->getName() , new Vector(other->getRate()));
//}

//MovieRate& operator=(const MovieRate& other) {
//  if (this != &other) {  // protect against invalid self-assignment
//    // 1: allocate new memory and copy the elements
//    int* new_array = new int[other.count];
//    std::copy(other.array, other.array + other.count, new_array);
//
//    // 2: deallocate old memory
//    delete[] array;
//
//    // 3: assign the new memory to the object
//    array = new_array;
//    count = other.count;
//  }
//  // by convention, always return *this
//  return *this;
//}


void MovieRate::print() const {
	cout<<name;
	rate->printVector();
}

float MovieRate::average() const {
	return rate->average();
}
