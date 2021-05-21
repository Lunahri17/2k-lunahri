incrementar x = x + 1

cuadrado x = x * x

cubo x = x * x * x

hola = "mundo"

--Encaje de Patrones
--Patron Simple
fac 0 = 1
fac x = x * fac (x - 1)

--Patron Tupla
base (x,y) = x
altura (x,y) = y
area (x,y) = x * y

--Patron Lista
primero (x:xs) = x
cola (x:xs) = xs



--if en haskell

fac x = if (x==0) then 1
        else x * fac(x-1)