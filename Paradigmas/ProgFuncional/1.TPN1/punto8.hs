--- Punto 8:
--- La sumade los componentesde una tupla
sumaComp :: (Int,Int)-> Int
sumaComp (x,y) = x + y

--- Funciónque recibe 2 enteros y devuelva una tupla donde el primer componente sea el mayor de los dos y la segunda el menor.
maxmin :: Int -> Int -> (Int, Int)
maxmin x y | x > y = (x,y)
           | otherwise = (y,x)