/*
 * Vector.cpp
 *
 *  Created on: 4 באפר׳ 2020
 *      Author: Pinhas
 */

#include "Vector.h"

Vector::Vector(int dim ):dimantion(dim){
	coordinates = new double[dim];
}
Vector::Vector(int dim , double*& coord ):dimantion(dim), coordinates(coord){}

Vector::Vector(const Vector* v):dimantion(v->getDimantion()){
	coordinates = new double[dimantion];
	for(int i=0 ; i<dimantion ; i++){
		coordinates[i] = v->getCoordinate(i);
	}
}

double Vector::average() const {
	double sum = 0 ;
	for(int i=0 ; i<dimantion ; i++){
		sum += coordinates[i];
	}
	return sum/dimantion;
}

void Vector::printVector() const {
	cout<<"= [";
		for(int i=0 ; i<dimantion ; i++){
			cout<< setprecision(2) <<coordinates[i];
			if(i < dimantion-1)
				cout<<",";
		}
		cout<<"]"<<endl;
}

void Vector::destroy() {
	delete[] coordinates;
}
