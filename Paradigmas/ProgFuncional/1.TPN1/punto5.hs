-- Punto 5:
-- a) Fecha a ingresar "20112019" -> Obtener Día, Mes y Año:
dia x = div x 1000000
mes x = div (mod (x - anio x) 1000000) 10000
anio x = mod x 10000
fecha x = (dia x , mes x , anio)

-- b) Averiguar si un alumno aprobó el parcial (Ap <= 6):
resultado x 
    | x > 5 = "Aprobado"
    | otherwise = "Desaprobado"

-- c) Promedio de 3 números:
promedio x y z = (x + y + z) / 3

-- d) Volumen de una esfera:
volumen x =  (4 * pi * x * x * x) / 3

-- e) Área de un circulo:
area x = pi * x * x

-- f) Última cifra de un número entero:
ultimo x = mod x 10

-- g) dado tres números que representan longitudes indicar si pueden formar un triangulo
triangulo x y z = if (x < (y + z)) && (y < (x + z)) && (z < (x + y)) then "Es triangulo" else "No es triangulo"

-- h) Semaforo:
semaforo x
    | x == "rojo" = "No avanzar"
    | x == "amarillo" = "No avanzar"
    | x == "verde" = "avanzar"
