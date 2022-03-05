=============================================================================

Criptare Parole: Cifrul Vigenere | Timp de lucru: 7h

	Pentru Cifrul Vigenere am utilizat 2 vectori cheie si text.
	Mai departe am utilizat o functie pentru a verifica daca
	toate caracterele sunt litere.
	Daca toate caracterele sunt litere atunci luam o functie
	in care prelungim cheia cu litere din ea pana ajunge
	sa aiba aceeasi dimensiune cu textul.
	In functia criptare efectuam modificarile cerute
	in text pe baza caracterelor din cheie. 
	Daca caracterul din cheie este litera mare atunci adaugam
	diferenta de 26 din codul ASCII intre literele "A" si "a".
	
=============================================================================

Automatically fill | Timp de lucru: 1 zi

	Pentru aceasta cerinta am alocat dinamic 2 vectori in main
	reprezentand textul initial si cel final. In condinuare am
	alocat dinamic vectorul "sir" de tip struct pereche.
	In functia citire am citit un camp si o valoare pe rand si le-am
	pus intr-un vector de pointeri alocat dinamic. 
	Astfel am retinut toate campurile in "sir[i].camp" 
	si valorile in "sir[i].valoare".
	Apoi citim un caracter "\n" pentru a putea citi dupa textul
	ce trebuie prelucrat. 
	Am realocat dinamic fix cata memorie am nevoie in text.
	Apoi am apelat functia de inlocuire.
	Functia de inlocuire functioneaza prin parcurgerea
	cuvant cu cuvant al textului cu strtok. 
	Daca acel cuvant este camp atunci vom efectua inlocuirea 
	cu valoarea intr-un text rezultat (copiat de la textul initial). 
	Acele while-uri din functie si "sarire" sunt puse pentru 
	a rezolva cazurile asemanatoare in care avem de inlocuit
	"A" cu "AA" si s-ar inlocui in aceeasi pozitie din text.
	Astfel, folosind "sarire" sarim peste cuvintele deja inlocuite.
	Functia de replace inlocuieste campul cu valoarea
	in textul ce trebuie afisat.
	In functia de main dupa apelarea functiei de inlocuire
	realocam dinamic fix cat este necesar si afisam textul.
	Eliberam vectorii alocati dinamic.

=============================================================================

Generare Parole | Timp de lucru: 1 zi

	Pentru rezolvare, am citit seed si n si
	am alocat dinamic vectorul de codificari. 
	Am alocat dinamic un pointer de functii "point_functii".
	In functia generare, se genereaza in vectorul alocat dinamic
	numit "parola" parola de lungimea n si seed-ul dat.
	Generarea se face caracter cu caracter folosind 
	"rand () % (final-initial+1) + initial" insemnand "rand () % 93+32"
	pentru a genera o litera.
	Am salvat in pointerul de functii cele 3 functii de codificare.
	In functia codif am generat random ce codificari 
	trebuie efectuate in vectorul de codificari.
	Functia transform: In while apelam codificarile cerute 
	din vectorul de codificari folosind caracterul curent din parola. 
	Rezultatul obtinut in urma codificarilor va fi afisat direct
	pentru a nu avea probleme de time-out. 
	Tot aici am eliberat memoria vectorului dinamic folosit in 
	codificari prin intermediul pointerului in care
	am salvat rezultatul obtinut.
	In main: Am apelat functiile necesare pentru codificari si 
	la final am eliberat memoria alocata celor 2 vectori.
	Codificare 1: Functia de codificare 1 este cea care poate returna 
	un pointer la un vector alocat dinamic de dimensiune mai mare de 2.
	Pentru a rezolva aceasta codificare am declarat static
	un vector "static int frecv[200]" pentru a retine frecventa
	unui caracter apelat la fiecare apelare a codificarii 1.
	Crestem frecventa si din frecventa obtinuta scadem 1 pentru ca
	numaratoarea incepe de la 0 si o impartim intr-un vector
	in care sunt retinute cifrele numarului corespunzator frecventei.
	Acesta trebuie inversat (din "100" obtinem "0","0","1"
	pe care il transformam in "1","0","0").
	In prima pozitie a vectorului alocat dinamic punem caracterul
	urmat de frecventa acestuia. Returnam rezultatul printr-un pointer.
	Codificare 2: In cadrul acestei codificari am efectuat pe rand
	operatiile cerute. Am explicat in comentarii procedurile.
	Rezultatul obtinut l-am salvat intr-un vector alocat dinamic
	si l-am returnat folosind un pointer.
	Codificare 3: Aceasta functie primeste ca parametrul litera data.
	Daca aceasta este litera mica ii scade codul ASCII cu 32 
	adica distanta de la aceeasi litera scrisa mare sau mica "a" - "A".
	Litera modificata este pusa intr-un vector alocat dinamic
	si returnat printr-un pointer in functia transform.

=============================================================================



