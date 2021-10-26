package clase4;

public abstract class Figura {
    private String color = "Sin color";

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Figura(String color) {
        this.color = color;
    }

    public Figura() {
    }
    
    public abstract void dibujar();
    
    /*
    public void dibujar(){
        System.out.println("No se dibujarme");
    }
    */
}
