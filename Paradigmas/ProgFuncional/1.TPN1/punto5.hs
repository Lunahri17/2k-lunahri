-- Punto 5:
-- a) Fecha a ingresar "20112019" -> Obtener Día, Mes y Año:
dia x = div x 1000000
mes x = div (mod (x - anio x) 1000000) 10000
anio x = mod x 10000

-- b) Averiguar si un alumno aprobó el parcial (Ap <= 6):
resultado x 
    | x > 5 = "Aprobado"
    | otherwise = "Desaprobado"

-- c) Promedio de 3 numeros:
promedio x y z = (x + y + z) / 3

-- d) Volumen de una esfera:
volumen x =  (4 * (3.14) * x * x * x) / 3