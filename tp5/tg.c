#include <stdio.h>


#define TAILLE_MAX 5
typedef enum{FAUX=0, VRAI=1} bool;

#define DECLARER_PILE(TYPE) \
typedef struct Pile##TYPE  \
{ \
	TYPE  pile[TAILLE_MAX]; \
	TYPE* top; \
	int indiceTop;
\
} Pile##TYPE##_t;\
/* empile la valeur */ \
void empiler##TYPE(TYPE valeur, struct Pile##TYPE* this); \
\
/* dépile en retournant le sommet */\
TYPE depiler##TYPE(struct Pile##TYPE* this);\
\
/* Prédicat: la pile est-elle vide? */\
bool estVide##TYPE(struct Pile##TYPE* this);\
\
/* renvoie le sommet de pile */ \
TYPE sommet##TYPE(struct Pile##TYPE* this);

#define IMPLEMENTER_PILE(TYPE) \
void empiler##TYPE(TYPE a, struct Pile##TYPE * this){ \
	if(this->indiceTop < TAILLE_MAX){ \
		this->pile[this->indiceTop +1] = a; \
		this->top = &this->pile[0]; \
		this->indiceTop ++;\
	}
}\
\
TYPE depiler##TYPE(struct Pile##TYPE* this){
	if(this->indiceTop != -1){ \
		this->top = & this.pile[this->indiceTop -1];\
		this->indiceTop --;\
		return this->Pile[this->indiceTop];\
	}\
	return -1;\
}
	
								
//* on met ici le code des “méthodes” de la pile 


#define DEFINIR_MAX(TYPE) \
TYPE max##TYPE(TYPE a, TYPE b) { return a >=b ? a : b; }

DEFINIR_MAX(int)

DECLARER_PILE(int)
DECLARER_PILE(float)
IMPLEMENTER_PILE(int)
IMPLEMENTER_PILE(float)

int main(int argc, char ** argv)
{
	printf("%d\n", maxint(5,7));
	
	Pileint_t   pi;
	Pilefloat_t pf;
	pi.top = NULL;
	pi.indiceTop = -1;
	empilerint(5, &pi);
	
	/*depilerint(&pi);
	pf.top = NULL;
	empilerfloat(5, &pf);
	depilerfloat(&pf);*/
	 
	 return 0;
}
