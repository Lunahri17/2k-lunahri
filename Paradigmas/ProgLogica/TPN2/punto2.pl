% --- Punto 2 ---
quierea('Pedro', 'Maria').	% Pedro quiere a María.
quierea('Pedro', 'Belen').	% Pedro quiere a Belén.
quierea('Manuel', 'Belen').	% Manuel quiere a Belén.
quierea('Maria', 'Pedro').	% María quiere a Pedro.

quierea('Todos','Maria').   % Todos quieren a María.
quierea('Todos','Juan').    % Todos quieren a Juan.

% Todo el mundo se quiere a si mismo.
quierea('Juan', 'Asimismo').
quierea('Pedro', 'Asimismo').
quierea('Maria', 'Asimismo').
quierea('Belen', 'Asimismo').
quierea('Manuel', 'Asimismo').

quierea('Alguien','Juan').  % Alguien quiere a Juan.
quierea('Alguien','Pedro'). % Alguien quiere a Pedro.
quierea('Alguien','Maria'). % Alguien quiere a María.

quierea('Alguien','Todos'). % Alguien quiere a Todos.


% Predicados a responder:
% ¿Quiere Manuel a María? 			            -> quierea('Manuel', 'Maria').
% ¿Quiere Manuel a María y a Pedro?         	-> quierea('Manuel', 'Maria'), quierea('Manuel', 'Pedro').
% ¿Quiere Manuel a alguien? 			        -> quierea('Manuel', 'Alguien').
% ¿Quiénes son los que quieren a María? 	    -> quierea(X, 'Maria').
% ¿Quiénes son los que quieren a Pedro? 	    -> quierea(X, 'Pedro').
% ¿Quiénes son los que se quieren mutuamente? 	-> quierea(X, Y), quierea(Y, X).
% ¿Quiénes son los que se quieren a sí mismos? 	-> quierea(X, 'Asimismo').
% ¿Se quiere Manuel a sí mismo? 		        -> quierea('Manuel','Asimismo').
% ¿Hay alguien que quiera a María? 		        -> quierea('Alguien','Maria').
% ¿Hay alguien que quiera a alguien?            -> quierea('Alguien', 'Alguien').
% ¿Hay alguien que se quiera a sí mismo? 	    -> quierea('Alguien', 'Asimismo').
% ¿Hay alguien que quiera a todo el mundo? 	    -> quierea('Alguien', 'Todos').
