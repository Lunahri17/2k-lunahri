% Punto 10
empresa([administracion,personal,produccion]).

empleados(administracion,3).
empleados(personal,1).
empleados(produccion,10).

sueldoPromedio(administracion,60000).
sueldoPromedio(personal,45000).
sueldoPromedio(produccion,77000).

ventas(180000).

% ----Apartado a)----

totalSueldos(X, Importe) :- findall((NumEmpleados, Puesto, Sueldo), (empleados(Puesto, NumEmpleados), sueldoPromedio(Puesto, Sueldo)), X), sumaSueldos(X, Importe).

sumaSueldos([], 0) :- !.
sumaSueldos([(Cant, _, Sueld) | Xs], Importe) :- sumaSueldos(Xs, Importe1), multi(Cant, Sueld, Z), Importe is Z + Importe1, !.
sumaSueldos([(Cant, _, Sueld) | Xs], Importe) :- sumaSueldos(Xs, Importe).

multi(Cant, Sueld, Z) :- Z is Cant * Sueld.

% ----Apartado b)----
porcentaje(TotalGasto, X, Importe) :- findall(Ingresos, (ventas(Ingresos)), X), recorte(TotalGasto, X, Importe).

recorte(TotalGasto, [Head |_], Importe) :- Head > TotalGasto, Importe is Head - TotalGasto.





excedente(_, [], 0) :- !.
excedente(TotalGasto, [Head | Tail], Importe) :- excedente(TotalGasto, Tail, Importe), Importe is TotalGasto - Head, !.
excedente(TotalGasto, [Head | Tail], Importe) :- excedente(TotalGasto, Tail, Importe).