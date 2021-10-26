package miprimeraclase;

public class Circulo {
    private double radio = 1;
    
    void setRadio(double rad){
        if (rad >= 0){
            radio = rad;
        } else {
            System.out.println("El radio es invalido");
        }
    }
    
    public void mostrar(){

        System.out.println("Radio: " + radio + ", con un area de: " + calcularArea());
    }
    
    public double calcularArea(){
        return Math.PI * radio * radio;
    }
}
