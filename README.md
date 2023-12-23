# DOKUMENTACIJA  

 

Programski jezik: C++ 

Github repository: https://github.com/NejcSorgo/calc-app 

 

## 1.Prevei pravilnost vhodnih podatkov (sara veskovic)  

Vhodni podatki : niz  

### 1.1 Logična vrata 

    med vsako ključno besedo in številom mora bit presledek (razen v primeru npr (sqrt(10) ali pow(2,10) 

    Oklepaji se obravnavajo kot neki podniz , ki se posebej računa. 

    Vsak oklepaj ( mora imeti tudi par ) 

    Izračun velikost polja n 

    Uporabniško vnesen ali pridobljen glede na velikost v bitih največjega števila v nizu 

 

Primer vhodnih podatkov:  

10101 XOR 111 OR 10001 

NOT 10111 NOR 11111 XOR (10111 OR 1111) 

A4 AND B3 OR 2E (DD NOR 12) 

(NOT 95 AND 03) OR 25  

### 1.2 Aritmetika 

    Med vsako operacijo mora bit presledek 

    Oklepaji se obravnavajo kot neki podniz , ki se posebej računa. 

    Vsak oklepaj ( mora imeti tudi par ) 

    Funkcije (pow, sqrt)  

Primer vhodnih podatkov 

5 * 2 + 20 

(2 + 10) * (5 + 20)  

    Če je način računanja z logičnimi vrati prvo pretvori vsa števila v binarno obliko 

    Če je način računanja z aritmetiko pretvori števila v decimalni zapis 

 

 

## 2. Logika računanja (nejc šorgo) 

### 2.1 Pretvorba niza v obliko, ki razume računalnik 

    Vrstni red operacij 

    Oklepaji se obrovnavajo kot svoj podniz (rekurzivna funkcija) 

    Rekurzivna funkcija, ki lahko bere podnize 

    Uporaba funkcij iz 3. točke 

## 3. funkcije  (mark vidovič)  

### 3.1. za računanje logičnih vrat <ime_operacije> (a,b,n)  

n – velikost polja 

a – 1. Polje bitov 

b – 2. Polje bitov 

datoteka: operacije.cpp 

### 3.2 za pretvarjanje med številskimi sistemi 

    Desetiško  

    Osmiško 

    Binarno 

    Šestnajstiško 

datoteka: operacije.cpp 

 

## 4. GUI (grafični vmesnik) (nejc Šorgo, po možnosti še drugi) 

- gumb za spreminnjanje načina (aritmetični, logična vrata, pretvorba števila) 

- gumb za spreminjanje načina vnosa (bin,hex,oct,dec) 

- gumbi za vnos posamezne operacije (xor,not,or,and…) in oklepajev () 

- gumbi za vnos aritmetike (+,-,koren,/,*,%,potenciranje) 

- gumbi za rezultat ter brisanje podatkov 

datoteka:  vmesnik.cpp 
