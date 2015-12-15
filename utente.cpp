#include <iostream>
using namespace std;

#include "utente.h"

string ND = "ND";

Utente::Utente() {
	nome = ND; cognome = ND; luogoNascita = ND; dataNascita = ND; docIdentita = ND;
}


void Utente::stampa() const {
	cout << nome << " " << cognome;
}

Utente::Utente(string n, string c, string l, string d, string doc) {
	nome=n; cognome=c; luogoNascita=l; dataNascita=d; docIdentita=doc;
}

// void Utente::prenota(string garr, string gpar, TipoStanza& ts) {
void Utente::prenota(Prenotazione& p) {
	// check global availability of rooms before pushing a booking into the list.

	// Prenotazione temp(garr, gpar, ts);
	// here we should have implemented Date and Time classes to correctly check
	// whether the user had booked another room in the same period.
	list <Prenotazione>::iterator lpi=lpreno.begin();
	for (; lpi != lpreno.end(); ++lpi) {
		if (p == *lpi) {
			cout << "Un'altra prenotazione è già stata effettuata dal cliente ";
			this->stampa();
			cout << " negli stessi giorni: "; p.stampa();
			cout << "." << endl;
			return;
		}
	}

	lpreno.push_back(p);
	return;
}


void Utente::presenza(Presenza& p) {
	list <Presenza>::iterator lpi=lprese.begin();
	for (; lpi != lprese.end(); ++lpi) {
		if (p == *lpi) {
			cout << "Un'altra presenza del cliente "; this->stampa();
			cout << " è già stata registrata negli stessi giorni: ";
			p.stampa(); cout << "." << endl;
			return;
		}
	}

	lprese.push_back(p);
	return;
}


bool Utente::operator==(Utente& u) {
	if (docIdentita == u.docIdentita)
		return true;
	return false;
}


bool Utente::esistePrenotazione(Prenotazione& p) {
	list <Prenotazione>::iterator lpi=lpreno.begin();
	for(;lpi!=lpreno.end(); ++lpi) {
		if (p==*lpi)
			return true;
	}
	return false;
}


Prenotazione& Utente::trovaPrenotazione(Prenotazione& p) {
	list <Prenotazione>::iterator lpi=lpreno.begin();
	for(;lpi!=lpreno.end(); ++lpi) {
		if (p==*lpi) {
			return *lpi;
		}
	}
	// Non esistono alternative in verità. bisogna prima controllare col metodo
	// esistePrenotazione se effettivamente esiste una prenotazione p.
	return *lpi; // Non arriva mai qua se prima viene controllata la presenza effettiva.
}


void Utente::addTipoStanzaAPrenotazione(Prenotazione& p, TipoStanza& _ts) {
	if (this->esistePrenotazione(p)) {
		this->trovaPrenotazione(p).addTipoStanza(_ts);
	}
	else {
		cout << "la prenotazione "; p.stampa();
		cout << " non esiste per il cliente "; this->stampa();
		cout << "." << endl;
	}
}


bool Utente::esistePresenza(Presenza& p) {
	return false;
}

void Utente::addStanzaAPresenza(Presenza& p, Stanza& _ts) {
	;
}


int costiTotali(Utente& u) {
	int tot=0;
	list <Presenza>::iterator lpri=u.lprese.begin();
	for (; lpri!=u.lprese.end(); ++lpri) {
		tot += lpri->getPrezzo();
	}
	return tot;
}