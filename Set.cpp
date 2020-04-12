/*
 * Set.cpp
 *
 *  Created on: 6 באפר׳ 2020
 *      Author: Pinhas
 */

#include "Set.h"

Set::Set(int max_size , int dim):max_size(max_size),set_size(0),elem(new MovieRate*[max_size]){}




/*3 Idiots
  1.836,8.742,4.124,1.822,8.101,0.848,3.174,9.136,4.431,8.326
*/

bool Set::getInput(int dimantion ){
	if(set_size >= max_size){
		cerr<<"ERROR: MAX_MOVIES exceeded"<<endl;
		return false;
	}
	string name;
	string coordStr;
	getline(cin , name);
	if((int)name.length() > max_size) return false;
	getline(cin , coordStr);
	int cnt=0;
	for(unsigned int i=0 ; i<coordStr.length() ; i++){
		if(coordStr.at(i) == ','){
			if(i == 0 || i== coordStr.length()-1) return false;
			cnt++;
		}
		else if ( !isdigit(coordStr.at(i)) && coordStr.at(i) != '.' ){
			return false;
		}
	}
	if(cnt != dimantion-1) return false;
	double *coord = new double[dimantion];
	string temp;
	stringstream sso(coordStr);
	for(int i=0 ; i<dimantion ; i++){
		getline(sso , temp , ',');
		coord[i] = atof(temp.c_str());
	}

	add(dimantion, name, coord);

	return true;
}

void Set::add(int dim, string& name, double*& coord) {

	MovieRate* temp = new MovieRate(name , new Vector(dim , coord) );
	int inx = isExist(temp->getName());
	if(inx >= 0 && inx < max_size){  //in case of the movie is already exist
		elemDstroy(elem[inx]);
		elem[inx]= temp;
	}
	else{
		elem[set_size] = temp;
		set_size++;
	}
}

int Set::isExist(const string &name) const{
	for(int i=0 ; i<set_size ; i++){
		if(name == elem[i]->getName())
			return i;
	}
	return -1; //if not found
}

	MovieRate* Set::searchByName() const{
	char* temp = new char[MAX_NAME];
	cin>>temp;
	int index = isExist(temp);
	delete[] temp; // free waist memory
	if(index == -1){
		cerr<<"ERROR:"<<temp<<" does not exist"<<endl;
		return NULL;
	}
	return elem[index];
}

bool Set::isEmpty() const {
	return set_size == 0;
}

bool Set::isFull() const{
	return set_size >= max_size;
}

void Set::printSet() const {
	for(int i=0 ; i<set_size ; i++)
		elem[i]->print();
}

void Set::elemDstroy(MovieRate* movie){
	movie->destroy();
	delete movie;
}

void Set::setDestroy() {
	for(int i=0 ; i<set_size ; i++)
		elemDstroy(elem[i]);
}

void Set::summery(){
	for(int i=0 ; i<set_size ; i++){
		cout<<elem[i]->getName()<<", "<<elem[i]->average()<<endl;
	}
}

Vector* Set::statistics(int dimantion) const{
	Vector* avg = new Vector(dimantion);
	double sum = 0;
	for(int i=0 ; i<dimantion ; i++){
		for(int j=0 ; j<set_size ; j++){
			sum += elem[j]->getRating(i);
		}
		avg->setCoordinate(i , sum/set_size);
	}
	return avg;
}

void Set::covariance(int dimantion) const{
	double sum = 0;
	Vector* u = statistics(dimantion);
	cout<<"cov=["<<endl;
	for(int i=0 ; i<dimantion ; i++){
		for(int j=0 ; j<dimantion ; j++){
			for(int k=1 ; k<set_size ; k++){
				sum+=(elem[k]->getRating(i) - u->getCoordinate(i))*(elem[k]->getRating(j)- u->getCoordinate(j));
			}
			cout << setprecision(2) << sum;
			if(j<dimantion-1) cout<<",";
		}
		cout<<endl;
	}
	cout<<"]"<<endl;
}
