package miprimeraclase;


public class Rectangulo {
    double base; //byte, short, int, long
    double altura;
    
    public void mostrar(){
        System.out.println("Base: " + base + ", Altura: " + altura);
    }
    
    public double calcularArea(){
        return base * altura;
    }
}
