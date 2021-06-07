% --- Punto 9 ---
producto(cuaderno, 570).  
producto(lapiz, 50).  
producto(goma, 25).  
producto(compaz, 150).  
producto(carpeta, 255).  
producto(folios, 20). 
producto(cartuchera, 920). 

cliente(camila, cuaderno).  
cliente(camila, lapiz).  
cliente(lisandro, compaz).  
cliente(lisandro, goma).

cantidad(camila, 180).
cantidad(camila, 55).
cantidad(lisandro, 39).
cantidad(lisandro, 50).

productos_comprados('camila', T):- cantidad('camila', A), cantidad('camila', B), T is A + B.
productos_comprados('lisandro', T):- cantidad('lisandro', A), cantidad('lisandro', B), T is A + B.

costos(X, Y):- cliente(X, Y), mcn(X, Y).
mcn(X, Y):- producto(Y, P), cantidad(X, D), D is D * P.
