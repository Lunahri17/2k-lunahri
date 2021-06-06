% --- Punto 5 ---
borrar_elementos(_, [], []).
borrar_elementos(Y, [Y|Xs], Zs) :- borrar_elementos(Y, Xs, Zs), !.
borrar_elementos(X, [Y|Xs], [Y|Zs]) :- borrar_elementos(X, Xs, Zs).