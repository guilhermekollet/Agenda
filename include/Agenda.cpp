#include "Agenda.hpp"

Agenda::Agenda(string name)
{

    _name = name;
    _dateCreated = getTime();
    _dateLastModified = getTime();
    _hrefDataBase = "../database/agenda.csv";

}

string Agenda::getTime()
{

    time_t t;
    struct tm * tempo;
    time(&t);
    tempo = localtime(&t);

    stringstream data;
    data << "Data: ";
    
    data << tempo->tm_mday << "/";
    if(tempo->tm_mon < 10)
    {
        
        data << "0" << tempo->tm_mon << "/";
    
    }
    else
    {

        data << tempo->tm_mon << "/";

    }

    data << tempo->tm_year+1900;

    if(tempo->tm_hour < 10)
    {

        data << " - Hora: 0" << tempo->tm_hour << ":";

    }
    else
    {

        data << " - Hora: " << tempo->tm_hour << ":";

    }

    if(tempo->tm_min < 10)
    {
        
        data << "0" << tempo->tm_min << ":";
    
    }
    else
    {

        data << tempo->tm_min << ":";

    }

    if(tempo->tm_sec < 10)
    {
        
        data << "0" << tempo->tm_sec;
    
    }
    else
    {

        data << tempo->tm_sec;

    }

return data.str();
}

Agenda::~Agenda()
{

}

string Agenda::getAgendaName()
{

return _name;
}

string Agenda::getDataCreated()
{

return _dateCreated;
}

string Agenda::getLastModified()
{

return _dateLastModified;
}

string Agenda::getProperties()
{

    stringstream ss;
    ss << "Agenda: " << _name << " - " << getAgendaSize() << " contatos salvos." << endl;
    ss << "Data de criacao: " << _dateCreated << " - Data da ultima modificacao: " << _dateLastModified;

return ss.str();
}

int Agenda::getAgendaSize()
{

return _list.size();
}

void Agenda::postDateLastModified()
{

    _dateLastModified = getTime();

}

string Agenda::getLista()
{

    stringstream ss;
    
    for(int i = 0; i < _list.size(); i++)
    {

        if(_list.at(i).getName() == "")
        {

            ss << _list.at(i).getLastName() << " | +" << _list.at(i).getDDD() << _list.at(i).getNumber() << endl;
        
        }
        else if(_list.at(i).getName() == "" && _list.at(i).getLastName() == "")
        {

            ss << "+" << _list.at(i).getDDD() << _list.at(i).getNumber() << endl;
        
        }
        else if(_list.at(i).getName() != "" && _list.at(i).getLastName() == "")
        {

            ss << _list.at(i).getName() << " | +" << _list.at(i).getDDD() << _list.at(i).getNumber() << endl;
        
        }
        else
        {

            ss << _list.at(i).getName() << " " << _list.at(i).getLastName()  << " | +" << _list.at(i).getDDD() << _list.at(i).getNumber() << endl;

        }

    }

return ss.str();
}

bool Agenda::getAgendaFromCSV(string csv)
{

    if(csv != "")
    {

        _dateLastModified = getTime();
        
        stringstream buffer(csv);
        string auxStream;

        getline(buffer, auxStream, ',');
        
        int qtd = stoi(auxStream);

        do
        {

            for(int i = 0; i < qtd; i++)
            {
                Contato *c = new Contato();
                
                getline(buffer, auxStream, ':');
                c->setNome(auxStream);

                getline(buffer, auxStream, ':');
                c->setSobrenome(auxStream);

                getline(buffer, auxStream, ':');
                c->setDDD(auxStream);

                getline(buffer, auxStream, ',');
                c->setNumero(auxStream);

                addContact(*c);
                delete c;
            }

        }
        while(buffer.good());

    }

return false;
}

bool Agenda::setAgendaToCSV()
{

    stringstream toCSV;

    if(getAgendaSize() == 0)
    {

        toCSV << "false";

    
    }


    toCSV << "true," << _name << "," << getAgendaSize() << ",";
    
    

    for(int i = 0; i < getAgendaSize()-1; i++)
    {

        toCSV << _list.at(i).getName() << ":" << _list.at(i).getLastName() << ":" << _list.at(i).getDDD() << ":" << _list.at(i).getNumber() << ",";

    }

/*
    ofstream writer(_hrefDataBase, ios::trunc);
    if(writer.is_open())
    {

        writer << toCSV.str();

    }

    writer.close();
*/
}

bool Agenda::addContact(Contato &contato)
{

    if(contato.getNumber() != "")
    {

        postDateLastModified();
        _list.push_back(contato);

    return true;
    }

}

bool Agenda::newContact(string name, string lastName, string ddd, string number)
{
    if(number != "")
    {
        postDateLastModified();
        Contato *c = new Contato(name, lastName, ddd, number);

        

        delete c;

    }

}

bool Agenda::setDataBase(string url)
{

    if(url != "")
    {

        _hrefDataBase = url;

    return true;    
    }

return false;

}