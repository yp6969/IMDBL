/*
 * MovieRate.h
 *
 * implement a movie rating
 * holds vector of rating
 *
 *  Created on: 4 באפר׳ 2020
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
	void print() const;
	double average() const;
	void destroy();

	/* getters */
	int getDimantion() const {
		return rate->getDimantion();
	}

	const double& getRating(int i) const{
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
