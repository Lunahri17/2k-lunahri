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

--- e) Unir dos listas de cadenas de cadena (incluidos repetidos)
unirLista [] ys = ys
unirLista xs [] = xs
unirLista (x:xs) ys 
    |verificaElem x ys = unirLista xs ys
    |otherwise = [x] ++ unirLista xs ys

--- h) obtener vocales
vocales [] = []
vocales (x:xs) |x == 'a' = x : vocales xs
               |x == 'e' = x : vocales xs
               |x == 'i' = x : vocales xs
               |x == 'o' = x : vocales xs
               |x == 'u' = x : vocales xs
               |otherwise = vocales xs