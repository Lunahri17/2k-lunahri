---Punto 6
--- a) Longitud de una cadena
longCadena [] = 0
longCadena (x:xs) = 1 + longCadena xs;

--- b) Invertir una cadena
invertirCadena [] = []
invertirCadena (x:xs) = invertirCadena xs ++ [x]