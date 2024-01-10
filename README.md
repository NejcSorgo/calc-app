# DOKUMENTACIJA  

Avtorji: Nejc Šorgo, Sara Veskovič, Mark Vidovič

Programski jezik: C++ 

## 1.Preveri pravilnost vhodnih podatkov (sara veskovic)  

Vhodni podatki : string input, int mode
Mode predstavlja način (aritmetika, logična vrata, tip številskega sistema)
Input pa vhodni niz, ki ga vpiše uporabnik

### 1.1 Logična vrata 

- med vsako ključno besedo in številom mora bit presledek (razen v primeru npr (sqrt(10) ali pow(2,10)
- Oklepaji se obravnavajo kot neki podniz , ki se posebej računa. 
- Vsak oklepaj ( mora imeti tudi par ) 
- Izračun velikost polja n 
- Uporabniško vnesen ali pridobljen glede na velikost v bitih največjega števila v nizu 

 

Primer vhodnih podatkov:  

    10101 XOR 111 OR 10001 

    NOT 10111 NOR 11111 XOR (10111 OR 1111) 

    A4 AND B3 OR 2E (DD NOR 12) 

    (NOT 95 AND 03) OR 25  

### 1.2 Aritmetika 

- Med vsako operacijo mora bit presledek 
- Oklepaji se obravnavajo kot neki podniz , ki se posebej računa. 
- Vsak oklepaj ( mora imeti tudi par ) 
   - Funkcije (pow, sqrt)  

Primer vhodnih podatkov:

    5 * 2 + 20 

    (2 + 10) * (5 + 20)  

- Če je način računanja z logičnimi vrati prvo pretvori vsa števila v binarno obliko 
- Če je način računanja z aritmetiko pretvori števila v decimalni zapis 

## 2. Logika računanja (nejc šorgo) 

### 2.1 Pretvorba niza v obliko, ki razume računalnik 
- Vrstni red operacij 
- Oklepaji se obrovnavajo kot svoj podniz (rekurzivna funkcija) 
- Rekurzivna funkcija, ki lahko bere podnize 
- Uporaba funkcij iz 3. točke 

Datoteka: validator.cpp
## 3. funkcije  (mark vidovič)  

### 3.1. za računanje logičnih vrat <ime_operacije> (a,b,n)  

n – velikost polja 

a – 1. Polje bitov 

b – 2. Polje bitov 

datoteka: operacije.cpp 

### 3.2 za pretvarjanje med številskimi sistemi string <ime_pretvorbe> (string input)
- Funkcija naj vrne niz, ki bo vseboval pretvorjena stevila.
- Prvo se števila pretvorijo v binarno
- Nato se iz binarnega lahko pretvori v katerikoli številski sistem (manj dela kot direktno prevajanje)
- Možna uporaba regex-a, ki ti poišče številke v nizu.
 #### Primer:
     string input = "5 XOR 4 AND ( 12 OR 15)";
     DecimalToBinary(input);
 ##### Naj vrne:
     101 XOR 100 AND (1100 OR 1111)
datoteka: pretvorbe.cpp 

## 4. GUI (grafični vmesnik) (nejc Šorgo, po možnosti še drugi) 

- gumb za spreminnjanje načina (aritmetični, logična vrata, pretvorba števila) 
- gumb za spreminjanje načina vnosa (bin,hex,oct,dec) 
- gumbi za vnos posamezne operacije (xor,not,or,and…) in oklepajev () 
- gumbi za vnos aritmetike (+,-,koren,/,*,%,potenciranje) 
- gumbi za rezultat ter brisanje podatkov 

datoteka:  vmesnik.cpp 
