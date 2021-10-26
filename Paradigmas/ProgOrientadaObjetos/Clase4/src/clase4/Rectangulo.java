package clase4;

public class Rectangulo extends Figura {
    private int base;
    private int altura;

    public int getBase() {
        return base;
    }

    public void setBase(int base) {
        this.base = base;
    }

    public int getAltura() {
        return altura;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public Rectangulo() {
    }

    public Rectangulo(int base, int altura) {
        this.base = base;
        this.altura = altura;
    }

    public Rectangulo(int base, int altura, String color) {
        super(color);
        this.base = base;
        this.altura = altura;
    }

    @Override
    public void dibujar() {
        for (int i = 0; i <= altura; i++) {
            for (int j = 0; j <= base; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }
        System.out.println("Soy un rectangulo de base " + base + ", de altura "
                            + altura + ", y de color " + getColor());
    }

    
}
