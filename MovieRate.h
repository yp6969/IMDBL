/*
 * MovieRate.h
 *
 * implement a movie rating
 * holds vector of rating
 *
 *  Created on: 4 ����� 2020
 *      Author: Pinhas
 */

#ifndef MOVIERATE_H_
#define MOVIERATE_H_
#include "Vector.h"
#define MAX_NAME 32


class MovieRate {
public:
	MovieRate();
	MovieRate(const string& name ,  Vector* v );
	MovieRate(MovieRate* other);
	~MovieRate(){
	    delete rate;
	}
	void print() const; // print the vector
	float average() const; // return the avereg of the coordinates

	/* getters */
	int getDimantion() const {
		return rate->getDimantion();
	}

	const float& getRating(int i) const{
		return rate->getCoordinate(i);
	}

	const string& getName() const {
		return name;
	}

	const Vector* getRate() const {
		return rate;
	}


private:
	string name;
	Vector* rate;
};

#endif /* MOVIERATE_H_ */
