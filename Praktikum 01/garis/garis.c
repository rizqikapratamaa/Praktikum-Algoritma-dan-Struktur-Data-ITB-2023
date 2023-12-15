#include <stdio.h>
#include <math.h>
#include "garis.h"

void CreateGaris(GARIS * L, POINT P1, POINT P2){
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS * L){
    POINT p1, p2;
    do{
        BacaPOINT(&p1);BacaPOINT(&p2);
        if(EQ(p1, p2)){
            printf("Garis tidak valid\n");
        }
    } while (EQ(p1, p2));
    CreateGaris(L, p1, p2);
}

void TulisGARIS(GARIS L){
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

float PanjangGARIS(GARIS L){
    return Panjang(PAwal(L), PAkhir(L));
}

float Gradien(GARIS L){
    POINT P1 = PAwal(L);
    POINT P2 = PAkhir(L);
    return (Ordinat(P2) - Ordinat(P1))/(Absis(P2) - Absis(P1));
}

void GeserGARIS(GARIS * L, float deltaX, float deltaY){
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus(GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2){
    return (Gradien(L1) == Gradien(L2));
}

float JarakGARIS(GARIS L, POINT P){
    float a = Gradien(L);
    float b = -1.0;
    float c = PAwal(L).X * (-a) + PAwal(L).Y * (-b);

    float jarak = fabs((a * P.X + b * P.Y + c) / sqrt(a * a + b * b));

    return jarak;
}

boolean IsPointMemenuhiGaris(GARIS L, POINT P){
    float a = Gradien(L);
    float b = -1.0;
    float c = PAwal(L).X * (-a) + PAwal(L).Y * (-b);

    return a * P.X + b * P.Y + c == 0;
}