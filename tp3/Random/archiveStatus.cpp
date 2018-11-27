#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"

#include <string.h>

int main(){
	
	int SequenceLength = 1000000000;
	int NbSequences = 1;
	
	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();	// initialisation du moteur de MT
	
	for(int numSeq = 0; numSeq<NbSequences; numSeq ++){
		char fileName[20];
		char num[3];
		sprintf(num,"%d",numSeq);
		strcpy(fileName,"Status");
		strcat(fileName,num);
		//std::cout<<fileName<<std::endl;
		
		s->saveStatus(fileName);
		//std::cout<<"Sequence "<<numSeq<<" :"<<std::endl;
		for(int i=0; i<SequenceLength; ++i){
			float nombre = s->flat();
			//td::cout<<nombre<<std::endl;
		}
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
