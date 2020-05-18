# Tema 3 POO

Tema 7.  La realizarea unui film(nume,tip,durata), participa o mulțime de persoane: un regizor, actori, personal tehnic etc. Fiecare personal (cnp, nume, nume_film) are prevăzut prin contract un procent din încasări, drept urmare  primește, pentru fiecare film la care participa, o anumită suma. Actorii, dacă sunt personaje principale, primesc un bonus de 10% din încasări, iar regizorul are prevăzut și o suma fixa, indiferent de calitatea filmului produs.
Structura de date: set<tuple<persoana, film, bonus>>

Cerința suplimentară:

- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Sa se construiască clasa template FirmaDistributie care sa conțină informații despre filmele realizate într-un an. Clasa conțină numărul total de persoane implicat incrementat automat), numărul de actori (incrementat automat) și o structura de obiecte, alocată dinamic.
- Să se realizeze o specializare pentru tipul Actor, care sa conțină numărul actorilor care au fost distribuiți în roluri principale.

## Cerinte comune tuturor temelor

- utilizarea sabloanelor
- utilizarea STL
- utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
- utilizarea conceptelor de RTTI raportat la template-uri
- tratarea excepțiilor
- citirea informațiilor complete a n obiecte, memorarea și afișarea acestora

## Cerinte generale aplicate fiecarei teme din acest fisier

- sa se identifice si sa se implementeze ierarhia de clase;
- clasele să contina constructori, destructori, =, functie prietena de citire a datelor;
- clasa de baza sa conțină funcție virtuala de afisare, rescrisa in clasele derivate, iar operatorul de citire sa fie implementat ca functie prieten (in clasele derivate sa se faca referire la implementarea acestuia in clasa de baza).
