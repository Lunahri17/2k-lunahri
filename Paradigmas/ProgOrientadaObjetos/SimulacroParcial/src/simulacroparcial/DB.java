package simulacroparcial;

import java.sql.*;
import javax.swing.table.DefaultTableModel;

public class DB {
    public void addPrestamo(int dni, int codigolibro, String fechaprestamo){
            
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/biblioteca","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "INSERT INTO prestamos VALUES(?,?,?,NULL)");
            s.setInt(1, dni);
            s.setInt(2, codigolibro);
            s.setString(3, fechaprestamo);
            s.executeUpdate();
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
    public DefaultTableModel listar(){
        DefaultTableModel datos = new DefaultTableModel();
        datos.addColumn("DNI");
        datos.addColumn("Código del Libro");
        datos.addColumn("Fecha del Prestamo");
        datos.addColumn("Fecha de Devolución");
        
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/biblioteca","root","1234");
            Statement s = con.createStatement();
            ResultSet res = s.executeQuery("SELECT * FROM prestamos");
            while (res.next()) {
                Object[] fila = new Object[4];
                fila[0] = res.getString("dni");
                fila[1] = res.getString("codigolibro");
                fila[2] = res.getString("fechaprestamo");
                fila[3] = res.getString("fechadevolucion");
                datos.addRow(fila);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return datos;
    }
    
    public DefaultTableModel findPrestamo(int dni){
        DefaultTableModel datos = new DefaultTableModel();
        datos.addColumn("DNI");
        datos.addColumn("Código del Libro");
        datos.addColumn("Fecha del Prestamo");
        datos.addColumn("Fecha de Devolución");
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/biblioteca","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "SELECT * FROM prestamos WHERE dni = ?");
            s.setInt(1, dni);
            ResultSet res = s.executeQuery(); 
            while (res.next()) {
                Object[] fila = new Object[4];
                fila[0] = res.getString("dni");
                fila[1] = res.getString("codigolibro");
                fila[2] = res.getString("fechaprestamo");
                fila[3] = res.getString("fechadevolucion");
                datos.addRow(fila);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return datos;
    }
    
    public void addDevolucion(int dni, String fechadevolucion){   
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost/biblioteca","root","1234");
            PreparedStatement s = con.prepareStatement(
                    "UPDATE prestamos SET fechadevolucion = ? WHERE dni = ?");
            s.setString(1, fechadevolucion);
            s.setInt(2, dni);
            s.executeUpdate();         
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
