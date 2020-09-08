#ifndef __EXCEPTION_OFR_H__
#define __EXCEPTION_OFR_H__
#include <string>
class NumeroPartieNullException
{
public:
    NumeroPartieNullException(unsigned long int numeroPartie, std::string login, unsigned long int score)
    {
        this->numeroPartie = numeroPartie;
        this->login = login;
        this->score = score;
    }
    NumeroPartieNullException()
    {
    }
    std::string what() const
    { // Affichage d'un message détaillé  sur l’exception
        std::string message = " * Les donnees du joueur dont le Login est : ";
        message += this->login;
        message += ", avec le score : ";
        message += std::to_string(this->score);
        message += " ne sont \n    pas importees a cause du numero de la partie qui est nul (";
        message += std::to_string(this->numeroPartie);
        message += ").\n";
        return message;
    }

private: // Attributs qui servent pour afficher les informations sur l'exception
    unsigned long int numeroPartie;
    std::string login;
    unsigned long int score;
};
#endif // __EXCEPTION_OFR_H__
