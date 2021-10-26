package javaapplicationclase3;

public class Empleado extends Persona {
    private int sueldo;
    private int horas;

    public int getSueldo() {
        return sueldo;
    }

    public void setSueldo(int sueldo) {
        this.sueldo = sueldo;
    }

    public int getHoras() {
        return horas;
    }

    public void setHoras(int horas) {
        this.horas = horas;
    }

    public Empleado(String nombre, int edad, int sueldo, int horas) {
        super(nombre, edad);
        this.sueldo = sueldo;
        this.horas = horas;
    }

    
}
