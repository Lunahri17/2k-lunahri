% Tipos de clausulas:
gato(tom).
animal(X) :- gato(X).



padrede('Juan', 'Maria').
padrede('Pablo', 'Juan').
padrede('Pablo', 'Marcela').
padrede('Carlos', 'Débora').

hijode(A,B) :- padrede(B,A).
abuelode(A,B) :- padrede(A,C), padrede(C,B).
hermanode(A,B) :- padrede(C,A), padrede(C,B), A \== B.

familiarde(A,B) :- padrede(A,B).
familiarde(A,B) :- hijode(A,B).
familiarde(A,B) :- hermanode(A,B).

% se puede formular de otra manera:
familiarde(A,B) :- padrede(A,B) ; hijode(A,B) ; hermanode(A,B).

% Factorial
factorial(0, 1).
factorial(1, 1).
factorial(N, F) :- N>0, N1 is N - 1, factorial(N1, F1), F is N * F1.


% Listas en Prolog
% Creación y consulta de Listas

plantas([manzana, naranja, limón, espinaca, gardenia, alfalfa, pino]). 

lista([1,2,3]).

% Longitud de una Lista.
longitud([],0).
longitud([_|T],N):-longitud(T,N0), N is N0 + 1.


suma(X,Y,Z) :- Z is X + Y.


% Estructurar datos

persona(juan,23).
alumno(persona(juan,23), ingenieriasistemas, fecha(22,03,1982)).
fecha(22,03,1982).
