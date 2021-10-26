package miprimeraclase;


public class MiPrimeraClase {

    public static void main(String[] args) {
        
        //Creación de un primer objeto
        Rectangulo r1 = new Rectangulo();
        //r1.altura = 10; //Ya no se puede acceder porque está en private
        //r1.base = 20; //Ya no se puede acceder porque está en private
        //double area = r1.base * r1.altura;
        
        //Segundo objeto
        Rectangulo r2 = new Rectangulo();
        //r2.altura = 5; //Ya no se puede acceder porque está en private
        //r2.base = 1; //Ya no se puede acceder porque está en private
                
        //System.out.println(area);
        //System.out.println(r2.altura*r2.base);
        
        //En este programa se crean 2 objetos.
        
        //Comportamiento dentro de un objeto:
        r1.mostrar();
        System.out.println("Area del Rectangulo r1: " + r1.calcularArea());
        
        
        //Creamos un obejto circulo
        Circulo c1 = new Circulo();
        c1.mostrar();
        //c1.radio = 20; //Ya no se puede acceder porque está en private
        c1.mostrar(); //Le envio un mensaje al obejto circulo c1 que se muestre.
        System.out.println("Area del circulo c1: " + c1.calcularArea());
        
        
        //Encapsulamiento
        //Circulo:
        c1.setRadio(10);
        c1.setRadio(-10);
        c1.mostrar();
        System.out.println("Area del circulo c1: " + c1.calcularArea());
    }
    
}
