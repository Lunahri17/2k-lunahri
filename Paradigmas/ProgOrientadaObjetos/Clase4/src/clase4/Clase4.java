package clase4;

public class Clase4 {

    public static void main(String[] args) {
        Cuadrado c = new Cuadrado(5, "rojo");
        
        c.dibujar();
        System.out.println();
        System.out.println("--------------------------");
        System.out.println();
        
        Rectangulo r = new Rectangulo(5,12,"azul");
        r.dibujar();
    }
    
}
