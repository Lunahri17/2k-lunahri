package javaapplicationclase3;

public class Alumno extends Persona {
    private int legajo;
    private String carrera;

    public int getLegajo() {
        return legajo;
    }

    public void setLegajo(int legajo) {
        this.legajo = legajo;
    }

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }

    public Alumno(int legajo, String carrera, String nombre, int edad) {
        super(nombre, edad);
        this.legajo = legajo;
        this.carrera = carrera;
    }
    
}
