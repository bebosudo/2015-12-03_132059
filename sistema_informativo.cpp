#include <iostream>
using namespace std;
#include "sistema_informativo.h"
#include <cstdlib>

// #include <sstream>

// SistemaInformativo::SistemaInformativo() { }

int casuale(int min, int max) { return rand()%(max-min+1); }

void SistemaInformativo::addStanzaAlSistema(Stanza s) { lstanze.push_back(s); }


// prima di aggiungere una prenotazione, si controlla se c'è almeno una stanza
// come quella richiesta.
bool SistemaInformativo::checkDisponibilitaStanza(TipoStanza& ts) {
	list <Stanza>::iterator lsti=lstanze.begin();
	for (; lsti!=lstanze.end(); ++lsti) {
		// sfrutto l'ereditarietà per fare il confronto tra una stanza e un tipoStanza
		if (*lsti == ts) {
			if ( lsti->isEmpty() ) {
				return true;
			}
		}
	}
	// se tutte le stanze sono occupate o non esistono stanze del genere: false
	return false;
}


void SistemaInformativo::addUtente(Utente u) { lutenti.push_back(u); }


bool SistemaInformativo::checkUtente(Utente& u) {
	list <Utente>::iterator lu=lutenti.begin();
	for (; lu!=lutenti.end(); ++lu) {
		if (*lu == u)
			return true;
	}
	return false;
}


// bisogna prima utilizzare checkUtente per assicurarsi che l'utente cercato esista.
Utente& SistemaInformativo::trovaUtente(Utente& u) {
	list <Utente>::iterator lu=lutenti.begin();
	for (; lu!=lutenti.end(); ++lu) {
		if (*lu == u)
			return *lu;
	}
	return u;
}


void SistemaInformativo::addPrenotazione(Utente& u, Prenotazione& p) {
	if (this->checkUtente(u)) {
		this->trovaUtente(u).prenota(p);
	}
	else {
		cout << "Utente "; u.stampa();
		cout << " non trovato. Prenotazione per il periodo ";
		p.stampa();
		cout << " non effettuata." << endl;
	}
	//lutenti.push_back(u);
}


void SistemaInformativo::addTipoStanzaAPrenotazione(Utente& u, Prenotazione& p, TipoStanza& ts) {
	if (this->checkDisponibilitaStanza(ts)) {
		if (u.esistePrenotazione(p)) {
			u.trovaPrenotazione(p).addTipoStanza(ts);
			cout << "Aggiunta tipologia di stanza "; ts.stampa();
			cout << " alla prenotazione "; p.stampa();
			cout << " dell'utente "; u.stampa(); cout << "." << endl;
		}
		else {
			cout << "Prenotazione "; p.stampa();
			cout << " non trovata per l'utente: "; u.stampa();
			cout << "." << endl;
		}
	}
	else {
		cout << "La tipologia di stanza "; ts.stampa();
		cout << " richiesta dall'utente "; u.stampa();
		cout << " per la prenotazione "; p.stampa();
		cout << " non esiste o non è più disponibile." << endl;
	}
}


void SistemaInformativo::addPresenza(Utente& u, Presenza& p) {
	if (this->checkUtente(u)) {
		this->trovaUtente(u).presenza(p);
	}
	else {
		cout << "Utente "; u.stampa();
		cout << " non trovato. Presenza per il periodo ";
		p.stampa(); cout << " non registrata." << endl;
	}
}

void SistemaInformativo::randomInitStanze() {
	for (int i=1; i<3; ++i) {
		for (int j=1; j<15; ++j) {
			// To randomize the numbers of the rooms.
			if (casuale(0,3)%2==0) continue;
			this->addStanzaAlSistema(Stanza((dimStanza)casuale(SINGOLA, SUITE),
											casuale(1, 5),
											(esposizioneStanza)casuale(SE, SO),
											i*100+j,
											casuale(10, 30),
											casuale(10, 30)+10
										   )
									);
		}
	}
}


void SistemaInformativo::randomInitUtentiPrenotazioniPresenze() {
	Utente array_utenti[20];
	for (int i=0; i<20; ++i) {
		this->addUtente(array_utenti[i]);
	}

	list <Utente>::iterator lui=lutenti.begin();
	for(; lui!=lutenti.end(); ++lui) {
		Prenotazione p_temp("DATAprova", "2aDATAprova");
		lui->prenota(p_temp);

		Presenza pr_temp("DATAprovaPresenza", "2aDATAprovaPresenza", casuale(30, 60),
						 (strumPagamento)casuale(0, 3));
		lui->presenza(pr_temp);
		for (int j=0; j<4; ++j) {
			Stanza s_temp((dimStanza)casuale(SINGOLA, SUITE),
						  casuale(1, 5), (esposizioneStanza)casuale(SE, SO),
						  casuale(101, 130), casuale(30, 40), casuale(40, 60)
						 );
			lui->addTipoStanzaAPrenotazione(p_temp, s_temp);
			if ( this->checkDisponibilitaStanza(s_temp) ) {
				lui->addStanzaAPresenza(pr_temp, s_temp);
			}
		}
	}
}


Utente* SistemaInformativo::getRandomUser() {
	if (lutenti.size()==0) return NULL;
	return &( *lutenti.begin() );
}


// list<Utente> PersonePresenti(SistemaInformativo& s) {
	// list<Utente> temp;
	// list<Utente>::iterator lui=s.lutenti.begin();
	// for(; lui!=s.lutenti.end(); ++lui) {
		// temp.push_back(*lui);
	// }
// }




