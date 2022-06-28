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
    string getNome();
    string getLista();
    bool addExistentContact(Contato &contato);
    bool newContact();

};

#endif