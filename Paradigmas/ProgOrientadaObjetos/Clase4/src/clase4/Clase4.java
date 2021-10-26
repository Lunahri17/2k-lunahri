package clase4;

public class Clase4 {

    public static void main(String[] args) {
        Cuadrado c = new Cuadrado(5, "rojo");
        
        //c.dibujar();
        System.out.println();
        System.out.println("--------------------------");
        System.out.println();
        
        Rectangulo r = new Rectangulo(5,12,"azul");
        //r.dibujar();
        
        
       //polimorfismo
       
       Figura[] figuras = new Figura[3];
       figuras[0] = c;
       figuras[1] = r;
       
        for (int i = 0; i < 2; i++) {
            Figura f = figuras[i];
            f.dibujar();
            System.out.println("--------------------------");
        }
       
    }
    
}
