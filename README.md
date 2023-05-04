# OBJ2023Q2
PROGRAMOS PALEIDIMAS (nuo v1.1)
1. Į pasirinktą kompiuterio direktoriją įkelkite source (programos kodo failai) ir data (duomenu failai) direktorijas
NOTE! programa neveiks, jei nebus laikomasi numatytos failų struktūros
3. Atidarykite source direktoriją naudojant terminalą 
2. Komandinėje eilutėje įveskite: make 
(bus naudojamas O3 optimizavimo flag'as, norėdami jį pakeisti veskite: make OPT=<optimizavimo vėliavėlė (pvz. O2 ar O1)>)
3. Kai programa bus paruošta naudoti, paleiskite ją į komandinę eilutę įvedę: ./program
4. Naudokitės programa
_________________________________
PALYGINIMAS v1.0 VS v1.1

*v1.1 TESTAVIMO REZULTATAI (vektorius, naudojant viena papildoma konteineri, vidurkis, 7 paz.)*
| FAILAS |studentai100000.txt|studentai1000000.txt|
| --- | - | - |
| NUSKAITYMAS |0.152425 s. |1.73667 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0876523 s. |1.04264 s. |
| RUSIAVIMAS I DVI GRUPES |0.0157844 s. |0.143365 s. |
| FAILO LAIKAS |0.360032 s. |3.86091 s. |

*v1.0 TESTAVIMO REZULTATAI (vektorius, naudojant viena papildoma konteineri, pagerinta strategija, vidurkis, 7 paz.)*
| FAILAS |studentai100000.txt|studentai1000000.txt|
| --- | - | - |
| NUSKAITYMAS |0.166575 s. |1.85288 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0385877 s. |0.435087 s. |
| RUSIAVIMAS I DVI GRUPES |0.0147071 s. |0.122744 s. |
| FAILO LAIKAS |0.344409 s. |3.62993 s. |

Išvados:
Bendras laikas nežymiai pablogėjo perėjus prie klasių, didžiausias našumo skirtumas matomas studentų rūšiavime pagal pavardes.
*****************************
OPTIMIZAVIMO FLAG'Ų TESTAVIMAS

*v1.1 TESTAVIMO REZULTATAI (vektorius, naudojant viena papildoma konteineri, vidurkis, 7 paz., studentai1000000.txt)*
| FLAG |O1|O2|O3|
| --- | - | - | - |
| .exe DYDIS | 327KB | 305KB | 315KB |
| NUSKAITYMAS |1.71352 s. |1.59184 s. |1.59888 s. |
| RUSIAVIMAS PAGAL PAVARDES |1.07885 s. |1.04279 s. |1.20678 s. |
| RUSIAVIMAS I DVI GRUPES |0.147452 s. |0.144691 s. |0.152278 s. |
| FAILO LAIKAS |3.92889 s. |3.87678 s. |3.94755 s. |

Išvados:
1. Mažiausiai vietos paleidžiamasis failas užima naudojant O2 flag'ą
2. Daugiausiai vietos paleidžiamasis failas užima naudojant O1 flag'ą
3. Sparčiausiai programa veikia naudojant O2 flag'ą
_____________________________
PROGRAMOS PALEIDIMAS (nuo v1.0)
1. Į pasirinktą kompiuterio aplankalą sukelkite (main.cpp, funkcijos.cpp, header.h,  names18239.txt, surnames29638.txt)
2. Komandinėje eilutėje įveskite: make
3. Kai programa paruošta naudoti, paleiskite ją į komandinę eilutę įvedę: ./program
4. Naudokitės programa
_____________________________
VERSIJA v1.0
Sukurtos universalios funkcijos, kurios gali priimti, bet kurį konteinerį (vektorių, deką arba listą), todėl nebereikia 3 skirtingų rinkinių failų. Vartotojas programos veikimo metu pasirenka reikiamą konteinerį ir vieną iš trijų studentų dalinimo strategijų:
1. Nenaudojant papildomų konteinerių (informacija iškarto rašoma į buferį)
2. Naudojant vieną papildomą konteinerį 
3. Naudojant du papildomus konteinerius

***********************************

*v1.0 TESTAVIMO REZULTATAI (vektorius, nenaudojant papildomu konteineriu, vidurkis, 7 paz., RAM: 5000MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.002711 s. |0.0256903 s. |0.236511 s. |2.34629 s. |24.0425 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0010832 s. |0.013549 s. |0.155108 s. |1.76191 s. |21.1119 s. |
| RUSIAVIMAS I DVI GRUPES |0.001173 s. |0.0116766 s. |0.112392 s. |1.11198 s. |11.6153 s. |
| FAILO LAIKAS |0.010018 s. |0.0617356 s. |0.569372 s. |5.86909 s. |64.3527 s. |

*v1.0 TESTAVIMO REZULTATAI (vektorius, naudojant viena papildoma konteineri, pagerinta strategija, vidurkis, 7 paz., RAM: 5500MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0027028 s. |0.0246782 s. |0.235441 s. |2.41123 s. |24.1556 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0010948 s. |0.0137417 s. |0.158222 s. |1.80779 s. |22.9682 s. |
| RUSIAVIMAS I DVI GRUPES |0.0003307 s. |0.0037327 s. |0.0365803 s. |0.36683 s. |3.64902 s. |
| FAILO LAIKAS |0.0101636 s. |0.0627191 s. |0.590514 s. |6.29908 s. |68.2113 s. |

*v1.0 TESTAVIMO REZULTATAI (vektorius, naudojant du papildomus konteinerius, vidurkis, 7 paz., RAM: 6500MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0027168 s. |0.0247762 s. |0.238573 s. |2.40177 s. |23.843 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0011302 s. |0.0144303 s. |0.165251 s. |1.90092 s. |22.9887 s. |
| RUSIAVIMAS I DVI GRUPES |0.0005123 s. |0.0053064 s. |0.0451304 s. |0.478523 s. |4.47791 s. |
| FAILO LAIKAS |0.0106038 s. |0.0656555 s. |0.619349 s. |6.52326 s. |70.1516 s. |

***************************

*v1.0 TESTAVIMO REZULTATAI (dekas, nenaudojant papildomu konteineriu, vidurkis, 7 paz., RAM: 5300MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0026373 s. |0.0237971 s. |0.231607 s. |2.41507 s. |23.8084 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0014139 s. |0.017793 s. |0.208574 s. |2.40068 s. |29.0722 s. |
| RUSIAVIMAS I DVI GRUPES |0.0012658 s. |0.0120928 s. |0.120148 s. |1.18774 s. |11.8951 s. |
| FAILO LAIKAS |0.010292 s. |0.0655554 s. |0.640666 s. |6.81638 s. |74.1603 s. |

*v1.0 TESTAVIMO REZULTATAI (dekas, naudojant viena papildoma konteineri, pagerinta strategija, vidurkis, 7 paz., RAM: 5500MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0026651 s. |0.0241406 s. |0.247151 s. |2.41402 s. |23.558 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0014996 s. |0.0179691 s. |0.206546 s. |2.41671 s. |29.0089 s. |
| RUSIAVIMAS I DVI GRUPES |0.0003385 s. |0.0033307 s. |0.0413612 s. |0.437471 s. |4.3521 s. |
| FAILO LAIKAS |0.0108876 s. |0.0676111 s. |0.67856 s. |7.17366 s. |76.7392 s. |

*v1.0 TESTAVIMO REZULTATAI (dekas, naudojant du papildomus konteinerius, vidurkis, 7 paz., RAM: 6800MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.002622 s. |0.0240976 s. |0.232044 s. |2.44299 s. |23.7803 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0013589 s. |0.0181076 s. |0.213089 s. |2.42047 s. |29.1033 s. |
| RUSIAVIMAS I DVI GRUPES |0.00035 s. |0.0040051 s. |0.0386529 s. |0.390516 s. |3.85883 s. |
| FAILO LAIKAS |0.0100745 s. |0.0700448 s. |0.68011 s. |7.31668 s. |78.9355 s. |

**************************

*v1.0 TESTAVIMO REZULTATAI (listas, nenaudojant papildomu konteineriu, vidurkis, 7 paz., RAM: 5800MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0030801 s. |0.0243499 s. |0.241793 s. |2.48634 s. |24.9044 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0003329 s. |0.0050072 s. |0.0757148 s. |1.0495 s. |15.6227 s. |
| RUSIAVIMAS I DVI GRUPES |0.001408 s. |0.0146111 s. |0.147528 s. |1.48337 s. |14.945 s. |
| FAILO LAIKAS |0.0100008 s. |0.0582965 s. |0.573093 s. |6.17942 s. |70.5237 s. |

*v1.0 TESTAVIMO REZULTATAI (listas, naudojant viena papildoma konteineri, vidurkis, 7 paz., RAM: 5800MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0026923 s. |0.0260556 s. |0.246379 s. |2.48509 s. |24.3623 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0003233 s. |0.0045772 s. |0.070203 s. |1.14655 s. |15.528 s. |
| RUSIAVIMAS I DVI GRUPES |0.0003817 s. |0.0038534 s. |0.041733 s. |0.421251 s. |4.18216 s. |
| FAILO LAIKAS |0.0098405 s. |0.061309 s. |0.59572 s. |6.53267 s. |71.738 s. |

*v1.0 TESTAVIMO REZULTATAI (listas, naudojant du papildomus konteinerius, vidurkis, 7 paz., RAM: 7500MB)*
| FAILAS |studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
| --- | - | - | - | - | - |
| NUSKAITYMAS |0.0027901 s. |0.025073 s. |0.24257 s. |2.49032 s. |24.5303 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0003396 s. |0.0047946 s. |0.071592 s. |1.07051 s. |15.4688 s. |
| RUSIAVIMAS I DVI GRUPES |0.0005279 s. |0.0063616 s. |0.0611666 s. |0.594323 s. |5.92961 s. |
| FAILO LAIKAS |0.0099222 s. |0.0635894 s. |0.62989 s. |6.77458 s. |75.1002 s. |

*****************************

IŠVADOS:
1. mažiausiai RAM - nenaudojant papildomų konteinerių
2. daugiausiai RAM - naudojant 2 papildomus konteinerius
3. greičiausia strategija - nenaudojant papildomų konteinerių
4. lėčiausia - naudojant du papildomus
5. greičiausias konteineris - vektorius
6. lėčiausias - dekas
7. vektorius reikalauja mažiausiai RAM
8. listas reikalauja daugiausiai RAM
______________________________________________

v0.5 versijoje pridėti 2 nauji konteineriai: list ir deque. Ištestuotas veikimo greitis visų 3 konteinerių.
Rūšiavimui į dvi grupes naudojami du papildomi konteineriai.

*v0.5 TESTAVIMO REZULTATAI (vector, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS |0.0026745 s. |0.0254801 s. |0.230089 s. |2.36638 s. |23.5728 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0010068 s. |0.0129677 s. |0.148798 s. |1.68099 s. |20.0706 s. |
| RUSIAVIMAS I DVI GRUPES |0.0005815 s. |0.0053484 s. |0.0458798 s. |0.471971 s. |4.49471 s. |


*v0.5 TESTAVIMO REZULTATAI (list, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS |0.0026035 s. |0.0257713 s. |0.235164 s. |2.43475 s. |23.6985 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0003024 s. |0.0047881 s. |0.0683193 s. |1.04437 s. |15.5723 s. |
| RUSIAVIMAS I DVI GRUPES |0.0004904 s. |0.0054576 s. |0.0560885 s. |0.568864 s. |5.62757 s. |


*v0.5 TESTAVIMO REZULTATAI (deque, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS |0.0026441 s. |0.0231419 s. |0.226863 s. |2.34653 s. |23.419 s. |
| RUSIAVIMAS PAGAL PAVARDES |0.0012762 s. |0.0164112 s. |0.196054 s. |2.24799 s. |26.8782 s. |
| RUSIAVIMAS I DVI GRUPES |0.0003843 s. |0.0043138 s. |0.0419994 s. |0.453128 s. |4.16894 s. |

*v0.5 ISVADOS (kuris konteineris greičiausiai atlieka tam tikrą uzduotį*
1. NUSKAITYMAS 			-> vec
2. RUSIAVIMAS PAGAL PAVARDES 	-> list
3. RUSIAVIMAS I DVI GRUPES	-> deq

Testai buvo atliekami naudojant:
1. AMD Ryzen 5 5600H (Bazinis greitis:	3,30 GHz, Branduoliai:	6)
2. RAM (16,0 GB, 3200 MHz)
3. SSD SAMSUNG MZVLB1T0HBLR-000L2 (3,500 MB/s read, 3,000 MB/s write)
__________________________________________________________________________________

v0.4 versija suteikia galimybę testuoti programos veikimo greitį. 
Rūšiavimui į dvi grupes naudojami nenaudojami papildomi konteineriai, skirstymas vyksta iškart į buferį.

*v0.4 TESTAVIMO REZULTATAI (7 paz. vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| -------------------------- | --------------- | --------------- | --------------- | --------------- | ---------------|
| NUSKAITYMAS | 0.0026978 s. |	0.0240502 s. | 0.236582 s. | 2.39076 s. | 23.3939 s. |
|RUSIAVIMAS PAGAL PAVARDES |         0.0012214 s.	|	0.0154948 s.	|	0.185395 s.	|	2.16904 s.	|	25.9256 s. |
|RUSIAVIMAS I DVI GRUPES    |        0.0007919 s.	|	0.0078059 s.	|	0.0775511 s.	|	0.761724 s.	|	7.57009 s. |
|STUDENTU ISVEDIMAS I 2 FAILUS |      0.0010293 s.	|	0.0024381 s.	|	0.0145592 s.	|	0.135909 s.	|	1.88412 s. |
|FAILO TESTO LAIKAS             |    0.0101514 s.	|	0.0578819 s.	|	0.560839 s.	|	5.95478 s.	|	64.7254 s. |

*v0.4 TESTAVIMO REZULTATAI (7 paz. med.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| -------------------------- | --------------- | --------------- | --------------- | --------------- | ---------------|
| NUSKAITYMAS | 0.0026622 s. |	0.0231427 s. | 0.222712 s. | 2.24406 s. | 22.3828 s. |
|RUSIAVIMAS PAGAL PAVARDES |    0.0012307 s.     	|	0.0156028 s.	|	0.18151 s.	|	2.1045 s.	|	25.9201 s. |
|RUSIAVIMAS I DVI GRUPES    |     0.0011479 s.   	|	0.011492 s.	|	0.112039 s.	|	1.12202 s.	|	11.1964 s. |
|STUDENTU ISVEDIMAS I 2 FAILUS |   0.0012494 s.   	| 0.0024877 s.	|	0.0175972 s.	|	0.162713 s.	|	1.76581 s. |
|FAILO TESTO LAIKAS             |   0.0107944 s. 	|	0.061578 s.	|	0.584953 s.	|	6.15949 s.	|	 67.3351 s. |

__________________________________________________________
Programa skirta suskaičiuoti galutinius studentų balus pagal pateiktus namų darbų ir egzaminų pažymius.

Išpildyti keli duomenų įkelimo būdai:
1. Įvesti studentų duomenis (Vardas, Pavardė, nd pažymiai, egzamino rezultatas) ranka komandine eilute, jei reikia pažymius programa gali sugeneruoti atsitiktinius pažymius.
2. Nuskaityti duomenis iš failo.

Galutinį balą galima suskaičiuoti naudojant:
1. Nd vidurkį + egzaminas.
2. Nd medianą + egzaminas.

Rezulatų išvedimas galimas į konsolę arba failą. Rezultatai surūšiuojami pagal pavardes.
_________________________________________________________




