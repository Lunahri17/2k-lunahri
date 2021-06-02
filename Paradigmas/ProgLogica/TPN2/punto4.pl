repetidos(_, [], 0).
repetidos(Head1, [Head|Tail], N) :- repetidos(Head1, Tail, N1), Head1 == Head, N is N1 + 1.
