#include <stdio.h>

int main(){
	float a = 0.7;
	float b = 0.5;
	
	if(a <.7){
		if(b < .5) printf("2"); /* 0.5 tombe pile car float codés sur en binaire */
		else printf("1"); /* bonne reponse */
	}
	else printf("0");
	/*printf("%d",a<(float).7); .7 != (float) .7*/
	
	return 0;
}
