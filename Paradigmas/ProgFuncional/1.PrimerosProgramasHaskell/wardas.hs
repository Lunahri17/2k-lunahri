factorial x 
    | x == 0 = 1
    | otherwise = x * factorial (x - 1)

clasificar x
    | x <= 3 = "Aplaso"
    | x <= 6 = "Aprobado"
    | x >= 7 = "Promocionado"