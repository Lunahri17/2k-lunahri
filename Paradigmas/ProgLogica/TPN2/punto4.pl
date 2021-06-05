% --- Punto 4 ---
repetidos(_, [], 0) :- !.
repetidos(H, [Head|Tail], N) :- repetidos(H, Tail, N1), H =:= Head, N is N1 + 1, !.
repetidos(H, [_ | Tail], N) :- repetidos(H, Tail, N).
