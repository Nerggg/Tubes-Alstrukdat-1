#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    for(int i=0;i<nRows;i++){
        for(int j =0;j<nCols;j++){
            MATELMT(*m,i,j) = 0;
        }
    }
}


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i>=0 && i<ROW_CAP) && (j>=0 && j<COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return ROW_EFF(m)-1;
}
IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return COL_EFF(m)-1;
}
boolean isIdxEffMat(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{ 
    return (i>=0 && i<ROW_EFF(m)) && (j>=0 && j<COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    return MATELMT(m,i,i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrix(ROW_EFF(mIn),COL_EFF(mIn),mOut);
    for(int i=0;i<ROW_EFF(*mOut);i++){
        for(int j=0;j<COL_EFF(*mOut);j++){
            MATELMT(*mOut,i,j) = MATELMT(mIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    createMatrix(nRow,nCol,m);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            int x;
            scanf("%d",&x);
            MATELMT(*m,i,j) = x;
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for(int i=0;i<ROW_EFF(m);i++){
        for(int j=0;j<COL_EFF(m);j++){
            printf("%d",MATELMT(m,i,j));
            if(j!=COL_EFF(m)-1){
                printf(" ");
            }
        }
        if(i!=ROW_EFF(m)-1){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix m3;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            MATELMT(m3,i,j) = MATELMT(m1,i,j) + MATELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix m3;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            MATELMT(m3,i,j) = MATELMT(m1,i,j) - MATELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix m3;
    createMatrix(ROW_EFF(m1),COL_EFF(m2),&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            int temp =0;
            for(int k=0;k<COL_EFF(m1);k++){
                temp += MATELMT(m1,i,k) * MATELMT(m2,k,j);
            }
            MATELMT(m3,i,j) = temp;
        }
    }
    return m3;
}
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
{
    Matrix m3;
    createMatrix(ROW_EFF(m1),COL_EFF(m2),&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            int temp =0;
            for(int k=0;k<COL_EFF(m1);k++){
                temp += (MATELMT(m1,i,k) * MATELMT(m2,k,j));
            }
            MATELMT(m3,i,j) = temp%mod;
        }
    }
    return m3;
}
Matrix multiplyByConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix m3;
    copyMatrix(m,&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            MATELMT(m3,i,j)*= x;
        }
    }
    return m3;
}
void pMultiplyByConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    for(int i=0;i<ROW_EFF(*m);i++){
        for(int j=0;j<COL_EFF(*m);j++){
            MATELMT(*m,i,j)*= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    boolean cek = true;
    if(countElmt(m1) == countElmt(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)){
        for(int i=0;i<ROW_EFF(m1);i++){
            for(int j=0;j<COL_EFF(m1);j++){
                if(MATELMT(m1,i,j) != MATELMT(m2,i,j)){
                    cek = false;
                }
            }
        }
        return cek;
    }
    else{
        return false;
    }
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !isMatrixEqual(m1,m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    boolean cek = true;
    if(isSquare(m)){
        for(int i=0;i<ROW_EFF(m);i++){
            for(int j=0;j<COL_EFF(m);j++){
                if(MATELMT(m,i,j) != MATELMT(m,j,i)){
                    cek = false;
                }
            }
        }
        return cek;
    }
    else{
        return false;
    }
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    boolean cek = true;
    for(int i=0;i<ROW_EFF(m);i++){
        for(int j=0;j<COL_EFF(m);j++){
            if(i==j){
                if(MATELMT(m,i,j)!=1){
                    cek = false;
                }
            }
            else{
                if(MATELMT(m,i,j)!=0){
                    cek = false;
                }
            }
        }
    }
    return cek;
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int max = 5*countElmt(m)/100;
    int cnt = 0;
    for(int i=0;i<ROW_EFF(m);i++){
        for(int j=0;j<COL_EFF(m);j++){
            if(MATELMT(m,i,j) != 0){
                cnt ++;
            }
        }
    }
    return cnt <= max;
}
Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    return multiplyByConst(m,-1);
}
void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    pMultiplyByConst(m,-1);
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
   int n = getLastIdxRow(m) + 1;
   int tmpRow[11];
   int i, j, k, idx, temp1, temp2;
   int det = 1;
   int co = 1;
   for(i = 0; i < n; i++){
      idx = i;
      while(MATELMT(m,idx,i) == 0 && idx < n){
         idx++;
      }
      if (idx == n){
         return 0;
      }
      if (i != idx){
         for(j = 0; j < n; j++){
            ElType temp;
            temp = MATELMT(m, idx, j);
            MATELMT(m, idx, j) = MATELMT(m, i, j);
            MATELMT(m, i, j) = temp;
         }
         det *= -1;
      }
      for(j = 0;j<n;j++){
         tmpRow[j] = MATELMT(m,i,j);
      }
      for (j=i+1; j<n; j++){
         temp1 = tmpRow[i];
         temp2 = MATELMT(m,j,i);
         for(k=0;k<n;k++){
            MATELMT(m,j,k) = ((temp1 * MATELMT(m,j,k)) - (temp2 * tmpRow[k]));
         }
         co *= temp1;
      }
   }
   for(i=0;i<n;i++){
      det *= MATELMT(m,i,i);
   }
   return det/co;
}
Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix m3;
    createMatrix(ROW_EFF(m),COL_EFF(m),&m3);
    for(int i=0;i<ROW_EFF(m3);i++){
        for(int j=0;j<COL_EFF(m3);j++){
            MATELMT(m3,i,j) = MATELMT(m,j,i);
        }
    }
    return m3;
}
void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix tmp;
    copyMatrix(*m,&tmp);
    for(int i=0;i<ROW_EFF(*m);i++){
        for(int j=0;j<COL_EFF(*m);j++){
            MATELMT(*m,i,j) = MATELMT(tmp,j,i);
        }
    }
}
