package clase4;

public class Cuadrado extends Figura {
        private int lado;

    public int getLado() {
        return lado;
    }

    public void setLado(int lado) {
        this.lado = lado;
    }

    public Cuadrado() {
    }

    public Cuadrado(int lado) {
        this.lado = lado;
    }

    public Cuadrado(int lado, String color) {
        super(color);
        this.lado = lado;
    }
    
    @Override
    public void dibujar(){
        for (int i = 0; i <= lado; i++) {
            for (int j = 0; j <= lado; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }
        System.out.println("Soy un cuadrado de lado " + lado + ", y de color " +
                            getColor());
    }
}
