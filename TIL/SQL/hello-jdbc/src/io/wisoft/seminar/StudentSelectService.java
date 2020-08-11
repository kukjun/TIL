package io.wisoft.seminar;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class StudentSelectService {

    public void getStudentAll() {
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            conn = PostgresqlAccess.setConnection();
            conn.setAutoCommit(false);

            String query ="SELECT * FROM STUDENT";
            pstmt = conn.prepareStatement(query);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                System.out.print("[학번] " + rs.getString(1) + "||");
                System.out.print("[이름] " + rs.getString(2) + "||");
                System.out.println("[생일] " + rs.getString(3));
            }
        } catch (SQLException sqex) {
            System.out.println("SQLException: " + sqex.getMessage());
            System.out.println("SQLState: " + sqex.getSQLState());
        } finally {
            if (rs != null) { try{ rs.close(); } catch(Exception e) { e.printStackTrace(); }}
            if (pstmt != null){try{ pstmt.close ();}catch(Exception e ) { e.printStackTrace(); }}
            if (conn != null) { try{ conn.close ();}catch(Exception e) { e.printStackTrace (); }}
        }
    }

    public void getStudentByNo(String studentNo) {
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            conn = PostgresqlAccess.setConnection();
            conn.setAutoCommit(false);

            String query = "SELECT * FROM STUDENT WHERE NO = ?";
            pstmt = conn.prepareStatement(query);
            pstmt.setInt(1, Integer.parseInt(studentNo));
            rs = pstmt.executeQuery();

            while (rs.next()) {
                System.out.print("[학번] " + rs.getString(1) + " || ");
                System.out.print("[이름] " + rs.getString(2) + " || ");
                System.out.println("[생일] " + rs.getString(3));
            }
        } catch (SQLException sqex) {
            System.out.println("SQLException: " + sqex.getMessage());
            System.out.println("SQLState: " + sqex.getSQLState());
        } finally {
            if (rs != null) { try{ rs.close(); } catch(Exception e) { e.printStackTrace(); }}
            if (pstmt != null){try{ pstmt.close(); } catch(Exception e) { e.printStackTrace(); }}
            if (conn != null) { try{ conn.close ();}catch(Exception e) { e.printStackTrace (); }}
        }

    }

    public void getStudentByName(String studentName) {

    }

    public void getStudentByBirthday(String studentBirthday) {
    Connection conn = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;

    try {
        conn = PostgresqlAccess.setConnection();
        conn.setAutoCommit(false);

        String query = "SELECT * FROM STUDENT WHERE BIRTHDAY = ?";
        pstmt = conn.prepareStatement(query);
        pstmt.setString(1, studentBirthday);
        rs = pstmt.executeQuery();

        while(rs.next()) {
            System.out.print("[학번] " + rs.getString(1) + " || ");
            System.out.print("[이름] " + rs.getString(2) + " || ");
            System.out.println("[생일] " + rs.getString(3));
        }
    } catch (SQLException sqex) {
        System.out.println("SQLException: " + sqex.getMessage());
        System.out.println("SQLState: " + sqex.getSQLState());
    } finally {
        if ( pstmt != null ) try{pstmt.close();}catch(Exception e){}
        if ( conn != null ) try{conn.close();} catch (Exception e){

        }
    }
    }
}
