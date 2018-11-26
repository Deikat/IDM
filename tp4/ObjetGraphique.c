#include <stdio.h>


typedef struct ObjetGraphique * this;

/* -------------------- META OBJET -------------------- */
typedef struct MetaObjetGraphique{
	void (*setX) (int, this);
	void (*setY) (int, this);
	int (*getX) (this);
	int (*getY) (this);
	
	int NbObjetGraphique;
	
	int (*GetNgObjetGraphique) (void);
	
	void (*ConstructeurObjetGraphique) (this);
	
	void (*ConstructeurMetaObjetGraphique) (this);
	
}MetaObjetGraphique_t;

/* ---------------------- OBJET --------------------- */
typedef struct ObjetGraphique{
	struct MetaObjetGraphique * maClasse;
	int x;
	int y;
}ObjetGraphique_t;


/* -------------------- METHODES -------------------- */
int getX(this t){
	return t->x;
}
int getY(this t){
	return t->y;
}
void setY(int inY, this t){
	t->y = inY;
}
void setX(int inX, this t){
	t->x = inX;
}

/* ------------------ SUPER OBJET ------------------ */
MetaObjetGraphique_t LeMetaObjetGraphique;


int GetNgObjetGraphique(void){
	return LeMetaObjetGraphique.NbObjetGraphique;
}
void ConstructeurObjetGraphique(this t){
	t->x = 0;
	t->y= 0;
	t->maClasse = &LeMetaObjetGraphique;
	LeMetaObjetGraphique.NbObjetGraphique ++;
}


void initLeMetaObjetGraphique(){
	LeMetaObjetGraphique.ConstructeurObjetGraphique = ConstructeurObjetGraphique;
	LeMetaObjetGraphique.GetNgObjetGraphique = GetNgObjetGraphique;
	LeMetaObjetGraphique.NbObjetGraphique = 0;
	LeMetaObjetGraphique.getX = getX;
	LeMetaObjetGraphique.getY = getY;
	LeMetaObjetGraphique.setX = setX;
	LeMetaObjetGraphique.setY = setY;
	
}


int main(){
	ObjetGraphique_t monObjet;
	
	initLeMetaObjetGraphique();
	printf("%d\n",LeMetaObjetGraphique.GetNgObjetGraphique());
	
	LeMetaObjetGraphique.ConstructeurObjetGraphique(&monObjet);
	printf("%d\n",LeMetaObjetGraphique.GetNgObjetGraphique());
	printf("x=%d y=%d\n",LeMetaObjetGraphique.getX(&monObjet),LeMetaObjetGraphique.getY(&monObjet));
	LeMetaObjetGraphique.setX(42,&monObjet);
	LeMetaObjetGraphique.setY(-42,&monObjet);
	printf("x=%d y=%d\n",LeMetaObjetGraphique.getX(&monObjet),LeMetaObjetGraphique.getY(&monObjet));
	
	return 0;
}
