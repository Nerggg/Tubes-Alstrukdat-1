#include <stdio.h>
#include "balasan.h"
#include "../feat/operational.c"
#include "../feat/io.c"

Addresst newNodet(Kicau val) {
    Addresst p = (Addresst)malloc(sizeof(Tree));
    if (p == NULL) {
        // Handle memory allocation error
        exit(1);
    }
    value(p) = val;
    firstChild(p) = NULL;
    nextSibling(p) = NULL;
    return p;
}

void CreateListoftree(ListDintree *l, int capacity)
{
    BUFFER(*l) = (List *) malloc(capacity * sizeof(List));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocatelistoftree(ListDintree *l)
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

void insertLasttree(ListDintree *l, List newtree)
{
    ELMT(*l, NEFF(*l)) = newtree;
    NEFF(*l)++;
}

void deleteLasttree(ListDintree *l, List *lastree)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *lastree = ELMT(*l, NEFF(*l));
    NEFF(*l)--;
}

List searchidxtree(ListDintree l, int id)
{
    int i;
    List target;
    for (i = 0; i < NEFF(l);i++){
        if (i+1 == id){
            target = ELMT(l,i);
        }
    }
    return target;
}
boolean cektree(ListDintree l, int id)
{
    int i;
    List target;
    for (i = 0; i < NEFF(l);i++){
        if (i+1 == id){
            return true;
        }
    }
    return false;
}

void CreateTree(List *t) {
    *t = NULL;
}


void deleteChild(List *t, int id) {
   Addresst p = searchIdx(*t, id);
   firstChild(p) = NULL;
   p = nextSibling(p);
}



Addresst searchIdx(List t, int idbalasan) {
    Addresst root = t;
    root = firstChild(root);
    if (root == NULL) {
        return IDX_UNDEF;
    }

    // Cek apakah nilai pada node saat ini sama dengan targetValue
    if (value(root).id == idbalasan) {
        return root; // Jika sama, kembalikan alamat node
    }

    // Cari di anak pertama dan saudara berikutnya
    Addresst childAddress = searchIdx(firstChild(root), idbalasan);
    if (childAddress != IDX_UNDEF) {
        return childAddress; // Jika ditemukan di anak pertama, kembalikan alamat node
    }

    Addresst siblingAddress = searchIdx(nextSibling(root), idbalasan);
    return siblingAddress; // Kembalikan alamat node, mungkin NULL jika tidak ditemukan
}

void AddBalasan(List *t, int id, Kicau kicauan){
    Addresst p = newNodet(kicauan);
    Addresst current;
    if (id == -1){
        Addresst current = *t;
        if (firstChild(current) == NULL){
            firstChild(current) = p;
        }else{
            current = firstChild(current);
            while(nextSibling(current) != NULL){
                current = nextSibling(current);
            }
            nextSibling(current) = p;
        }
    }else{
        current = searchIdx(t, id);
        if (firstChild(current) == NULL){
            firstChild(current) = p;
        }else{
            current = firstChild(current);
            while(nextSibling(current) != NULL){
                current = nextSibling(current);
            }
            nextSibling(current) = p;
        }
    }
}

int findLargestIdx(List t, int *largestValue) {
    Addresst root = t;
    root = firstChild(root);
    if (root == NULL) {
        return IDX_UNDEF;
    }

    int currentIndex = value(root).id;
    *largestValue = currentIndex;

    // Cek anak pertama
    int childIdx = findLargestIdx(firstChild(root), largestValue);

    // Cek saudara berikutnya
    int siblingIdx = findLargestIdx(nextSibling(root), largestValue);

    // Bandingkan dengan indeks anak pertama dan saudara berikutnya
    if (childIdx != IDX_UNDEF && currentIndex < *largestValue) {
        currentIndex = childIdx;
    }
    if (siblingIdx != IDX_UNDEF && currentIndex < *largestValue) {
        currentIndex = siblingIdx;
    }

    return currentIndex;
}


void Balas(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree,Graf teman, int idkicau, int idbalasan)
{
    int i;
    Kicau newBalasan;
    List rootbalasan;
    boolean ada = false;
    boolean berteman = false;
    Pengguna currentPengguna;
    Pengguna pembuatKicau;
    if (!cek(*currentUser, ";;;")) {
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            return;
        }
    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(user->db[i].nama, *currentUser)) {
            currentPengguna = user->db[i];
            break;
        }
    }
    int idx;
    for (int i = 0; i < kicau->nEff; i++) {
        if (kicau->buffer[i].id == idkicau) {
            ada = true;
            idx = i;
            for (int j = 0; j < user->Neff; j++) {
                if(ceksama(user->db[j].nama, kicau->buffer[i].author)) {
                    pembuatKicau = user->db[j];
                    break;
                }
            }
            break;
        }
    }
    if(cekteman(currentPengguna, pembuatKicau, &user, teman)) {
        // printf("penggunanya %s\n", currentPengguna.nama.TabWord);
        // printf("authornya %s\n", pembuatKicau.nama.TabWord);
        berteman = true;
    }
    if ((cek(kicau->buffer[idx].jakunkicau, "Publik") || (cek(kicau->buffer[idx].jakunkicau, "Privat") && berteman))) {
        
    }

    if(cektree(*kumpulantree, idkicau)){
        rootbalasan = searchidxtree(*kumpulantree, idkicau);

        
    }else{
        printf("id kicauan tidak ditemukan");
        return;
    }
    
    if (searchIdx(rootbalasan,idbalasan) == IDX_UNDEF){
        print("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
    }else{
        Addresst kc = searchIdx(rootbalasan,idbalasan);
        Kicau kicauandibalas = kc->value;
        Pengguna pembuatBalasan;
        berteman = false;
        for (int j = 0; j < user->Neff; j++) {
                if(ceksama(user->db[j].nama, kicauandibalas.author)) {
                    pembuatBalasan = user->db[j];
                    break;
                }
        }
        if(cekteman(currentPengguna, pembuatBalasan, &user, teman)) {
            // printf("penggunanya %s\n", currentPengguna.nama.TabWord);
            // printf("authornya %s\n", pembuatKicau.nama.TabWord);
            berteman = true;
        }
        if(berteman){
            AddBalasan(&rootbalasan, idbalasan, newBalasan);
            Word text;
            printf("Masukan balasan : ");
            text = bacakalimat();
            boolean space = true;
            for (int i = 0; i < text.Length; i++) {
                if (text.TabWord[i] != ' ') {
                    space = false;
                    break;
                }
            }

            if (text.Length > 280) {
                printf("Balasan tidak boleh lebih dari 280 karakter! Kicauan Anda akan terpotong secara otomatis.\n");
            }else if(space){
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
            } else{
                int largestValue = 0;
                newBalasan.id = findLargestIdx(root(rootbalasan), largestValue) + 1;
                newBalasan.text = text;
                newBalasan.like = 0;
                newBalasan.author = user->db[idx].nama;
                newBalasan.date = ctow(DateTimeToString(CurrentDatetime()));
                newBalasan.jakunkicau = user->db[idx].jakun;
                printf("Selamat! balasan telah diterbitkan!\n");
                printf("Detail balasan :\n");
                displaykicauan(newBalasan);
            }
        }else{
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
        }

    }
    
    

    
    
}


void Balasan(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree, int idkicau)
{
    
    List rootbalasan;
    if(cektree(*kumpulantree, idkicau)){
        rootbalasan = searchidxtree(*kumpulantree, idkicau);

        
    }else{
        printf("id kicauan tidak ditemukan");
        return;
    }
}


void Hapus_Balasan(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree, int idkicau, int idbalasan)
{
    Pengguna currentPengguna;
    List rootbalasan;
    boolean ada = false;
    boolean berteman = false;
    
    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(user->db[i].nama, *currentUser)) {
            currentPengguna = user->db[i];
            break;
        }
    }
    if(cektree(*kumpulantree, idkicau)){
        rootbalasan = searchidxtree(*kumpulantree, idkicau);
        if (searchIdx(rootbalasan,idbalasan) == IDX_UNDEF){
            print("Balasan tidak ditemukan\n");
        }else{
            Addresst kc = searchIdx(rootbalasan,idbalasan);
            Kicau kicauandibalas = kc->value;
            Pengguna pembuatBalasan;
            berteman = false;
            for (int j = 0; j < user->Neff; j++) {
                    if(ceksama(user->db[j].nama, kicauandibalas.author)) {
                        pembuatBalasan = user->db[j];
                        break;
                    }
            }
            if(ceksama(pembuatBalasan.nama,currentPengguna.nama)){
                deleteChild(&rootbalasan, idkicau);
                printf("Balasan berhasil dihapus\n");
            } else{
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }

        }
    }else{
        printf("kicauan tidak ditemukan!\n");
    }
    
}