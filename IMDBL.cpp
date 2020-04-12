//============================================================================
// Name        : IMDBL.cpp
// Author      : yair
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Set.h"
using namespace std;

int main(int argc, char *argv[]) {

	/*  need to be check  */
	int dimantion = atoi(argv[1]);
	int max_movies = atoi(argv[2]);

	Set* movieSet = new Set(max_movies , dimantion);
	MovieRate* movie_t;
	int option;
	while(true){

		//round(100*num)/100;
		cout<<"pleas choose your option"<<endl;
		cout<<"**********************************************"<<endl;
		cout<<"[0] exit system"<<endl;
		cout<<"[1] add/update movie ratings"<<endl;
		cout<<"[2] show movie ratings"<<endl;
		cout<<"[3] show average movie rating"<<endl;
		cout<<"[4] show movies statistics"<<endl;
		cout<<"[5] show rating statistics"<<endl;
		cout<<"[6] show covariance matrix"<<endl;
		cout<<"**********************************************"<<endl;
		cin>>option;
		switch(option){
		case 0:
			cout<<"exit system bye"<<endl;
			return 0;
		case 1:
			if(!movieSet->getInput(dimantion)){
				cerr<<"invalid input"<<endl;
			}
			break;
		case 2:

			movie_t = movieSet->searchByName(); // searching movie
			if(movie_t == NULL) break;
			movie_t->print();
			break;
		case 3:
			movie_t = movieSet->searchByName(); // searching movie
			if(movie_t == NULL) break;
			cout<<"the average is:"<<movie_t->average()<<endl;
			break;
		case 4:
			if(movieSet->getSetSize() == 0){
				cerr<<"no record in the system"<<endl;
				break;
			}
			movieSet->summery();
			break;
		case 5:
			if(movieSet->getSetSize() == 0){
				cerr<<"no record in the system"<<endl;
				break;
			}
			movieSet->statistics(dimantion)->printVector();
			break;
		case 6:
			if(movieSet->getSetSize() == 0){
				cerr<<"no record in the system"<<endl;
				break;
			}
			movieSet->covariance(dimantion);
			break;
		default:
			cerr<<"ERROR: invalid command; type 0 for exit\n";
		}
	}
	return 0;
}



