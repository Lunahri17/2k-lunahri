package miprimeraclase;

public class Circulo {
    double radio = 1;
    
    void setRadio(double rad){
        radio = rad;
    }
    
    public void mostrar(){

        System.out.println("Radio: " + radio + ", con un area de: " + calcularArea());
    }
    
    public double calcularArea(){
        return Math.PI * radio * radio;
    }
}
