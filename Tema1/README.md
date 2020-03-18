# Tema 1 POO
Tema 13. Clasa ”Polinom” - reprezentat ca tablou unidimensional (prin gradul polinomului si vectorul
coeficientilor (coeficientii vor apartine la monoame de grade consecutive), de dimensiune egala cu gradul
plus 1, de la cel al termenului liber la cel de grad maxim.
- fiecare coeficient va fi de tip double;
- membri privati pentru vectorul propriuzis si numarul de elemente;
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii
dinamice, se dezaloca zona de memorie utilizata);
- metoda publica pentru calculul valorii unui polinom intr-un punct;
- suma a doua polinoame, implementata prin supraincarcarea operatorului +;
- diferenta a doua polinoame, implementata prin supraincarcarea operatorului -;
- produsul a doua polinoame, implementat prin supraincarcarea operatorului *;

### Cerinte comune tuturor temelor:
- implementare in C++ folosind clase
- ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie
altfel de functii), pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se
considera ca aceasta alegere este mai naturala;
- supraincarcarea operatorilor &lt;&lt; si &gt;&gt; pentru iesiri si intrari de obiecte, dupa indicatiile de
mai jos, astfel incat sa fie permise (si ilustrate in program):
- sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte,
memorarea și afisarea acestora.