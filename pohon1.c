/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 18 November 2026 */

#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E){ //representasi fisik fungsi
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}
 
/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree (bintree *P){
    //kamus lokal
    //algoritma
    if(*P != NIL){
        left(*P) = NIL;
        right(*P) = NIL;
        free(*P);
    }
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    //kamus lokal
    //algoritma
    if( P != NIL){
        return left(P);
    }
    else{
        return NIL;
    }
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //kamus lokal
    //algoritma
    if( P != NIL){
        return right(P);
    }
    else{
        return NIL;
    }
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    //kamus lokal
    //algoritma
    return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)) {
        return ((right(P) == NIL) && (left(P) == NIL));
    }
    else{
        return false;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return ((right(P) != NIL) && (left(P) != NIL));
    }
    else{
        return false;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return ((right(P) == NIL) && (left(P) != NIL));
    }
    else{
        return false;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        return ((right(P) != NIL) && (left(P) == NIL));
    }
    else{
        return false;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    //kamus lokal
    //algoritma
    if( !IsEmptyTree(P) ){
        return (1 + NbElm(left(P)) + NbElm(right(P)));
    }
    else{
        return 0;
    } 
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        if (IsDaun(P)){
            return 1;
        }
        else {
            return (NbDaun(left(P)) + NbDaun(right(P)));
        } 
    }
    else{
        return 0;
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    //kamus lokal
    //algoritma
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P){
    //kamus lokal
    int tinggi;
    //algoritma
    tinggi = -1; // default bila pohon kosong
    if(!IsEmptyTree(P)){
        if(IsDaun(P)){
            tinggi = 0;
        }
        else {
            tinggi = 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
        }
    }
    return tinggi;
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    //kamus lokal
    boolean find;
    //algoritma
    find = false;
    if(!IsEmptyTree(P)){
        if(info(P) == X){
            find = true;
        }
        else{
            find = (SearchX(left(P), X) || SearchX(right(P), X));
        }
    }
    return find;
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(*P)){
        if(info(*P) == X){
            info(*P) = Y;
        }
        UpdateX(&(left(*P)), X, Y);
        UpdateX(&(right(*P)), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    //kamus lokal
    int count;
    //algoritma
    count = 0;
    if(!IsEmptyTree(P)){
        if(info(P) == X){
            count = 1 + CountX(left(P), X) + CountX(right(P), X);
        }
        else{
            count = CountX(left(P), X) + CountX(right(P), X);
        }
    }
    return count;
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)){
        if (IsDaun(P)){
            return true;
        }
        else{
            return (IsUnerLeft(P) && IsSkewLeft(left(P)));
        }
    }
    else{
        return false;
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)){
        if (IsDaun(P)){
            return true;
        }
        else{
            return (IsUnerRight(P) && IsSkewRight(right(P)));
        }
    }
    else{
        return false;
    }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P){
    //kamus lokal
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c",info(P));
        if(!IsDaun(P)){
            printf("(");
            PrintPrefixRingkas(left(P));
            printf(",");
            PrintPrefixRingkas(right(P));
            printf(")");
        }
    }   
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    //kamus lokal
    int level;
    //algoritma
    level = 0;
    if(!IsEmptyTree(P)){
        if(info(P) == X){
            level = 1;
        }
        else{
            if(SearchX(left(P), X)){
                level = 1 + LevelX(left(P), X);
            }
            else if(SearchX(right(P), X)){
                level = 1 + LevelX(right(P), X);
            }
        }
    }
    return level;
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T){
    //kamus lokal
    int count;
    //algoritma
    count = 0;
    if(!IsEmptyTree(P)){
        if(T == 1){
            count = 1;
        }
        else if(T > 1){
            count = CountLevel(left(P), T-1) + CountLevel(right(P), T-1);
        }
    }
    return count;
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        if(N == 1){
            printf("%c ", info(P));
        }
        else if(N > 1){
            PrintLevel(left(P), N-1);
            PrintLevel(right(P), N-1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        if(IsDaun(P)){
            return info(P);
        }
        else{
            if(left(P) != NIL){
                return GetDaunTerkiri(left(P));
            }
            else{
                return GetDaunTerkiri(right(P));
            }
        }
    }
    return '#';
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X){
    //kamus lokal
    float frekuensi;
    //algoritma
    frekuensi = 0.0;
    if(!IsEmptyTree(P)){
        frekuensi = (float)CountX(P, X) / (float)NbElm(P);
    }
    return frekuensi;
}

/*function IsVocal(c:character) -> boolean */
/*{Mengembalikan true jika c adalah huruf vokal}*/
boolean IsVocal(char c){
    //kamus lokal
    //algoritma
    if ((c == 'a') || (c == 'A') || 
        (c == 'i') || (c == 'I') || 
        (c == 'u') || (c == 'U') || 
        (c == 'e') || (c == 'E') || 
        (c == 'o') || (c == 'O')) {
        return true;
    } else {
        return false;
    }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P){
    //kamus lokal
    int count;
    //algoritma
    count = 0;
    if(!IsEmptyTree(P)) {
        if(IsVocal(info(P))){
            count = 1 + CountVocal(left(P)) + CountVocal(right(P));
        }
        else{
            count = CountVocal(left(P)) + CountVocal(right(P));
        }
    }
    return count;
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        if(IsVocal(info(P))){
            printf(" %c |", info(P));
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P){
    //kamus lokal
    int count;
    //algoritma
    count = 0;
    if(!IsEmptyTree(P)){
        if(!IsVocal(info(P))){
            count = 1 + CountConsonant(left(P)) + CountConsonant(right(P));
        } else {
            count = CountConsonant(left(P)) + CountConsonant(right(P));
        }
    }
    return count;
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P){
    //kamus lokal
    //algoritma
    if(!IsEmptyTree(P)){
        if(!IsVocal(info(P))){
            printf(" %c |", info(P));
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*procedure CariModus(input P:bintree, input root:bintree, input/output modus:char, input/output maks:int)*/
/*{ Proses: menelusuri semua node P untuk mencari karakter dengan kemunculan terbanyak pada root }*/
void CariModus(bintree P, bintree root, char *modus, int *maks){
    //kamus lokal
    int c;
    //algoritma
    if(!IsEmptyTree(P)){
        c = CountX(root, info(P));
        if(c > *maks){
            *maks = c;
            *modus = info(P);
        }
        CariModus(left(P), root, modus, maks);
        CariModus(right(P), root, modus, maks);
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    //kamus lokal
    char modus;
    int maks;
    //algoritma
    modus = '#'; // default bila pohon kosong
    maks = 0;
    if(!IsEmptyTree(P)){
        CariModus(P, P, &modus, &maks);
    }
    return modus;
}
