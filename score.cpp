#include "NumeroPartieNull_Exception.h" //classe d'exception
#include "score.hpp"

Score::Score()
{
}

Score::~Score()
{
}

Score::Score(unsigned long int numeroPartie, std::string login, unsigned long int meilleurScore)
{
    this->numeroPartie = numeroPartie;
    this->login = login;
    this->meilleurScore = meilleurScore;
}

unsigned long int Score::getNumeroPartie() const
{
    if(this->numeroPartie == 0) //Si numéro partie égale zéro on lance une exception
        throw NumeroPartieNullException(this->numeroPartie, this->login, this->meilleurScore);
    return this->numeroPartie;
}
std::string Score::getLogin() const
{
    return login;
}
unsigned long int Score::getMeilleurScore() const
{
    return meilleurScore;
}
void Score::setNumeroPartie(unsigned long int numeroPartie)
{
    this->numeroPartie = numeroPartie;
}
void Score::setLogin(std::string login)
{
    this->login = login;
}
void Score::setMeilleurScore(unsigned long int meilleurScore)
{
    this->meilleurScore = meilleurScore;
}

bool Score::operator<(const Score score_a_droite) const
{
    if(this->meilleurScore < score_a_droite.meilleurScore)
        return true;

    return false;
}
