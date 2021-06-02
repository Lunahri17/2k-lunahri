% ---Punto 2 ---
quierea('Pedro', 'Maria').	% Pedro quiere a María.
quierea('Pedro', 'Belen').	% Pedro quiere a Belén.
quierea('Manuel', 'Belen').	% Manuel quiere a Belén.
quierea('Maria', 'Pedro').	% María quiere a Pedro.

% Todos quieren a Juan y a Maria.
quierea('Pedro', 'Juan').
quierea('Maria', 'Juan').
quierea('Belen', 'Juan').
quierea('Manuel', 'Juan').
quierea('Belen', 'Maria').
quierea('Manuel', 'Maria').
quierea('Juan', 'Maria').

% Todo el mundo se quiere a si mismo.
quierea('Juan', 'Juan').
quierea('Pedro', 'Pedro').
quierea('Maria', 'Maria').
quierea('Belen', 'Belen').
quierea('Manuel', 'Manuel').
sequiere(X) :- Y = X, quierea(X, Y).

% Alguien quiere a: 
alguienquierea(X, Y, Z) :- quierea(X, Y), quierea(X, Z).

alguienquiere(A) :- quierea(B,A), B \== A . % Alguien quiere a Maria.

% Alguien quiere a todos los demás.
alguienquieretodos(L) :- A = 'Maria', B = 'Juan', C = 'Pedro', D = 'Belen', E = 'Manuel', quierea(L, A), quierea(L, B), quierea(L, C), quierea(L, D), quierea(L, E).

% Predicados a responder:
% ¿Quiere Manuel a María? 			            -> quiera('Manuel', 'Maria').
% ¿Quiere Manuel a María y a Pedro?         	-> quierea('Manuel', 'Maria'), quierea('Manuel', 'Pedro').
% ¿Quiere Manuel a alguien? 			        -> quierea('Manuel', X).
% ¿Quiénes son los que quieren a María? 	    -> quierea(X, 'Maria').
% ¿Quiénes son los que quieren a Pedro? 	    -> quierea(X, 'Pedro').
% ¿Quiénes son los que se quieren mutuamente? 	-> quierea(X, Y), quierea(Y, X).
% ¿Quiénes son los que se quieren a sí mismos? 	-> sequiere(X).
% ¿Se quiere Manuel a sí mismo? 		        -> sequiere('Manuel').
% ¿Hay alguien que quiera a María? 		        -> alguienquiere('Maria').
% ¿Hay alguien que quiera a alguien?            -> alguienquiere(A).
% ¿Hay alguien que se quiera a sí mismo? 	    -> sequiere(X).
% ¿Hay alguien que quiera a todo el mundo? 	    -> alguienquieretodos(L).
