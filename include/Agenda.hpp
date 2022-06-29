#ifndef _AGENDA_HPP
#define _AGENDA_HPP

#include "Contato.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Agenda
{

    private:
    vector<Contato> _Lista;
    string _nome;

    public:
    Agenda(string nome = "Pessoal");
    ~Agenda();
    string getNomeAgenda();
    int getSizeAgenda();
    string getLista();
    bool addExistentContact(Contato &contato);
    bool newContactFromCSV(string csv);
    bool newContact();

};

#endif