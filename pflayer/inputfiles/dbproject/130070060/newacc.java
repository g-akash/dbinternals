

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class newacc
 */
@WebServlet("/newacc")
public class newacc extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public newacc() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		String acc_num=request.getParameter("accnm");
		String bid=request.getParameter("bid");
		String cust1=request.getParameter("cust1");
		String cust2=request.getParameter("cust2");
		String date=request.getParameter("dte");
		String ovm=request.getParameter("ovlim");
		String bal=request.getParameter("currbal");
		Trans.newac(acc_num,bid,cust1,cust2,date,ovm,bal);
		
		
		
		
	}

}
