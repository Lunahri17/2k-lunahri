% --- Punto 3 ---
edadde('Juan',95).
edadde('Maria',87).
edadde('Ana',37).
edadde('Analia',48).
edadde('Oscar',34).
edadde('Martin',37).
edadde('Esteban',17).
edadde('Rafaella',5).
edadde('Matias',5).
edadde('Simon',2).



bebe(A):-edadde(A,B), B < 3.
nino(A):-edadde(A,B), B >2 , B <10.
adolecente(A):-edadde(A,B), B > 9 ,B < 21.
adulto(A):-edadde(A,B), B >20 , B <70.
anciano(A):-edadde(A,B), B > 69.



mayor(A,B):- edadde(A,D), edadde(B,E), D>E.
menor(A,B):- edadde(A,D), edadde(B,E), D<E.
igual(A,B):- edadde(A,D), edadde(B,E), D=E.

hombre('Marcelo').
hombre('Oscar').
hombre('Martin').
hombre('Esteban').
hombre('Matias').
hombre('Simon').
mujer('Maria').
mujer('Ana').
mujer('Analia').
mujer('Andrea').
mujer('Sara').
mujer('Rafaella').

padre('Juam','Ana').
padre('Juan','Analia').
padre('Juan','Oscar').
padre('Maria','Ana').
padre('Maria','Analia').
padre('Maria','Oscar').
padre('Ana','Martin').
padre('Marcelo','Martin').
padre('Martin','Matias').
padre('Martin','Simon').
padre('Sara','Matias').
padre('Sara','Simon').
padre('Oscar','Esteban').
padre('Oscar','Rafaella').
padre('Andrea','Esteban').
padre('Andrea','Rafaella').

esposos('Juan','Maria').
esposos('Ana','Marcerlo').
esposos('Andrea','Oscar').
esposos('Martin','Sara').
esposos('Maria','Juan').
esposos('Ana','Marcelo').
esposos('Oscar','Andrea').
esposos('Sara','Martin').


diferente(X,Y):- X \== Y.
hijo(A,B):-padre(B,A),hombre(A).
hija(A,B):-padre(B,A),mujer(A).
nieto(A,B):-padre(B,C),padre(C,A),hombre(A).%solo es nieto hombre
hermano(A,B):-padre(C,A),padre(C,B),diferente(A,B).
primo(A,B):-padre(C,A),padre(D,B),hermano(C,D),diferente(D,C).
tio(A,B):-padre(C,B),hermano(C,A),hombre(A).
tia(A,B):-padre(C,B),hermano(C,A),mujer(A).
sobrino(A,B):-hijo(A,C),hermano(C,B),hombre(A).
sobrina(A,B):-hija(A,C),hermano(C,B),mujer(A).
abuelo(A,B):-nieto(B,A).

cuniadoado(A,B):- esposos(B,), hermano(A,).
suegro(A,B):- hijo(,A); hija(,A), esposos(_,B).
bisnieto(A,B):-padre(B,C), padre(C,D), padre(D,A), mujer(A).
bisnieto(A,B):-padre(B,C), padre(C,D), padre(D,A), hombre(A).
