#ifndef SCORE_HPP
#define SCORE_HPP
#include <iostream>
#include <string>

class Score
{
public:
    Score();
    ~Score();
    Score(unsigned long int numeroPartie, std::string login, unsigned long int meilleurScore);
    unsigned long int getNumeroPartie() const;
    std::string getLogin() const;
    unsigned long int getMeilleurScore() const;
    void setNumeroPartie(unsigned long int numeroPartie);
    void setLogin(std::string login);
    void setMeilleurScore(unsigned long int meilleurScor);
    bool operator<(const Score score_a_droite) const;

private:
    unsigned long int numeroPartie;
    std::string login;
    unsigned long int meilleurScore;
};

#endif // SCORE_HPP
