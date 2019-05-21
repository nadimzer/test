/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: s.shah
 *
 * Created on 18 décembre 2018, 09:41
 */

#include "miniproj.h"

#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
extern "C" {
#endif

    film getFilm(int i);
    void setFilm(film f, int i);
    int getNbFilms();
    void setNbFilms();


#ifdef __cplusplus
}
#endif

#endif /* DATA_H */

