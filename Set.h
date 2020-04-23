/*
 * Set.h
 *
 * represent the data structure that store the movies
 *
 *  Created on: 6 באפר׳ 2020
 *      Author: Pinhas
 */

#ifndef SET_H_
#define SET_H_
#include <sstream>
#include "MovieRate.h"


class Set {
public:
	Set(int max_size , int dim);
	~Set();
	bool getInput(int dimantion ); // get input of the
	void add(int dim, string& name, float*& coord); //add element to the set
	int isExist(const string &name) const;
	MovieRate* searchByName() const; // search movie by name return NULL if not found
	bool isEmpty() const; //check if the set is empty
	bool isFull() const;
	void printSet() const; //print all the set

	/* handle the information of the vectors */
	void summery(); // print the summery of the movie set
	Vector* statistics(int dimantion) const; // return a vector represent avereg
	void covariance(int dimantion) const; // print the covariance matrix

	/* getters */
	int getDimantion() const {
		return (*elem)->getDimantion();
	}

	const MovieRate* getElem(int i) const {
		return elem[i];
	}

	int getSetSize() const {
		return set_size;
	}

private:
	MovieRate** elem; //array of elements
	int set_size;
	int max_size; // max set size

};

#endif /* SET_H_ */
