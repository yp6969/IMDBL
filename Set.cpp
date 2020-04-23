/*
 * Set.cpp
 *
 *  Created on: 6 באפר׳ 2020
 *      Author: Pinhas
 */

#include "Set.h"

Set::Set(int max_size , int dim):elem(new MovieRate*[max_size]),set_size(0),max_size(max_size){}
Set::~Set(){
    for(int i=0 ; i<set_size ; i++){
        delete elem[i];
    }
    delete elem;
}

/* getting the input and check it return false if invalid input
 * create an object only if the input is correct */
bool Set::getInput(int dimantion ){
	string name;
	string coordStr;
	getline(cin , name);
    if( isExist(name) == -1 ) {
        if (set_size >= max_size) {
            cerr << "ERROR: MAX_MOVIES exceeded" << endl;
            return true;
        }
    }
	if( name.size() < 1 || name.size() > MAX_NAME) return false;
	getline(cin , coordStr);
	int cnt=0;
	for(unsigned int i=0 ; i<coordStr.size() ; i++){
		if(coordStr.at(i) == ','){
		    if(i == 0 || i== coordStr.length()-1) return false;
			cnt++;
		}
		else if ( !isdigit(coordStr.at(i)) && coordStr.at(i) != '.' ){
            return false;
		}
	}
	if(cnt != dimantion-1) return false;
	float *coord = new float[dimantion];
	string temp;
	stringstream sso(coordStr);
	for(int i=0 ; i<dimantion ; i++){
		getline(sso , temp , ',');
		coord[i] = atof(temp.c_str());
	}

	add(dimantion, name, coord); // add the movie in the set


	return true;
}

/* adding the movie to the data structure */
void Set::add(int dim, string& name, float*& coord) {

	MovieRate* temp = new MovieRate(name , new Vector(dim , coord) );
	int inx = isExist(temp->getName());
	if(inx >= 0 && inx < max_size){  //in case of the movie is already exist
		delete elem[inx];
		elem[inx]= temp;
	}
	else{
		elem[set_size] = temp;
		set_size++;
	}
}

/* check if the element is exist
 * return the index or -1 if not exist*/
int Set::isExist(const string &name) const{
	for(int i=0 ; i<set_size ; i++){
		if(name == elem[i]->getName())
			return i;
	}
	return -1; //if not found
}

/* search movie by his name
 * return pointer to the movie in the set*/
MovieRate* Set::searchByName() const{
	string temp;
	getline(cin , temp);
	int index = isExist(temp);
	if(index == -1){
		cerr<<"ERROR: "<<temp<<" does not exist"<<endl;
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

void Set::summery(){
	for(int i=0 ; i<set_size ; i++){
		cout<<elem[i]->getName()<<", "<< round(100*( elem[i]->average() ))/100 <<endl;
	}
}

Vector* Set::statistics(int dimantion) const{
	Vector* avg = new Vector(dimantion);
	float sum = 0;
	for(int i=0 ; i<dimantion ; i++){
		for(int j=0 ; j<set_size ; j++){
			sum += elem[j]->getRating(i);
		}
		avg->setCoordinate( i , sum/set_size);
		sum = 0;
	}
	return avg;
}

void Set::covariance(int dimantion) const{
	float sum = 0;
	Vector* u = statistics(dimantion);
	cout<<"cov=["<<endl;
	for(int i=0 ; i<dimantion ; i++){
		for(int j=0 ; j<dimantion ; j++){
			for(int k=0 ; k < set_size ; k++){
				sum+=(elem[k]->getRating(i) - u->getCoordinate(i))*(elem[k]->getRating(j) - u->getCoordinate(j));
            }
            if(set_size != 1 ) sum /= (set_size-1);
            cout <<round(100*sum)/100;
            sum = 0;
            if(j<dimantion-1) cout<<",";
		}
		cout<<endl;
	}
	cout<<"]"<<endl;

}
