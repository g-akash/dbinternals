import java.util.List;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Trans {

	/**
	 * @param args
	 */
	public static List<Integer> clos() {
		// TODO Auto-generated method stub
		
		List<Integer> l=new ArrayList<Integer>();
		Connection connection=null;
		try{
			connection=getConnection();
			Statement stmt=connection.createStatement();
			ResultSet rs= stmt.executeQuery("Select count(*) from transaction where trans_type='credit'");
			l.add(rs.getInt(1));
			 rs= stmt.executeQuery("Select count(*) from transaction where trans_type='debit'");
			l.add(rs.getInt(1));
			 rs= stmt.executeQuery("Select sum(amount) from transaction where trans_type='credit'");
			l.add(rs.getInt(1));
			 rs= stmt.executeQuery("Select count(*) from transaction where trans_type='debit'");
			l.add(rs.getInt(1));
			
		} catch(SQLException sqle){
			System.out.println("SQL exception when getting Department List");
		} finally{
			closeConnection(connection);
		}
		return l;

	}
	
	public static void deb(String acn, String amt, String mod)
	{
		Connection connection=null;
		try{
			connection=getConnection();
			connection=getConnection();
			Statement stmt=connection.createStatement();
			PreparedStatement pstmt=connection.prepareStatement("Select count(*) from account where =account_number=? and current_balance-?>=0");
			pstmt.setString(1, acn);
			pstmt.setString(2, amt);
			ResultSet rs= pstmt.executeQuery();
			if(!rs.next())
			{
				pstmt=connection.prepareStatement("update account where account_number=? set current_balance=current_balance-?" );
				pstmt.setString(1, acn);
				pstmt.setString(2, amt);
				pstmt.executeUpdate();
				pstmt=connection.prepareStatement("insert into transaction values(?,?,?,?,?,?,?)");
				pstmt.setString(1, acn);
				pstmt.setString(2,"debit");
				pstmt.setString(3, mod);
				pstmt.setString(4, "2013-12-21");
				pstmt.setString(5,"12:12:12");
				pstmt.setString(6,amt);
				
				pstmt.executeUpdate();
			}
		} catch(SQLException sqle){
			System.out.println("SQL exception when getting Department List");
		} finally{
			closeConnection(connection);
		}
		return;
		
		
	}
	
	public static void newac(String acc_num,String bid, String cust1, String cust2, String dte, String ovm, String bal)
	{
		if(acc_num==null)return;
		if(bid==null)return;
		if(cust1==null)return;
		if(cust2==null)return;
		if(dte==null)return;
		if(ovm==null)return;
		if(bal==null)return;
		Connection connection=null;
		try{
			connection=getConnection();
			PreparedStatement pstmt= connection.prepareStatement("Select * from customer where customer_id=?");
			pstmt.setString(1, cust1);
			ResultSet rs= pstmt.executeQuery();
			if(!rs.next())
			{
				closeConnection(connection);
				return;
			}
			pstmt.setString(1, cust2);
		    rs= pstmt.executeQuery();
			if(rs==null)
			{
				closeConnection(connection);
				return;
			}
			
			pstmt = connection.prepareStatement("Insert into account values(?,?,?,?,?,?,?)");
			pstmt.setString(1,acc_num);
			pstmt.setString(2,bid);
			pstmt.setString(3,cust1);
			pstmt.setString(4,cust2);
			pstmt.setString(5,dte);
			pstmt.setString(6,ovm);
			pstmt.setString(7,bal);
			pstmt.executeUpdate();
			
			 
			
		} catch(SQLException sqle){
			System.out.println("SQL exception when getting Department List");
		} finally{
			closeConnection(connection);
		}
		
	return ;
	}
	static Connection getConnection() {
		String dbURL = "jdbc:postgresql://10.105.1.12/cs387";
        String dbUser = "db130070060";
        String dbPass = "helo1234";
        Connection connection=null;
        try {
			Class.forName("org.postgresql.Driver");
			connection = DriverManager.getConnection(dbURL, dbUser, dbPass);
        } catch(ClassNotFoundException cnfe){
        	System.out.println("JDBC Driver not found");
        } catch(SQLException sqle){
        	System.out.println("Error in getting connetcion from the database");
        }
        
        return connection;
	}
	
	static void closeConnection(Connection connection) {
		try{
			connection.close();
		} catch(SQLException sqle) {
			System.out.println("Error in close database connetcion");
		}
	}
	

}
