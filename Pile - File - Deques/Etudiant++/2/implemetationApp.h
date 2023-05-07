#include <iostream>
#include "implementationContact.h"
#include "implementationDir.h"
#include "implementationList.h"
#include "implementationNode.h"
#include "dir.h"

int App::run()
{
    Dir dir;
    d =dir;
    int NBC;
    string searchEmail;
    string name, email, phone;
    Node *node = NULL;
    do
    {
        system("cls");
        int choix;
        std::cout << "LA LIST DES CONTACTS" << std::endl;
        std::cout << "_--_-_-_-_-_--_-_-_-_-_-_-_-_-_-__-" << std::endl;
        std::cout << "1) ajouter un contact .." << std::endl;
        std::cout << "2) supprimer un contact .." << std::endl;
        std::cout << "3) modifier un contact .." << std::endl;
        std::cout << "4) chercher a un contact .." << std::endl;
        std::cout << "5) afficher la list de tout les contacts .." << std::endl;
        std::cout << "6) quite .." << std::endl;
        std::cout << "entrer votre choix .." << std::endl;
        std::cin >> choix;
        switch (choix)
        {
        case 1:
            system("cls");
            std::cout << "enter le nombre des contacts que vous voulez ajouter ";
            std::cin >> NBC;
            for (int index = 0; index < NBC; index++)
            {
                string name, email, phone;
                std::cout << "le nom du contact [ " << index + 1 << "] ";
                std::
                        cin >>
                    name;
                std::cout << "l'email du contact [ " << index + 1 << "] ";
                std::cin >> email;
                std::cout << "la numero du contact [ " << index + 1 << "] ";
                std::cin >> phone;
                dir.add(name, email, phone);
            }
            break;
        case 2:
            system("cls");

            std::cout << "enter l'email de contact a supprimer ";
            std::cin >> email;
            dir.remove("", email);
            break;
        case 3:
            system("cls");
            std::cout << "enter l'email de contact que vous voulez modifier ";
            std::cin >> searchEmail;
            std::cout << "les nouveaux informations ..." << std::endl;
            std::cout << "le nom du contact ";
            std::
                    cin >>
                name;
            std::cout << "l'email du contact  ";
            std::
                    cin >>
                email;
            std::cout << "la numero du contact ";
            std::
                    cin >>
                phone;
            dir.update(searchEmail, name, email, phone);
            break;
        case 4:
            system("cls");
            std::cout << "enter l'email de contact que vous voulez chercher ";
            std::cin >> searchEmail;
            node = dir.search("", searchEmail);
            displayContact(node);
            getchar();
            getchar();

            break;
        case 5:
            system("cls");
            std::cout << "la list de toutes les contacts .." << std::endl;
            dir.print();
            getchar();
            getchar();
            break;
        case 6:
            std::cout << "fin de programme merci ..." << std::endl;
            return 0;
            break;
        default:
            std::cout << "votre saisie est erronée" << std::endl;
            break;
        }

    } while (1);

    return 0;
}