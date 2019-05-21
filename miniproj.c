/*
 * To typedef struct {
    char nom [50];
    char auteeur[50];
    int date_de_sorti;
    char realisateur[50];
    char genres[50];
    int classification = 0;
    char note_de_filme =0;

change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include "miniproj.h"
#include "data.h"
#include <string.h>




//

int menu() {
    int choix = 0;




    printf("                                                                                  888888888     \n       ");
    printf("                                                                         88888888888888     \n");
    printf("                                                                              88888888888888888        \n");
    printf("                                                                            8888    888888   8888       \n");
    printf("                                                                            8888 **  8888 **  8888      \n ");
    printf("                                                                           88888   888888   88888       \n ");
    printf("                                                                           8888888888888888888888      \n  ");
    printf("                                                                          8888888888888888888888       \n ");
    printf("                                                                           8888888888888888888888       \n ");
    printf("                                                                            88888888888888888888    \n  ");
    printf("                                                                            888888888888888888       \n   ");
    printf("                                                                            8888888  8888888   \n   ");
    printf("                                                                             88888    88888    \n ");
    printf("                                                                                88888  88888   \n ");
    printf("                                                                                  88888888      \n");
    printf("                                                                                    888888                \n");




    printf("                                                                   *****************************************                                \n");
    printf("                                                                    *     BIENVENU DANS LA VIDEOTHEQUE      *                                   \n");
    printf("                                ***************************************************************************************************************\n");
    printf("                                *         1 Ajouter un film                            |         4  modifier un film                          *\n");
    printf("                                ***************************************************************************************************************\n");
    printf("                                *         2 Afficher tous les films                    |         5 afficher uniquement un film                *\n");
    printf("                                ***************************************************************************************************************\n");
    printf("                                *         3 supprimer un film                          |         6 rechercher un film                         *\n");
    printf("                                ***************************************************************************************************************\n");
    printf("                                                                     *               0 exit            *                                           \n");
    printf("                                                                     ***********************************                                            \n");
    scanf("%d", &choix);
    getc(stdin);

    return choix;


}

void start() {
    //viderTamponEntree(stdin);
    int choixMenu = -1;
    int i = 0;
    //printf("\n\n");
    //printf("                                            ****************************************\n");
    //  printf("                                            *     BIENVENU DANS LA VIDEOTHEQUE     *\n");
    // printf("                                            ****************************************\n");

    while (choixMenu != 0) {
        choixMenu = menu();


        switch (choixMenu) {



            case 1:
                ajouterFilm();

                break;

            case 2:
                afficherTousLesFilms();

                break;

            case 3:
                supprimer();

                break;

            case 4:
                modifier();
               

                break;
            case 5:
                filmdebasse();

                break;
            case 6:
                rechercher();

                break;

            case 0:
                puts("Au revoir !");
                break;

            default:
                puts("Erreur choix, doit etre comprit entre 0 a 6 inclus");
                break;
        }
    }
}

void afficherTousLesFilms() {

    int i = 0;
    int nombreDeFilms = getNbFilms();

    for (i = 0; i < nombreDeFilms; i++) {

        printf("Titre en Francais : %s\n", getFilm(i).titreFR);
        printf("Titre en English: %s\n", getFilm(i).titreENG);
        printf("Sortie en salle : %d\n", getFilm(i).date);
        printf("Realisateur : %s\n", getFilm(i).realisateur);
        printf("Acteurs : %s \n", getFilm(i).acteur);
        printf("Genre :%s\n", getFilm(i).genre);
        printf("Classification ( pegi) : %d\n", getFilm(i).classification);
        printf("Note : %d\n", getFilm(i).note);



    }

}

void ajouterFilm() {
    FILE *fp = NULL;

    film newFilm;

    viderTamponEntree(stdin);
    fp = fopen("doc1.txt", "a+");


    printf("ajouter un titre en Francais:\n");
    fgets(newFilm.titreFR, 80, stdin);
    fputs(newFilm.titreFR, fp);

    printf("ajouter un titre en English:\n");
    fgets(newFilm.titreENG, 50, stdin);
    fputs(newFilm.titreENG, fp);
    printf("ajouter un realisateur:\n");
    fgets(newFilm. realisateur, 50, stdin);
    fputs(newFilm.realisateur, fp);
    printf("ajouter acteur:\n");
    fgets(newFilm.acteur, 50, stdin);
    fputs(newFilm.acteur, fp);
    printf("ajouter la durer du film:\n");
    scanf("%d", &newFilm.durer, stdin);
    fprintf(fp,"%d",newFilm.durer);
    printf("ajouter une classification: \n(3) \n(7) \n(12) \n(16) \n(18) \n");
    scanf("%d", &newFilm.classification, stdin);
   fprintf(fp,"%d",newFilm.classification);
    printf(" ajouter le genre du film\n");
    //  fgets(fL[nbFilms].genre, 80, stdin);
    printf("veuillez choisir votres choix : \n1 Action  : \n2 Animation  \n3 Art Martiaux \n4 Aventure \n5 Romance \n6 Horreur \n7 Historique "
            "\n8 Comedie \n9 Policier \n10 Fantastique \n11 Espionnage \n12 Guerre \n13 Wester \n14 Science-fiction\n");
    genre_film(&newFilm);

    printf(" ajouter l'annee du film:\n");
    scanf("%d", &newFilm.date);
    fprintf(fp,"%d",newFilm.date);
    printf("ajouter une note sur 10:\n");
    scanf("%d", &newFilm.note, stdin);
  fprintf(fp,"%d",newFilm.note);
    setFilm(newFilm, getNbFilms());
    setNbFilms();
    fclose(fp);
}

void viderTamponEntree() {

    int c;

    while ((c = fgetc(stdin)) != '\n') { // pour caracter supprimer

    }

}

film rechercher() {
    film f;
    char titre [50];
    int i = 0;

    printf("entrer le titre du film:\n");
    fgets(titre, 50, stdin);

    for (i = 0; i < getNbFilms(); i++) {
        if (strcmp(titre, getFilm(i).titreFR) == 0) {
            f = getFilm(i);
        } else {
            strcpy(f.titreFR, "");
        }
    }
    
    return f;
}

film genre_film(film *fL) {


    int choix = 0;
    printf("Genre du film : ");
    scanf("%d", &choix);
    fflush(stdin);




    switch (choix) {

        case 1:
            strcpy(fL->genre, "Action");

            break;
        case 2:
            strcpy(fL->genre, "Animation");

            break;
        case 3:
            strcpy(fL->genre, "Art Martiaux");

            break;
        case 4:
            strcpy(fL->genre, "Aventure");

            break;
        case 5:
            strcpy(fL->genre, "Romance");

            break;
        case 6:
            strcpy(fL->genre, "Horreur");

            break;

        case 7:
            strcpy(fL->genre, "Historique");

            break;
        case 8:
            strcpy(fL->genre, "Comedie");

            break;
        case 9:
            strcpy(fL->genre, "Policier");
            break;
        case 10:
            strcpy(fL->genre, "Fantastique");
            break;
        case 11:
            strcpy(fL->genre, "Espionnage");
            break;
        case 12:
            strcpy(fL->genre, "Guerre");
            break;
        case 13:
            strcpy(fL->genre, "Wester");
            break;

        case 14:
            strcpy(fL->genre, "science fiction");
            break;
        case 0:
            strcpy(fL->genre, "pas de genre");
            break;
        default:
            printf("Erreur : votre choix est inconnu\n");

            break;


    }

}




//void rechercher(film FL,int i){

//  printf("Quel film vous voulez rechercher :\n");
//  fgets 




//}


/*void supprimer(){
    film f;
    int i = 0;
    char titre [80];
    int ret;
    
    printf ("entrer le titre du film ");
    fgets (titre,sizeof (titre),stdin);
    titre[strlen(titre) - 1] = '\0';
    
    for (i = 0 ; i< getNbFilms(); i++){
       ret = strcmp (f[i].titreFR,titre);
       if (ret == 0)
           printf("le film a etait supprimer");
    }
    
    


}

*/
void suppriimer(){
    system("cls");
    
    film f;
    int i = 0;
    char titre [80];
    int a;
    char filmchoisie[100];
    int taille = 0 ;
    
    fflush(stdin);
    printf ("entrer le titre du film ");
    fgets (filmchoisie,99,stdin);
    taille = strlen(filmchoisie);
    
    filmchoisie[taille-1] = '\0';
    
        if (strcmp (filmchoisie,f.titreFR)== 0 || strcmp (filmchoisie,f.titreENG)==0){
        
            f = getFilm(i+1);
            setFilm(f,i);
            
     
    
    }
    
    
}

void supprimer() {
    system("cls");
    int i = 0;
    int val = 0;
    int resultat = 0;
    FILE *file;
    FILE *file2;
    char stock[200];
    char stock2[200];
    char bin[200];



    if ((file = fopen("film.txt", "r")) == NULL) {
        return 1;
    }

    if ((file2 = fopen("newfilm.txt", "w+")) == NULL) {
        return 2;
    }

    afficherTousLesFilms();

    printf("Quel film voulez vous supprimer ?\n");
    scanf("%d", &val);
    viderTamponEntree(stdin);

    resultat = ((val)*11);

    system("cls");

    while (i < resultat - 11 && fgets(stock, sizeof stock, file) != NULL) {
        i++;
        fputs(stock, file2);


    }

    while (i != (resultat) && fgets(bin, sizeof bin, file) != NULL) {
        i++;
        while (i >= resultat && fgets(stock2, sizeof stock2, file) != NULL) {

            fputs(stock2, file2);

            i++;
        }
    }

    fclose(file);
    fclose(file2);

    remove("film.txt");
    rename("newfilm.txt", "film.txt");

    supprimer(val);
    
}
void filmdebasse() {

    printf("titre en Francais:Forrest Gump\n");
    printf("titre en English:Forrest Gump\n");
    printf("realisateur: Robert Zemeckis\n");
    printf("acteur: Tom Hanks, Gary Sinise, Robin Wright\n");
    printf("durer du film:2h 20min\n");
    printf("classification:7\n");
    printf("le genre du film: Comédie\n");
    printf("l'annee du film:2015 \n");
    printf("note sur 10:6\n");






    printf("titre en Francais:Coco\n");
    printf("titre en English:Coco\n");
    printf("realisateur:Adrian Molina, Lee Unkrich\n");
    printf("acteur: Andrea Santamaria, Benjamin Bratt, Ary Abittan\n");
    printf("durer du film:1h 45min\n");
    printf("classification:3\n");
    printf("le genre du film: Animation\n");
    printf("l'annee du film:2017\n");
    printf("note sur 10:6\n");







    printf("titre en Francais:DJANGO UNCHAINED\n");
    printf("titre en English:DJANGO UNCHAINED\n");
    printf("realisateur:Quentin Tarantino\n");
    printf("acteur: Jamie Foxx, Christoph Waltz, Leonardo DiCaprio\n");
    printf("durer du film:2h 44min\n");
    printf("classification:12\n");
    printf("le genre du film:Western\n");
    printf("l'annee du film:2012\n");
    printf("note sur 10:\n");







    printf("titre en Francais:LE CHEVALIER NOIR\n");
    printf("titre en English:THE DARK KNIGHT\n");
    printf("realisateur:Christopher Nolan\n");
    printf("acteur: Christian Bale, Heath Ledger, Aaron Eckhart \n");
    printf("durer du film:2h 27min\n");
    printf("classification:12\n");
    printf("le genre du film: Action,\n");
    printf("l'annee du film:2008\n");
    printf("note sur 10:7\n");






    printf("titre en Francais:LE SEIGNEUR DES ANNEAUX : LE RETOUR DU ROI\n");
    printf("titre en English:LE SEIGNEUR DES ANNEAUX : LE RETOUR DU ROI\n");
    printf("realisateur: Peter Jackson\n");
    printf("acteur: Sean Astin, Elijah Wood, Viggo Mortensen \n");
    printf("durer du film:3h 21min\n");
    printf("classification:12\n");
    printf("le genre du film: Fantastique\n");
    printf("l'annee du film:2003\n");
    printf("note sur 10:8\n");

}
