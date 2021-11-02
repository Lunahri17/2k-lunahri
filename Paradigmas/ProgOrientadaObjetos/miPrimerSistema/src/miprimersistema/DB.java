package miprimersistema;
import java.sql.*;

public class DB {
    public void prueba(){
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
