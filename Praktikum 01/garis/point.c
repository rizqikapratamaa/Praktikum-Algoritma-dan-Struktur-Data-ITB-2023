#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "boolean.h"
#define pi 3.14159265359

void CreatePoint (POINT * P, float X, float Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P)
{
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT (POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2)
{
    return((Absis(P1) == Absis(P2) && (Ordinat(P1) == Ordinat(P2))));
}

boolean NEQ (POINT P1, POINT P2)
{
    return((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P)
{
    return((Absis(P)==0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P)
{
    return(Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
{
    return(Absis(P) == 0);
}

int Kuadran (POINT P)
{
    if ((Absis(P) > 0) && (Ordinat(P) > 0))
    {
        return 1;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) > 0))
    {
        return 2;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) < 0))
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

POINT NextX (POINT P)
{
    Absis(P)++;
    return P;
}

POINT NextY (POINT P)
{
    Ordinat(P)++;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
{
    if(SbX == true)
    {
        Ordinat(P) = Ordinat(P) * -1;
        return P;
    }
    else if(SbX == false)
    {
        Absis(P) = Absis(P) * -1;
        return P;
    }
}

float Jarak0 (POINT P)
{
    return sqrt(powf(Absis(P), 2) + powf(Ordinat(P), 2));
}

float Panjang (POINT P1, POINT P2)
{
    return sqrt(powf((Absis(P2)-Absis(P1)), 2) + powf((Ordinat(P2)-Ordinat(P1)), 2));
}

void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}

void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
{
    if(SbX == true)
    {
        Ordinat(*P) = Ordinat(*P) * -1;
    }
    else
    {
        Absis(*P) = Absis(*P) * -1;
    }
}

void Putar (POINT *P, float Sudut)
{
   float sudutRadian;
   sudutRadian = -1 * Sudut * pi / 180;
   CreatePoint(P, Absis(*P) * cos(sudutRadian) - Ordinat(*P) * sin(sudutRadian), Absis(*P) * sin(sudutRadian) + Ordinat(*P) * cos(sudutRadian));
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2)
{
    int a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P1) - (a * Absis(P1));

    printf("(%d,%d)", a, b);
}
