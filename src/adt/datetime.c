//Shabrina Maharani 13522134

#include <stdio.h>
#include <math.h>
#include "time.h"
#include "datetime.h"
#include <time.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */
{
    if(M%2 == 1){
        if (M<8){
            return 31;
        } else{
            return 30;
        }
    }

    if (M != 2){
        if (M < 7) {
            return 30;
        }else{
            return 31;
        }
    }

    if (Y % 400 == 0) {
        return 29;
    }

    if (Y % 100 == 0) {
        return 28;
    }

    if (Y % 4 == 0) {
        return 29;
    }
    return 28;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
{
    if (M<1 || M>12) {
        return false;
    }
    if (Y<0) {
        return false;
    }
    if (D<1 || D > GetMaxDay(M,Y)) {
        return false;
    }
    if (!IsTIMEValid(h,m,s)) {
        return false;
    }
    return true;
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
{
    Day(*D)= DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Hour(D->T) = hh;
    Minute(D->T) = mm;
    Second(D->T) = ss;
    /*atau bisa juga 
    CreateTime (&t, hh,mm,ss);
    Time(*D)= t*/
}


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
{
    int DD,MM,YYYY,hh,mm,ss;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)){
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }
    CreateDATETIME(D, DD,MM,YYYY,hh,mm,ss);
}

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1=D2, false jika tidak */
{
    return((Day(D1)==Day(D2))&&(Month(D1)==Month(D2))&&(Year(D1)==Year(D2))&&(Hour(Time(D1))==Hour(Time(D2)))&&(Minute(Time(D1))==Minute(Time(D2)))&&(Second(Time(D1))==Second(Time(D2))));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1 tidak sama dengan D2 */
{
    return(!DEQ(D1, D2));
}

boolean DLT(DATETIME D1, DATETIME D2) {
    if (Year(D1) < Year(D2)) {
        return true;
    } else if (Year(D1) == Year(D2)) {
        if (Month(D1) < Month(D2)) {
            return true;
        } else if (Month(D1) == Month(D2)) {
            if (Day(D1) < Day(D2)) {
                return true;
            } else if (Day(D1) == Day(D2)) {
                if (TLT(Time(D1),Time(D2))) {
                    return true;
                }
            }
        }
    }
    return false;
}
boolean DGT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)) {
        return true;
    } else if (Year(D1) == Year(D2)) {
        if (Month(D1) > Month(D2)) {
            return true;
        } else if (Month(D1) == Month(D2)) {
            if (Day(D1) > Day(D2)) {
                return true;
            } else if (Day(D1) == Day(D2)) {
                if (TGT(Time(D1),Time(D2))) {
                    return true;
                }
            }
        }
    }
    return false;
}


DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    long SECOND;
    SECOND = TIMEToDetik(Time(D));
    SECOND = SECOND + N;
    if (SECOND >= 86400){
        Day(D) = Day(D) + floor(SECOND/86400);
        SECOND = SECOND % 86400;
        while (Day(D) > GetMaxDay(Month(D), Year(D))){
            Day(D) = Day(D)- GetMaxDay(Month(D), Year(D));
            Month(D) = Month(D)+ 1;
            if (Month(D) > 12){
                Year(D) += 1;
                Month(D) -= 12;
            }
        }
    }
    Time(D) = DetikToTIME(SECOND);
    return D;
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    long SECOND;
    SECOND = TIMEToDetik(Time(D));
    SECOND -= N;
    if (SECOND<0){
        Day(D) = Day(D) + floor(SECOND/86400);
        SECOND %= 86400;
        if (SECOND < 0){
            Day(D) = Day(D) - 1;
            SECOND += 86400;
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
    Time(D) = DetikToTIME(SECOND);
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

DATETIME CurrentDatetime() {
    DATETIME currentDatetime;
    time_t timestamp;
    struct tm *Infotime;

    time(&timestamp);
    Infotime = localtime(&timestamp);

    currentDatetime.DD = Infotime->tm_mday;
    currentDatetime.MM = Infotime->tm_mon + 1; // tm_mon mulai dari 0
    currentDatetime.YYYY = Infotime->tm_year + 1900; // 
    currentDatetime.T.HH = Infotime->tm_hour;
    currentDatetime.T.MM = Infotime->tm_min;
    currentDatetime.T.SS = Infotime->tm_sec;

    return currentDatetime;
}

char *DateTimeToString(DATETIME datetime) {
    static char result[20]; 
    
    // Format tanggal
    sprintf(result, "%02d/%02d/%04d %02d:%02d:%02d",
            DAY(datetime), Month(datetime), Year(datetime),
            Time(datetime));

    return result;
}



 



