package javaapplication4;

public class Fecha {
    private int dia;
    private int mes;
    int año;
    
    public void setDia(int d){
        if (mes == 2 && d>29){
            System.out.println("Error en el Día");
        }
        else if (mes!=2 && d > 31){
            System.out.println("Error en el Dia");
        }
        else{
            dia = d;
        }
    }
    public int getDia(){
        return dia;
    }
    
    public void modificarMes(int m){
        if (mes > 12) mes = 12;
        else mes = m;
    }
    
    public String aCadena(){
        return dia + "/" + mes + "/" + año;
    }
}
