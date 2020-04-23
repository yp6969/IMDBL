/*
 * Vector.cpp
 *
 *  Created on: 4 באפר׳ 2020
 *      Author: Pinhas
 */

#include "Vector.h"

Vector::Vector(int dim ):dimantion(dim){
	coordinates = new float[dim];
}
Vector::Vector(int dim , float*& coord ):dimantion(dim), coordinates(coord){}

/* copy constructor */
Vector::Vector(const Vector* v):dimantion(v->getDimantion()){
	coordinates = new float[dimantion];
	for(int i=0 ; i<dimantion ; i++){
		coordinates[i] = v->getCoordinate(i);
	}
}

float Vector::average() const {
	float sum = 0 ;
	for(int i=0 ; i<dimantion ; i++){
		sum += coordinates[i];
	}
	return sum/dimantion;
}

void Vector::printVector() const {
	cout<<"=[";
		for(int i=0 ; i<dimantion ; i++){
			cout<< round(100*(coordinates[i]))/100 ;
			if(i < dimantion-1)
				cout<<",";
		}
		cout<<"]"<<endl;
}
