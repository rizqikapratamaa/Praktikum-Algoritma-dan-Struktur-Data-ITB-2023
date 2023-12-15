#include "boolean.h"
#include "datetime.h"
#include <stdio.h>

boolean cekKabisat(int Y){
    if (Y % 400 == 0){
        return true;
    } else if ((Y % 400 != 0) && Y % 100 == 0){
        return false;
    } else if (Y % 400 != 0 && Y % 4 == 0){
        return true;
    } 

    return false;
}

int GetMaxDay(int M, int Y){
    if (M == 1 || 
        M == 3 || 
        M == 5 || 
        M == 7 || 
        M == 8 || 
        M == 10 || 
        M == 12) {
            return 31;
    } else if (M == 2) {
        if (cekKabisat(Y)){
            return 29;
        }

        return 28;
    }

    return 30;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    if (!IsTIMEValid(h, m, s)){
        return false;
    }

    return (
        (D>=0 && D<=GetMaxDay(M,Y)) &&
        (M>=0 && M <= 12) &&
        (Y >=1900 && Y<=2030)
    );
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;

    Hour(Time(*D)) = hh;
    Minute(Time(*D)) = mm;
    Second(Time(*D)) = ss;
}

void BacaDATETIME(DATETIME *D){
    int DD, MM, YY, h, m, s;

    scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);

    while (!IsDATETIMEValid(DD, MM, YY, h, m, s)){
        scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);
    }

    CreateDATETIME(D, DD, MM, YY, h, m, s);
}

void TulisDATETIME(DATETIME D){
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

boolean DEQ(DATETIME D1, DATETIME D2){
    return (
        Day(D1) == Day(D2) &&
        Month(D1) == Month(D2) && 
        Year(D1) == Year(D2) && 
        TEQ(Time(D1), Time(D2))
    );
}

boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2){
    if (Year(D1) < Year(D2)){
        return true;
    } else if (Year(D1) > Year(D2)){
        return false;
    }
    
    if (Month(D1) < Month(D2)){
        return true;
    } else if (Month(D1) > Month(D2)){
        return false;
    }
    
    if (Day(D1) < Day (D2)){
        return true;
    } else if (Day(D1) > Day(D2)){
        return false;
    }
    
    return TLT(Time(D1), Time(D2));
}

boolean DGT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)){
        return true;
    } else if (Year(D1) < Year(D2)){
        return false;
    }
    
    if (Month(D1) > Month(D2)){
        return true;
    } else if (Month(D1) < Month(D2)){
        return false;
    }
    
    if (Day(D1) > Day (D2)){
        return true;
    } else if (Day(D1) < Day(D2)){
        return false;
    }
    
    return TGT(Time(D1), Time(D2));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    long s;
    s = TIMEToDetik(Time(D));
    s += N;
    if (s >= 86400){
        Day(D) += floor(s/86400);
        s %= 86400;
        while (Day(D) > GetMaxDay(Month(D), Year(D))){
            Day(D) -= GetMaxDay(Month(D), Year(D));
            Month(D) += 1;
            if (Month(D) > 12){
                Year(D) += 1;
                Month(D) -= 12;
            }
        }
    }
    Time(D) = DetikToTIME(s);
    return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    long s;
    s = TIMEToDetik(Time(D));
    s -= N;
    if (s<0){
        Day(D) += floor(s/86400);
        s %= 86400;
        if (s < 0){
            Day(D) -= 1;
            s += 86400;
        } 
        while (Day(D) < 1){
            if (Month(D) == 1){
                Year(D) -= 1;
                Month(D) = 12;
            } else {
                Month(D) -= 1;
            }
            Day(D) += GetMaxDay(Month(D), Year(D));
        }
    }
    Time(D) = DetikToTIME(s);
    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    int DayAw = 0, DayAkh = 0;
    int i;

    for (i=1; i<Year(DAkh); i++) {
        if (i % 400 == 0) {
            DayAkh += 366;
        } else if (i % 100 == 0) {
            DayAkh += 355;
        } else if (i % 4 == 0) {
            DayAkh += 366;
        } else {
            DayAkh += 365;
        }
    }
    for (i=1; i<Month(DAkh); i++) {
        DayAkh += GetMaxDay(i,Year(DAkh));
    }
    DayAkh += Day(DAkh);
    for (i=1; i<Year(DAw); i++) {
        if (i % 400 == 0) {
            DayAw += 366;
        } else if (i % 100 == 0) {
            DayAw += 355;
        } else if (i % 4 == 0) {
            DayAw += 366;
        } else {
            DayAw += 365;
        }
    }
    for (i=1; i<Month(DAw); i++) {
        DayAw += GetMaxDay(i,Year(DAw));
    }
    DayAw += Day(DAw);

    return (DayAkh - DayAw) * 86400 + TIMEToDetik(Time(DAkh)) - TIMEToDetik(Time(DAw));
}