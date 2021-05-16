--- Punto 8:
--- La sumade los componentesde una tupla
sumaComp :: (Int,Int)-> Int
sumaComp (x,y) = x + y

--- Funciónque recibe 2 enteros y devuelva una tupla donde el primer componente sea el mayor de los dos y la segunda el menor.
maxmin :: Int -> Int -> (Int, Int)
maxmin x y | x > y = (x,y)
           | otherwise = (y,x)

--- La sumade los componentespara una lista de tuplas
listaSumComp :: [(Int,Int)] -> [Int]
listaSumComp [] = []
listaSumComp (x:xs) = sumaComp x : listaSumComp xs


--- Problama de la base de datos de la pelicula
--- a) Dada una lista de películas devuelva el tiempo que tardaría en verlas a todas.
---verTodas :: [(String, Int, Int, String)] -> Int
---verTodas [] = []
---verTodas ((x1,x2,x3,x4):xs) = x3 + verTodas xs

--- b) Dada una lista de películas devuelva el listado de películas que estrenaron en 2019
estrenos :: [(String, Int, Int, String)] -> [String] 
estrenos [] = []
estrenos (x:xs) | anioPeli x == True = nombrePeli x : estrenos xs
                | otherwise = estrenos xs

--- Funciones adicionales para estrenos
anioPeli :: (String, Int, Int, String) -> Bool
anioPeli (w,x,y,z) | x == 2019 = True
                   | otherwise = False

nombrePeli :: (String, Int, Int, String) -> String
nombrePeli (w,x,y,z) = w


--- Funcion similar a map
fun f f2 (x:xs) = [f (f2 x) | x <- xs]

cuadrado x = x * x
siguiente x = x + 1