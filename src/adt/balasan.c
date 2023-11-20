#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"

int countValuesInTree(Addresst node) {
    if (node == NULL) {
        return 0; // Jika pohon kosong, kembalikan 0
    }

    int count = 1; // Menghitung nilai pada node saat ini

    // Rekursif untuk menghitung nilai pada anak dan saudara
    count += countValuesInTree(node->firstChild);
    count += countValuesInTree(node->nextSibling);

    return count;
}



Addresst searchIdx(List t, int idbalasan) {
    Addresst root = t;
    root = firstChild(root);
    if (root == NULL) {
        return NULL;
    }

    // Cek apakah nilai pada node saat ini sama dengan targetValue
    if (value(root).id == idbalasan) {
        return root; // Jika sama, kembalikan alamat node
    }

    // Cari di anak pertama dan saudara berikutnya
    Addresst childAddress = searchIdx(firstChild(root), idbalasan);
    if (childAddress != NULL) {
        return childAddress; // Jika ditemukan di anak pertama, kembalikan alamat node
    }

    Addresst siblingAddress = searchIdx(nextSibling(root), idbalasan);
    return siblingAddress; // Kembalikan alamat node, mungkin NULL jika tidak ditemukan
}

void addBalasan(List *t, int id, Kicau kicauan){
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
        current = searchIdx(*t, id);
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

void deleteChild(List *t, int id) {
   Addresst p = searchIdx(*t, id);
   firstChild(p) = NULL;
   p = nextSibling(p);
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

void printtree(UserDB user,Pengguna currentPengguna,Graf teman, Addresst p, int idkicau, int depth)
{  
    if (p == NULL)
        return;

    // Print the current node
    boolean berteman;
    Pengguna pembuatBalasan;
    berteman = false;
    
    for (int j = 0; j < user.Neff; j++) {
        if(ceksama(user.db[j].nama, p->value.author)) {
            pembuatBalasan = user.db[j];
            break;
        }
    }
    if(cekteman(currentPengguna, pembuatBalasan, &user, teman)) {
            // printf("penggunanya %s\n", currentPengguna.nama.TabWord);
            // printf("authornya %s\n", pembuatKicau.nama.TabWord);
            berteman = true;
        }
    if ((cek(p->value.jakunkicau, "Publik") || (cek(p->value.jakunkicau, "Privat") && berteman))) {
        printf("%*s| ID = %d\n", depth * 3, "", p->value.id);
        printf("%*s| ", depth * 3, "" );
        for (int i = 0; i < p->value.author.Length; i++) {
            printf("%c", p->value.author.TabWord[i]);
        }
        printf("\n");
        printf("%*s| ", depth * 3, "" );
        for (int i = 0; i < p->value.date.Length; i++) {
            printf("%c", p->value.date.TabWord[i]);
        }
        printf("\n");
        printf("%*s| ", depth * 3, "" );
        for (int i = 0; i < p->value.text.Length; i++) {
            printf("%c", p->value.text.TabWord[i]);
        } 
    }else{
        printf("%*s| ID = %d\n", depth * 3, "", p->value.id);
        printf("%*s| PRIVAT\n", depth * 3, "");
        printf("%*s| PRIVAT\n", depth * 3, "");
        printf("%*s| PRIVAT\n", depth * 3, "");
    }
    // Recursively print the children and siblings
    printtree(user,currentPengguna,teman,p->firstChild,idkicau, depth += 1 );
    printtree(user,currentPengguna,teman,p->firstChild,idkicau, depth );

}

void Balas(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree kumpulantree,Graf teman, int idkicau, int idbalasan)
{
    Kicau newBalasan;
    List rootbalasan;
    boolean berteman = false;
    Pengguna currentPengguna;
    Pengguna pembuatKicau;
    if (!cek(currentUser, ";;;")) {
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            return;
        }
    for (int i = 0; i < user.Neff; i++) {
        if (ceksama(user.db[i].nama, currentUser)) {
            currentPengguna = user.db[i];
            break;
        }
    }
    int idx;
    for (int i = 0; i < kicau.nEff; i++) {
        if (kicau.buffer[i].id == idkicau) {
            idx = i;
            for (int j = 0; j < user.Neff; j++) {
                if(ceksama(user.db[j].nama, kicau.buffer[i].author)) {
                    pembuatKicau = user.db[j];
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
    if(!berteman){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
        return;
    }

    if(cektree(kumpulantree, idkicau)){
        rootbalasan = searchidxtree(kumpulantree, idkicau);
    }else{
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        return;
    }
    
    if (searchIdx(rootbalasan,idbalasan) == NULL){
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
    }else{
        Addresst kc = searchIdx(rootbalasan,idbalasan);
        Kicau kicauandibalas = kc->value;
        Pengguna pembuatBalasan;
        berteman = false;
        for (int j = 0; j < user.Neff; j++) {
                if(ceksama(user.db[j].nama, kicauandibalas.author)) {
                    pembuatBalasan = user.db[j];
                    break;
                }
        }
        if(cekteman(currentPengguna, pembuatBalasan, &user, teman)) {
            // printf("penggunanya %s\n", currentPengguna.nama.TabWord);
            // printf("authornya %s\n", pembuatKicau.nama.TabWord);
            berteman = true;
        }
        if ((cek(kicauandibalas.jakunkicau, "Publik") || (cek(kicauandibalas.jakunkicau, "Privat") && berteman))) {
            addBalasan(&rootbalasan, idbalasan, newBalasan);
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
                return;
            }else if(space){
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
                return;
            } else{
                int largestValue = 0;
                newBalasan.id = findLargestIdx(root(rootbalasan), &largestValue) + 1;
                newBalasan.text = text;
                newBalasan.like = 0;
                newBalasan.author = user.db[idx].nama;
                newBalasan.date = ctow(DateTimeToString(CurrentDatetime()));
                newBalasan.jakunkicau = user.db[idx].jakun;
                printf("Selamat! balasan telah diterbitkan!\n");
                printf("Detail balasan :\n");
                displaykicauan(newBalasan);
            }
        }else{
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        }

    }
}


void Balasan(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree kumpulantree, Graf teman, int idkicau)
{
    Pengguna currentPengguna;
    if (!cek(currentUser, ";;;")) {
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            return;
        }
    for (int i = 0; i < user.Neff; i++) {
        if (ceksama(user.db[i].nama, currentUser)) {
            currentPengguna = user.db[i];
            break;
        }
    }

    List rootbalasan;

    if(cektree(kumpulantree, idkicau)){
        rootbalasan = searchidxtree(kumpulantree, idkicau);
        Addresst p = rootbalasan;
        p = firstChild(p);
        printtree(user,currentPengguna,teman, p, idkicau, 0);
        
    }else{
        printf("id kicauan tidak ditemukan");
        return;
    }
}


void Hapus_Balasan(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree kumpulantree, int idkicau, int idbalasan)
{
    Pengguna currentPengguna;
    List rootbalasan;
    
    for (int i = 0; i < user.Neff; i++) {
        if (ceksama(user.db[i].nama, currentUser)) {
            currentPengguna = user.db[i];
            break;
        }
    }
    if(cektree(kumpulantree, idkicau)){
        rootbalasan = searchidxtree(kumpulantree, idkicau);
        if (searchIdx(rootbalasan,idbalasan) == NULL){
            printf("Balasan tidak ditemukan\n");
        }else{
            Addresst kc = searchIdx(rootbalasan,idbalasan);
            Kicau kicauandibalas = kc->value;
            Pengguna pembuatBalasan;
            for (int j = 0; j < user.Neff; j++) {
                    if(ceksama(user.db[j].nama, kicauandibalas.author)) {
                        pembuatBalasan = user.db[j];
                        break;
                    }
            }
            if(ceksama(pembuatBalasan.nama,currentPengguna.nama)){
                deleteChild(&rootbalasan, idkicau);
                printf("Balasan berhasil dihapus\n");
                if (countValuesInTree(rootbalasan) == 0){

                }
            } else{
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }

        }
    }else{
        printf("kicauan tidak ditemukan!\n");
    }
    
}