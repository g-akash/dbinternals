
import java.util.List;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

/**
 * Servlet implementation class homepage
 */
@WebServlet("/homepage")
public class homepage extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public homepage() {
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
		String option = request.getParameter("option");
		PrintWriter out = response.getWriter();
		if(option.equalsIgnoreCase("newacc"))
		{
			response.setContentType("text/html");

		      // New location to be redirected
		      String site = new String("127.0.0.1:8080/Bank/newaccount.html");

		      response.setStatus(response.SC_MOVED_TEMPORARILY);
		      response.setHeader("Location", site);    
		}
		else if(option.equalsIgnoreCase("debit"))
		{
			String site = new String("127.0.0.1:8080/Bank/debit.html");

		      response.setStatus(response.SC_MOVED_TEMPORARILY);
		      response.setHeader("Location", site);    
		}
		else if(option.equalsIgnoreCase("close"))
		{
			
			List<Integer> L=Trans.clos();
			out.println("<html><body>");

			out.println("no. OF CREDIT TRANSACTION:");
			out.println(L.get(0));
			out.println("<br>");
			out.println("no. OF Debit TRANSACTION:");
			out.println(L.get(1));
			out.println("<br>");
			out.println("Total amount of credit transaction:");
			out.println(L.get(2));
			out.println("<br>");
			out.println("Total amount of dedit transaction:");
			out.println(L.get(3));
			out.println("<br>");
			out.println("</body></html>");
			
		}
		
		// TODO Auto-generated method stub
	}

}
