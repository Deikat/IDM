#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"

int main(){
	
	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();	// initialisation du moteur de MT
	s->saveStatus("Status0");
	for(int i=0; i<10; ++i){
		
		float nombre = s->flat();
		std::cout<<nombre<<std::endl;
		
	}
	
	s->restoreStatus("Status0");
	for(int i=0; i<10; ++i){
		
		float nombre2 = s->flat();
		std::cout<<nombre2<<std::endl;
	}
	
	return 0;
}



// init MT
// SaveStatus("Status0"); -> créer fichier 6 ko
// generation de 1M nombres -> flat()
// SaveStatus("Status1"); -> créer fichier 6 ko
// generation de 1M nombres -> flat()
// SaveStatus("Status2"); -> créer fichier 6 ko
// ...
// generation de 1M nombres -> flat()
// SaveStatus("Status9"); -> créer fichier 6 ko



// # CodeSimuPI statusN
// # ..
// # restaureStatus("StatusN")
// # CalculPI



// fichier batch
// # CodeSimuPI status0 &
// # ...
// # CodeSimuPI status9 &
// chmod +x batch
// ./batch
