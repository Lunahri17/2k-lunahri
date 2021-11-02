package miprimersistema;
import java.sql.*;

public class DB {
    
    public void addCustomer(int customerNumber, String customerName, String contactLastName,
            String contactFirstName, String phone, String addressLine1,
            String addressLine2, String city, String state, String postalCode,
            String country, int salesRepEmployeeNumber, double creditLimit){
            
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "INSERT INTO customers VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?)");
            s.setInt(1, customerNumber);
            s.setString(2, customerName);
            s.setString(3, contactLastName);
            s.setString(4, contactFirstName);
            s.setString(5, phone);
            s.setString(6, addressLine1);
            s.setString(7, addressLine2);
            s.setString(8, city);
            s.setString(9, state);
            s.setString(10, postalCode);
            s.setString(11, country);
            s.setInt(12, salesRepEmployeeNumber);
            s.setDouble(13, creditLimit);
            s.executeUpdate();            
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
    public void prueba(){
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
            Statement s = con.createStatement();
            ResultSet res = s.executeQuery("SELECT current_user");
            res.next();
            System.out.println(res.getString(1));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
