% --- Punto 6 ---
insertar(_,[],[]) :- !.
insertar(Num,[Head1 | Tail1], [Head2 | Tail2]) :- insertar(Num, Tail1, Tail2), Head1 > Num, Head2 is Num.
insertar(Num,[Head1 | Tail1], [Head2 | Tail2]) :- insertar(Num, Tail1, Tail2), Head2 is Head1.