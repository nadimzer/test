/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   miniproj.h
 * Author: s.shah
 *
 * Created on 15 novembre 2018, 09:09
 */

#ifndef MINIPROJ_H
#define MINIPROJ_H

#ifdef __cplusplus
extern "C" {
#endif

    //int date;int classification;int durer;

    typedef struct {
        char titreFR[80];
        char titreENG[50];
        char realisateur [50];
        char acteur [50];
        char genre[80];
        int note ;
        int durer;
        int date;
        int classification;
    } film;


    void start();
    int menu();
    void ajouterFilm(); 
    void afficherTousLesFilms();
    void modifier();
    film rechercher(); //film(){
    void supprimer();
    void viderTamponEntree();
    film genre_film(film *fL);
    void filmdebasse();

    
    
    

   

    
    
            /* typedef struct{
          char genre[80];
      } film ;
    
    
    
      typedef struct  {           //le titre de film en English
          char titreENG[50];
    
      }titreENG;
    
    
      typedef struct {          // le titre de film en Français
      char titreFR [50];
  
  }titreFr;

  typedef struct {                      // le realisateur de ce film
   

  }realisateur;



  typedef struct {                  // les acteur qui joue dans le films
         char nom[50];
          char prenom[50];
  }acteur;


  typedef struct {        // la durer du film
      int heure;
      int minut;
  }durer;


  /*typedef struct {                        //le genre de film
      char drame  [50];
      char comedie  [50];
      char action  [50];
      char adventure [50];
      char fantastique  [50];
      char horreur [50];
      char policiere [50];
  
  }genre;*/






#ifdef __cplusplus
}
#endif

#endif /* MINIPROJ_H */

