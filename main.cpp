// Appello del 24 gennaio 2012.


#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
#include "sistema_informativo.h"

// list<Utente> PersonePresenti(SistemaInformativo& s);


int main(int argc, char **argv) {
	srand(time(0));
	cout << "0. " << endl;

	// creazione del sistema informativo che gestisce l'albergo.
	SistemaInformativo albergo;
	albergo.randomInitStanze();
	albergo.randomInitUtentiPrenotazioniPresenze();


	//risposta alla domanda 3.
	// non testata del tutto, ma lo spirito potrebbe essere questo.
	Utente* randomUser = albergo.getRandomUser();
	if (randomUser!=NULL) {
		cout << costiTotali(*randomUser) << endl;
	}


	cout << endl << "End. " << endl;
	return 0;
}




