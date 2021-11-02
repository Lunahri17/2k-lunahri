package miprimersistema;
import java.sql.*;
import javax.swing.table.DefaultTableModel;

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
    
    public void delCustomer(int customerNumber){
            
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "DELETE FROM customers WHERE customerNumber = ?");
            s.setInt(1, customerNumber);
            s.executeUpdate();            
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
    
    public DefaultTableModel listar(){
        DefaultTableModel resultado = new DefaultTableModel();
        resultado.addColumn("customerNumber");
        resultado.addColumn("customerName");
        resultado.addColumn("contactlastName");
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
            Statement s = con.createStatement();
            ResultSet res = s.executeQuery("SELECT * FROM customers");
            while (res.next()) {
                Object[] fila = new Object[3];
                fila[0] = res.getString("customerNumber");
                fila[1] = res.getString("customerName");
                fila[2] = res.getString("contactLastName");
                resultado.addRow(fila);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return resultado;
    }
    public DefaultTableModel findCustomer(int customerNumber){
        DefaultTableModel resultado = new DefaultTableModel();
        resultado.addColumn("customerNumber");
        resultado.addColumn("customerName");
        resultado.addColumn("contactlastName");
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/classicmodels","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "SELECT * FROM customers WHERE customerNumber LIKE '% ?%'");
            s.setInt(1, customerNumber);
            ResultSet res = s.executeQuery(); 
            while (res.next()) {
                Object[] fila = new Object[3];
                fila[0] = res.getString("customerNumber");
                fila[1] = res.getString("customerName");
                fila[2] = res.getString("contactLastName");
                resultado.addRow(fila);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return resultado;
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