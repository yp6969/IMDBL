/*
 * Vector.h
 *
 * represent a generic vector
 *
 *  Created on: 4 באפר׳ 2020
 *      Author:  Yair Pinhas
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

class Vector {
public:
	Vector(int dim);
	Vector(int dim , float*& coord);
	Vector(const Vector* v);
	~Vector(){
	    delete[] coordinates;
	}
	float average() const; // return the average
	void printVector() const; //print the vector

	const float& getCoordinate(int i) const {
		return coordinates[i];
	}

	const int& getDimantion() const {
		return dimantion;
	}

	void setCoordinate(int i , float d){
		coordinates[i] = d;
	}

private:
	int dimantion;
	float* coordinates;
};



#endif /* VECTOR_H_ */
