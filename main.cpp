#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include "NumeroPartieNull_Exception.h" //classe d'exception
#include "Score.hpp"

int main()
{
    std::priority_queue<Score> myFileAsterostorm;

    std::string fileNameInput = "hiscore.txt";
    std::ifstream mon_lecteur(fileNameInput);

    /*On teste si tout est OK puisque des problèmes
     * peuvent survenir lors de l'ouverture d'un fichier*/
    if(mon_lecteur) {
        std::string identifiantPartie;
        std::string loginPlayer;
        std::string scorePlayer;

        /*On test si on a pa atteint la fin du fichier
         *et on récupère le numéro de la partie, login et score du joueur
         * et on les insère dans notre std::priority_queue (Tas)*/

        while(mon_lecteur.eof() == false) {
            // lecture des données
            getline(mon_lecteur, identifiantPartie);
            getline(mon_lecteur, loginPlayer);
            getline(mon_lecteur, scorePlayer);

            if(mon_lecteur.eof() == false) {
                /*Conversion de l'identifiant de la Partie et le score en entier long après la lecture
                 *instanciation d'un objet Score et l'insertion dans notre std::set (notre arbre binaire de recherche)*/
                Score scoreTemp(std::stol(identifiantPartie), loginPlayer, stol(scorePlayer));
                myFileAsterostorm.push(scoreTemp);
            }
        }

        mon_lecteur.close();

    } else { // On affiche un message si la lecture du fichier "hiscore.txt" a échoué
        std::cout << "Un probleme est rencontré avec l'ouverture du fichier : " << fileNameInput << std::endl;
    }

    std::string fileNameOutput = "asterostorm.txt";
    std::ofstream mon_ecrivain(fileNameOutput);
    int taille_Tas = myFileAsterostorm.size();
    for(int i = 0; i < taille_Tas; i++) {
        try { // bloc ou l'exception numero partie peut se produire
            // j'ai ajouter l'instruction "dataPlayer.getNumeroPartie()" juste pour éviter l'insertion du login en cas
            // d'exception
            Score dataPlayer = myFileAsterostorm.top();
            dataPlayer.getNumeroPartie();
            //
            mon_ecrivain << dataPlayer.getLogin() << std::endl;
            mon_ecrivain << dataPlayer.getNumeroPartie() << std::endl; //(ici peut se produire l'exception).
            mon_ecrivain << "Asterostorm=" << dataPlayer.getMeilleurScore() << std::endl;
            // Suppression de l'élément affiché
            myFileAsterostorm.pop();
        } // Attrapez l’exception lancée et affichez un message approprié
        catch(const NumeroPartieNullException& ex) {
            std::cout << ex.what() << std::endl;
            myFileAsterostorm.pop();
        }
    }

    mon_ecrivain.close();
    std::cout << " - Fin du programme, maintenant vous pouvez consulter le fichier de transfert : " << fileNameOutput
              << std::endl
              << std::endl;
    return 0;
}
