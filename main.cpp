#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include "NumeroPartieNull_Exception.h" //classe d'exception
#include "Score.hpp"

int main()
{
    std::set<Score> myFileAsterostorm;

    std::string fileNameInput = "hiscore.txt";
    std::ifstream mon_lecteur(fileNameInput);

    /*On teste si tout est OK puisque des problèmes
     * peuvent survenir lors de l'ouverture d'un fichier*/
    if(mon_lecteur) {
        std::string identifiantPrtie;
        std::string loginPlayer;
        std::string scorePlayer;

        /*On test si on a pa atteint la fin du fichier
         *et on récupère le numéro de la partie, login et score du joueur
         * et on les insère dans notre arbre binaire de recherche std::set<Score>*/

        while(mon_lecteur.eof() == false) {

            getline(mon_lecteur, identifiantPrtie);
            getline(mon_lecteur, loginPlayer);
            getline(mon_lecteur, scorePlayer);

            if(mon_lecteur.eof() == false) {
                Score scoreTemp(std::stol(identifiantPrtie), loginPlayer, stol(scorePlayer));
                myFileAsterostorm.insert(scoreTemp);
            }
        }

        mon_lecteur.close();

    } else { // On affiche un message si la lecture du fichier "hiscore.txt" a échoué
        std::cout << "Un probleme est rencontré avec l'ouverture du fichier : " << fileNameInput << std::endl;
    }
    /* Création d'un itérateur pour récuperer les éléments de l'arbre
     * et les mettre dans notre nouveau fichier "asterostorm.txt"*/
    std::set<Score>::iterator mon_iterateur;

    std::string fileNameOutput = "asterostorm.txt";
    std::ofstream mon_ecrivain(fileNameOutput);

    for(mon_iterateur = myFileAsterostorm.begin(); mon_iterateur != myFileAsterostorm.end(); mon_iterateur++) {
        try { // bloc ou l'exception numero partie peut se produire
            // j'ai ajouter l'instruction suivante juste pour éviter l'insertion du login en cas d'exception
            (*mon_iterateur).getNumeroPartie();
            //
            mon_ecrivain << (*mon_iterateur).getLogin() << std::endl;
            mon_ecrivain << (*mon_iterateur).getNumeroPartie() << std::endl; //(ici peut se produire l'exception).
            mon_ecrivain << "Asterostorm=" << (*mon_iterateur).getMeilleurScore() << std::endl;
        } // Attrapez l’exception lancée et affichez un message approprié
        catch(const NumeroPartieNullException& ex) {
            std::cout << ex.what() << std::endl;
        }
    }

    mon_ecrivain.close();
    std::cout << " - Fin du programme, maintenant vous pouvez consulter le fichier de transfert : " << fileNameOutput
              << std::endl
              << std::endl;
    return 0;
}
