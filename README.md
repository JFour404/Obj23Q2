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

*v0.5 TESTAVIMO REZULTATAI (vector, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS 			| 0.0026161 s. 	| 0.0236885 s.	| 0.225701 s.		| 2.35053 s. 		| 23.1969 s. |
|RUSIAVIMAS PAGAL PAVARDES 	| 0.0010425 s.	| 0.0131544 s.	| 0.154814 s.		| 1.75592 s.		| 21.1027 s. |
|RUSIAVIMAS I DVI GRUPES  		| 0.0008217 s.	| 0.0079533 s.	| 0.0799499 s.	| 0.79476 s.		| 7.99026 s. |


*v0.5 TESTAVIMO REZULTATAI (list, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS 			| 0.0082148 s. 	| 0.0272699 s.	| 0.243159 s.		| 2.48977 s. 		| 24.73 s. |
|RUSIAVIMAS PAGAL PAVARDES 	| 0.0003096 s.	| 0.0043556 s.	| 0.069723 s.		| 1.06015 s.		| 16.0136 s. |
|RUSIAVIMAS I DVI GRUPES  		| 0.0009534 s.	| 0.008776 s.		| 0.0876484 s.	| 0.87294 s.		| 8.90919 s. |


*v0.5 TESTAVIMO REZULTATAI (deque, 7 paz., vid.)*
| FAILAS | studentai1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai10000000.txt| 
| ------ | ----------------- | ------------------ | ------------------- | -------------------- | ---------------------|
| NUSKAITYMAS 			| 0.0026564 s. 	| 0.0237203 s.	| 0.240121 s.		| 2.42459 s. 		| 23.5407 s. |
|RUSIAVIMAS PAGAL PAVARDES 	| 0.0014029 s.	| 0.017555 s.		| 0.207501 s.		| 2.34581 s.		| 28.7988 s. |
|RUSIAVIMAS I DVI GRUPES  		| 0.0011798 s.	| 0.0096889 s.	| 0.0864332 s.	| 0.852244 s.		| 8.529 s. 	|

*v0.5 ISVADOS (kuris konteineris greičiausiai atlieka tam tikrą uzduotį*
1. NUSKAITYMAS 			-> vec
2. RUSIAVIMAS PAGAL PAVARDES 	-> list
3. RUSIAVIMAS I DVI GRUPES	-> vec

Testai buvo atliekami naudojant:
1. AMD Ryzen 5 5600H (Bazinis greitis:	3,30 GHz, Branduoliai:	6)
2. RAM (16,0 GB, 3200 MHz)
3. SSD SAMSUNG MZVLB1T0HBLR-000L2 (3,500 MB/s read, 3,000 MB/s write)






