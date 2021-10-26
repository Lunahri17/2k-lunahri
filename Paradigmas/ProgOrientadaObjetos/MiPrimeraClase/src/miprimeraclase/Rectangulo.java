package miprimeraclase;


public class Rectangulo {
    private double base; //byte, short, int, long
    private double altura;

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        if (base > 0){
            this.base = base;
        } else {
            System.out.println("Se ingresó un valor de Base incorrecto");
        }
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        if (altura > 0){
            this.altura = altura;
        } else {
            System.out.println("Se ingresó un valor de altura incorrecto");
        }
    }
    
    public void mostrar(){
        System.out.println("Base: " + base + ", Altura: " + altura);
    }
    
    public double calcularArea(){
        return base * altura;
    }
}
