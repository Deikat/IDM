#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"

#include <string.h>
#include <algorithm> 

int main(){
	
	int SequenceLength = 5;
	int NbSequences = 3;
	
	CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();	// initialisation du moteur de MT
	
	float savedFloats[SequenceLength*NbSequences];
	float restoredFloats[SequenceLength*NbSequences];
	
	
	for(int numSeq = 0; numSeq<NbSequences; numSeq ++){
		char fileName[20];
		char num[3];
		sprintf(num,"%d",numSeq);
		strcpy(fileName,"Status");
		strcat(fileName,num);
		
		s->saveStatus(fileName);
		for(int i=0; i<SequenceLength; ++i){
			float nombre = s->flat();
			savedFloats[numSeq*SequenceLength+i] = nombre;
		}
	}
	
	for(int numSeq = 0; numSeq<NbSequences; ++numSeq){
		char fileName[20];
		char num[3];
		sprintf(num,"%d",numSeq);
		strcpy(fileName,"Status");
		strcat(fileName,num);
		
		s->restoreStatus(fileName);
		for(int i=0; i<SequenceLength; ++i){
			float nombre2 = s->flat();
			restoredFloats[numSeq*SequenceLength+i] = nombre2;
		}
	}
	
	bool areEquals = true;
	bool noRecovery = true;
	savedFloats[0] = savedFloats[3];
	restoredFloats[0]=restoredFloats[3];
	
	std::cout << "SavedFloats  \tRestoredFLoats\tEquals?  \tRecovery?"<<std::endl;
	for(int i=0; i<SequenceLength*NbSequences; ++i){
		if((i)%SequenceLength ==0)
			std::cout<<"---- Sequence n°"<<(int)(i/NbSequences)<<" ----"<<std::endl;
			
		std::cout<<savedFloats[i]<<"  \t"<<restoredFloats[i];
		
		if(savedFloats[i] == restoredFloats[i])
			std::cout<<"  \t==";
		else{
			std::cout<<"  \t!=";
			areEquals = false;
		}
		if(*std::find(savedFloats,savedFloats+i,savedFloats[i])==savedFloats[i])
			std::cout<<"  \tyes"<<std::endl;
		else{
			std::cout<<"  \tno"<<std::endl;
			noRecovery = false;
		}
		
	}
	bool result = areEquals & noRecovery;
	std::cout<<"Le sequence splitting fonctionne-t-il ? "<<result<<std::endl;

	return 0;
}
