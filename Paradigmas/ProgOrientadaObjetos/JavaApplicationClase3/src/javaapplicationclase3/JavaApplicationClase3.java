package javaapplicationclase3;

public class JavaApplicationClase3 {

    public static void main(String[] args) {
        Persona p = new Persona("Luna",21);
        //p.setNombre("Luna");
        //p.setEdad(21);
        System.out.println(p.getNombre() + " " + p.getEdad());
        
        
        Alumno a = new Alumno(52473,"ISI","Luna",21);
        //a.setNombre("Luna");
        //a.setEdad(21);
        //a.setLegajo(52473);
        //a.setCarrera("ISI");
        System.out.println(p.getNombre() + " " + p.getEdad());
    }
    
}
