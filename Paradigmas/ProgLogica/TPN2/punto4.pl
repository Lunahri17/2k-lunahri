repetidos(_, [], 0).
repetidos(B, [Head|Tail], N) :- repetidos(B, Tail, N1), B == Head, N is N1 + 1.
