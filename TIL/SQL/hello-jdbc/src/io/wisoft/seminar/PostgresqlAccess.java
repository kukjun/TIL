package io.wisoft.seminar;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class PostgresqlAccess {
    private static Connection conn = null;

    public void init() {
        try {
            Class.forName("org.postgresql.Driver");
        }
        catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static Connection setConnection() {
        String url = "jdbc:postgresql://localhost:5432/exercise";
        String username = "postgres";
        String password = "@leekukchun0519";

        try {
            conn = DriverManager.getConnection(url, username, password);
        }
        catch (SQLException e) {
            e.printStackTrace();
        }

        return conn;
    }
}
