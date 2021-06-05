% --- Punto 8 ---
cursa(pedro, paradigmas).
cursa(mario, paradigmas).
cursa(pedro, operativos).
cursa(sara, sintaxis).

materias(Nombre, X) :- findall((Materia), (cursa(Nombre,Materia)),X).

base(X) :- findall((Nombre,Materia), (cursa(Nombre,Materia)),X).