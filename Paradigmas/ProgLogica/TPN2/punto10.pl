empresa([administracion,personal,produccion]).

empleados(administracion,3).
empleados(personal,1).
empleados(produccion,10).

sueldoPromedio(administracion,6000).
sueldoPromedio(personal,45000).
sueldoPromedio(produccion,77000).

ventas(180000).

% -------

totalSueldos(X, Importe) :- findall((NumEmpleados, Puesto, Sueldo), (empleados(Puesto, NumEmpleados), sueldoPromedio(Puesto, Sueldo)), X), sumaSueldos(X, Importe).

sumaSueldos([(Cant, _, Sueld)], Importe).
sumaSueldos([(Cant, _, Sueld) | Xs], Importe) :- sumaSueldos(Xs, Importe), multi(Cant, Sueld, Z), Importe is Z + Importe.

multi(Cant, Sueld, Z) :- Z is Cant * Sueld.