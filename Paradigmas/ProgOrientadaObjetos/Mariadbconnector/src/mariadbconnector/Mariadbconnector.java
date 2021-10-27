package mariadbconnector;

import java.sql.*; //Connection, Statement, ResultSet

public class Mariadbconnector {

    public static void main(String[] args) {
        try { 
            //Iniciar conexión
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost","root","1234");
            System.out.println("Conexión Establecida");
            
        } catch (Exception e){
            System.out.println("Error de Conexión");
        }
    }
    
}
