# OBJ2023
Programa skirta suskaičiuoti galutinius studentų balus pagal pateiktus namų darbų ir egzaminų pažymius.

Išpildyti keli duomenų įkelimo būdai:
1. Įvesti studentų duomenis (Vardas, Pavardė, nd pažymiai, egzamino rezultatas) ranka komandine eilute, jei reikia pažymius programa gali sugeneruoti atsitiktinius pažymius.
2. Gauna duomenis iš failo.

Galutinį balą galima suskaičiuoti naudojant:
1. Nd vidurkį + egzaminas.
2. Nd medianą + egzaminas.

Rezulatų išvedimas galimas į konsolę arba failą. Rezultatai surūšiuojami pagal pavardes.


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

v0.5 versijoje prideti 2 nauji konteineriai: list ir deque. Istestuotas veikimo greitis visu 3 konteineriu.
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






