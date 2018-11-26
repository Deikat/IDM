#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"

#include <string.h>

int main(){
	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();
	
	s->restoreStatus("Status0");
	for(int i=0; i<10; ++i){
		
		float nombre2 = s->flat();
		std::cout<<nombre2<<std::endl;
	}
	
	return 0;
}
