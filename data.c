/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "data.h"

static film fL [500];
static int nbFilms = 0;

film getFilm(int i) {
    return fL[i];
}

void setFilm(film f, int i) {
    fL[i] = f;
}

int getNbFilms() {
    return nbFilms;
}

void setNbFilms() {

    nbFilms++;
}