<div align="center">
    <h1>BurBir</h2>
    <p>Tugas Besar IF2110 Algoritma & Struktur Data</p>
    <p>oleh Kelompok H</p>
    <br/>
    <br/>
</div>

BurBir (Burung Biru) merupakan program berbasis CLI yang mensimulasikan sebuah media sosial. Mulanya program ini terinisiasi untuk membantu Ande-Ande Lumut yang iba saat mendengar kisah Klenting Kuning yang sedih karena dia dirundung oleh ibu tirinya dan saudara tirinya di Kuning Space. BurBir dibuat semirip mungkin dengan sosial media yang marak pada saat itu. 
Berdasarkan spesifikasi program, kami membuat program dengan 11 komponen diantaranya, yaitu inisiasi dari program BurBir, pembacaan perintah agar pengguna dapat berinteraksi dengan program CLI, pengguna dapat melakukan inisialisasi data pribadi pengguna, profil pengguna, melakukan pertemanan dengan pengguna lain, melakukan permintaan pertemanan, kicauan, membuat balasan, draf kicauan, membuat utas, dan melakukan simpan serta muat.  
Laporan mencakup deskripsi umum dari program BurBir, penjelasan tambahan spesifikasi tugas, penjelasan struktur data yang digunakan, penjelasan program utama, algoritma-algoritma menarik yang ditemukan saat membuat program, data-data dan script yang digunakan untuk menguji keberjalanan program BurBir, pembagian tugas, dan lampiran lainnya yang berisi deskripsi tugas besar, notulensi rapat, log activity tiap anggota kelompok dan lampiran lainnya.
Program dibuat menggunakan bahasa C dengan memanfaatkan ADT yang telah dipelajari pada mata kuliah IF2110 Algoritma dan Struktur Data Semester 3 Tahun 2023/2024. Program ini dimulai dengan menampilkan inisiasi dengan pengguna memasukkan input berupa nama folder konfigurasi untuk dimuat. Setelah berhasil dimuat, pengguna akan diminta untuk melakukan daftar jika belum mempunyai akun dan masuk jika sudah. Pengguna juga dapat melakukan keluar untuk melakukan logout. Setelah masuk, pengguna dapat memberikan perintah seperti melengkapi profil, membuat kicauan dan hal lain yang berhubungan dengan kicauan, membuat utas, bersosialisasi dengan teman dengan balasan, dan membuat draf. Hasil kelompok kami, program sudah dapat berjalan sesuai dengan spesifikasi.

## Cara kompilasi program

Pada terminal WSL, tuliskan command berikut di **folder utama** project ini, yaitu folder yang sama tempat **Makefile** berada.

```shell
$ make
```

**Note**: Gunakan Git Bash jika Anda menggukanan Sistem Operasi Windows

## Cara Menjalankan Program
Setelah dikompilasi, jalankan program dengan memanggil langsung *executables* melalui terminal dengan menulis

```shell
$ ./main
```

sebelum memanggil program, pastikan  *Current Working Directory* terminal berada di **folder utama** program.

 *Current Working Directory* terminal dapat dilihat dengan menulis

 ```shell
 $ cwd
 ```
 atau
 ```shell
 $ pwd
 ```

## Pembagian tugas
| NIM | Nama | Tugas |
| :---: | :---: | :---: |
| 13522134 | Shabrina Maharani | ADT datetime, ADT kicauan,driver kicauan, daftar, masuk, keluar. |
| 13522147 | Ikhwan Al Hakim | Implementasi word machine, ADT Utas, driver utas, empty utas, isi utas, cetak utas, sambung utas, hapus utas, merging dan fix semua fungsi ke main. |
| 13522152 | Muhammad Roihan | ADT matrix, driver profil, ganti profil, lihat profil, atur jenis akun, ubah foto profil |
| 13522159 | Rafif Ardhinto Ichwantoro | ADT Balasan, ADT draftkicau, driver Balasan, driver draftkicau. |
| 13522161 | Mohammad Akmal Ramadan | ADT graph, Makefile, driver teman, fungsi daftar teman, hapus teman, daftar permintaan pertemanan, dan setujui pertemanan |

## Daftar fitur
| Fitur | Status pengerjaan |
| :---: | :---: |
| Inisialisasi | Selesai |
| DAFTAR | Selesai |
| MASUK | Selesai |
| KELUAR | Selesai |
| TUTUP_PROGRAM | Selesai |
| GANTI_PROFIL | Selesai |
| LIHAT_PROFIL | Selesai |
| ATUR_JENIS_AKUN | Selesai |
| UBAH_FOTO_PROFIL | Selesai |
| DAFTAR_TEMAN | Selesai |
| HAPUS_TEMAN | Selesai |
| TAMBAH_TEMAN | Selesai |
| DAFTAR_PERMINTAAN_PERTEMANAN | Selesai |
| SETUJUI_PERTEMANAN | Setengah Selesai (Fungsi sudah benar, gagal diintegrasi) |
| KICAU | Selesai |
| KICAUAN | Selesai |
| SUKA_KICAUAN | Selesai |
| UBAH_KICAUAN | Selesai |
| BALAS | Selesai |
| BALASAN | Selesai |
| HAPUS_BALASAN | Selesai |
| BUAT_DRAF | Selesai |
| LIHAT_DRAF | Selesai |
| UTAS | Selesai |
| SAMBUNG_UTAS | Selesai |
| HAPUS_UTAS | Selesai |
| CETAK_UTAS | Selesai |
| SIMPAN | Selesai |
| MUAT | Selesai |
