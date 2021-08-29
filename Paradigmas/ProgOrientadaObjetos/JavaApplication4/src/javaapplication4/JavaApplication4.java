package javaapplication4;

public class JavaApplication4 {
   
    public static void main(String[] args) {
       
        Fecha f1 = new Fecha();
        
        f1.setDia(10);
        f1.modificarMes(6);
        f1.año = 2021;
        System.out.println( f1.aCadena() );
    
    }
    
}
