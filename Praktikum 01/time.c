#include <stdio.h>
#include <math.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S){
    if (H < 0 || H > 23 || M < 0 || M > 59 || S < 0 || S > 59){
        return false;
    }
    return true;
}

void CreateTime (TIME * T,  int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME(TIME *T){
    int HH, MM, SS;
    do {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (!IsTIMEValid(HH, MM, SS)){
            printf("Jam tidak valid\n");
        }
    } while (!IsTIMEValid(HH, MM, SS));
    
    T->HH = HH;
    T->MM = MM;
    T->SS = SS;
}

void TulisTIME(TIME T){
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T){
    return 3600*Hour(T) + 60*Minute(T) + Second(T);
}

TIME DetikToTIME (long N){
    N %= 86400;
    int HH = N / 3600;
    N %= 3600;

    int MM = N / 60;
    int SS = N % 60;

    TIME result;
    CreateTime(&result, HH, MM, SS);
    return result;
}

boolean TEQ (TIME T1, TIME T2){
    return (Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return !TEQ(T1, T2);
}

boolean TLT (TIME T1, TIME T2){
    boolean bin;
    if (Hour(T1) < Hour(T2)){
        bin = true;
    }else if (Hour(T1) > Hour(T2)){
        bin = false;
    }else{
        if (Minute(T1) < Minute(T2)){
            bin = true;
        }else if (Minute(T1) > Minute(T2)){
            bin = false;
        }else{
            if(Second(T1) < Second(T2)){
                bin = true;
            }else if(Second(T1) > Second(T2)){
                bin = false;
            }else{
                bin = false;
            }
        }
    }
    return bin;
}

boolean TGT (TIME T1, TIME T2){
    return TLT(T2, T1);
}

TIME NextDetik (TIME T){
    long second = TIMEToDetik(T);
    second = (second + 1) % 86400;
    return DetikToTIME(second);
}

TIME NextNDetik (TIME T, int N){
    long second = TIMEToDetik(T);
    second = (second + N) % 86400;
    return DetikToTIME(second);
}

TIME PrevDetik (TIME T){
    long second = TIMEToDetik(T);
    second = (second + 86399) % 86400;
    return DetikToTIME(second);
}

TIME PrevNDetik(TIME T, int N){
    long second = TIMEToDetik(T);
    second = (second + 86400 - N) % 86400;
    return DetikToTIME(second);
}

long Durasi(TIME Tawal, TIME Takhir){
    long Sawal = TIMEToDetik(Tawal);
    long Sakhir = TIMEToDetik(Takhir);
    if (Sawal <= Sakhir){
        return Sakhir-Sawal;
    }else{
        return 86400 - Sawal + Sakhir;
    }
}