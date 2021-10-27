package mariadbconnector;

import java.sql.*; //Connection, Statement, ResultSet

public class Mariadbconnector {

    public static void main(String[] args) {
        try { 
            //Iniciar conexión
            Connection c = DriverManager.getConnection(
                    "jdbc:mysql://localhost/videoclub","root","1234"); //Se puede especificar tmb el puerto
            System.out.println("Conexión Establecida");
            
            //Enviar orden a mariaDB
            Statement s = c.createStatement();
            //s.execute("CREATE DATABASE prueba1");
            //s.execute("INSERT INTO pelicula VALUES(7,'IT','Terror')");
            //int res = s.executeUpdate("DELETE FROM pelicula WHERE codigo = 7"); 
                                                        //Devuelve un int con la cantidad de filas afectadas
            //System.out.println(res);
            
            ResultSet res = s.executeQuery("SELECT * FROM pelicula");
            while (res.next()){
                System.out.println(res.getString("Codigo"));;
                System.out.println(res.getString("Nombre"));;
                System.out.println(res.getString("Genero"));;
            }
            
        } catch (Exception e){
            System.out.println("Error de Conexión: " + e);
        }
    }
    
}
