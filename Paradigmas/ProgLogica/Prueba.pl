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



suma(X,Y,Z) :- Z is X + Y.