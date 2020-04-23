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
	if(dimantion < 1 || max_movies < 1 ){
	    cerr<<"ERROR: USAGE "<< argv[0] << "NUM_RANKERS MAX_MOVIES"<<endl;
	    exit(0);
	}


	Set* movieSet = new Set(max_movies , dimantion);
	MovieRate* movie_t;
	char option;
	while(true){
		cout<<"[1] add/update movie ratings"<<endl;
        cout<<"[2] show movie ratings"<<endl;
        cout<<"[3] show average movie rating"<<endl;
        cout<<"[4] show movies statistics"<<endl;
        cout<<"[5] show rating statistics"<<endl;
        cout<<"[6] show covariance matrix"<<endl;
        cout<<"[0] exit"<<endl;
        cin>>option;
		cin.get();
		switch(option){
		case '0':
		    delete movieSet;
			return 0;
		case '1':
			if(!movieSet->getInput(dimantion)){
				cerr<<"ERROR: invalid input"<<endl;
			}
			break;
		case '2':
			movie_t = movieSet->searchByName(); // searching movie
			if(movie_t == NULL) break;
			movie_t->print();
			break;
		case '3':
			movie_t = movieSet->searchByName(); // searching movie
			if(movie_t == NULL) break;
			cout<<movie_t->getName()<<", "<< round(100*(movie_t->average()))/100 <<endl;
			break;
		case '4':
			if(movieSet->getSetSize() == 0){
				cerr<<"ERROR: no records in the system"<<endl;
				break;
			}
			movieSet->summery();
			break;
		case '5':
			if(movieSet->getSetSize() == 0){
				cerr<<"ERROR: no records in the system"<<endl;
				break;
			}
			cout<<"mean";
			movieSet->statistics(dimantion)->printVector();
			break;
		case '6':
			if(movieSet->getSetSize() == 0){
				cerr<<"ERROR: no records in the system"<<endl;
				break;
			}
			movieSet->covariance(dimantion);
			break;
		default:
			cerr<<"ERROR: invalid command; type 0 for exit\n";
		}
	}
}



