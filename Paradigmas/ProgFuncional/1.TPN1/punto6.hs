---Punto 6
--- a) Longitud de una cadena
longCadena [] = 0
longCadena (x:xs) = 1 + longCadena xs;

--- b) Invertir una cadena
invertirCadena [] = []
invertirCadena (x:xs) = invertirCadena xs ++ [x]

--- c) verificar si un elemento pertence a la lista
verificaElem x [] = False
verificaElem x (y:ys) | x == y = True
                      | otherwise = verificaElem x ys

--- d) Eliminar elementos repetidos de una lista
eliminaRep [] = []
eliminaRep (x:xs) = x : eliminaRep (filter (/= x) xs)