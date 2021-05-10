-- Punto 5:
-- a) Fecha a ingresar "20112019" -> Obtener Día, Mes y Año
dia x = div x 1000000
mes x = div (mod (x - anio x) 1000000) 10000
anio x = mod x 10000