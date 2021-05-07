package miprimeraclase;


public class Rectangulo {
    double base; //byte, short, in long
    double altura;
    public void mostrar(){
        System.out.println("Base: " + base + ", Altura: " + altura);
    }
    
    public double calcularArea(){
        return base * altura;
    }
}
