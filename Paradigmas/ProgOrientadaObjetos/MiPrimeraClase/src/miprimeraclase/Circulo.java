package miprimeraclase;

public class Circulo {
    double radio = 1;
    public void mostrar(){

        System.out.println("Radio: " + radio + ", con un area de: " + calcularArea());
    }
    
    public double calcularArea(){
        return Math.PI * radio * radio;
    }
}
