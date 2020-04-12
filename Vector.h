/*
 * Vector.h
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
using namespace std;

class Vector {
public:
	Vector(int dim);
	Vector(int dim , double*& coord);
	Vector(const Vector* v);
	double average() const;
	void printVector() const; //print the vector
	void destroy(); // free the memory

	const double& getCoordinate(int i) const {
		return coordinates[i];
	}

	const int& getDimantion() const {
		return dimantion;
	}

	void setCoordinate(int i , double d){
		coordinates[i] = d;
	}

private:
	int dimantion;
	double* coordinates;
};



#endif /* VECTOR_H_ */
