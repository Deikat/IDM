#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"

#include <string.h>

int main(int argc, char  * argv[]){
	if(argc ==1 ){
		int SequenceLength = 1000000000;
		int NbPointsInTheCercle = 0;

		CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();
		
		s->restoreStatus(argv[0]);
		for(int i=0; i<SequenceLength; ++i){
			
			double nombreX = s->flat();
			double nombreY = s->flat();
			if(nombreX*nombreX+nombreY*nombreY < 1)
				++ NbPointsInTheCercle;
		}
		printf("PI = %f",(double)NbPointsInTheCercle*4/SequenceLength);
	}else{
		printf("Erreur, format attendu : CodeSimuPi Status0");
	}
	return 0;}
