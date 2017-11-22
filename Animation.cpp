/** Classe mère Animation

    Implémentation de la classe mère Animation, ce code est générique à toutes les animations
    Besoin d'écrire du code que vont exécuter toutes les animations ? C'est ici

    Pour écrire une nouvelle animation, regarder plutôt le fichierd'en-tête (.h)
**/

#include <Animation.h>

Animation::Animation() {

}


int Animation::setup(unsigned int height, unsigned int width, unsigned int loops) {

}


void Animation::loop() {

}

char *Animation::white(){
	char ret[3] = {255, 255, 255};
        return ret;
}

char *Animation::black(){
	char ret[3] = {0, 0, 0};
        return ret;
}

char *Animation::red(){
	char ret[3] = {255, 0, 0};
        return ret;
}

char *Animation::green(){
	char ret[3] = {0, 255, 0};
        return ret;
}

char *Animation::blue(){
	char ret[3] = {0, 0, 0};
        return ret;
}

unsigned char *Animation::rgb(int r, int g, int b){
	unsigned char ret[3] = {r, g, b};
	return ret;
}

/** D'après https://fr.wikipedia.org/wiki/Teinte_Saturation_Valeur#Conversion_de_TSV_vers_RVB */
char *Animation::hsv(int h, int s, int v){
	char ret[3];
	int ti = (int)(h/60) % 6;
	int f = (h/60) - ti;
	int l = v * (1 - s);
	int m = v * (1 - f * s);
	int n = v * (1 - (1 - f) * s);
	switch(ti){
		case 0:	ret[0]=v; ret[1]=n; ret[2]=l; break;
		case 1:	ret[0]=m; ret[1]=v; ret[2]=l; break;
		case 2: ret[0]=l; ret[1]=v; ret[2]=n; break;
		case 3: ret[0]=l; ret[1]=m; ret[2]=v; break;
		case 4: ret[0]=n; ret[1]=l; ret[2]=v; break;
		case 5: ret[0]=v; ret[1]=l; ret[2]=m; break;
	}
	return ret;
}
