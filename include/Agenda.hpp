#ifndef _AGENDA_HPP
#define _AGENDA_HPP

#include "Contato.hpp"
#include <ctime> 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class Agenda
{

    private:
    vector<Contato> _list;
    string _name;
    string _dateCreated;
    string _dateLastModified;
    string _hrefDataBase;

    public:
    Agenda(string name = "Pessoal");
    ~Agenda();

    string getTime();
    string getAgendaName();
    string getDataCreated();
    string getLastModified();
    string getProperties();

    string getLista();
    int getAgendaSize();

    bool getAgendaFromCSV(string csv);
    bool setAgendaToCSV();
    
    void postDateLastModified();
    bool addContact(Contato &contato);
    bool newContact(string name, string lastName, string ddd, string number);
    bool setDataBase(string url);

};

#endif