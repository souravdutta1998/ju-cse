package sourav.store.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import sourav.store.model.Item;
import sourav.store.model.User;

/**
 * Servlet implementation class ViewListServlet
 */
@WebServlet("/viewlist")
public class ViewListServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		try {
			PrintWriter out = response.getWriter();
			HttpSession session = request.getSession();
			String username = (String)session.getAttribute("username");
			if(username == null) {
				response.sendRedirect("registeruser.jsp");
				return;
			} 
			out.println("<title>View Details</title>");
			out.println("<h2>Welcome "+username+"</h2>");
			out.println("Want to logout? \r\n" + 
					"<a href=\"http://localhost:8080/ass4_online_apparel_store/logoutuser.jsp\">Logout</a> " + 
					"<br> <br> " + 
					"Want to go back to the User page? " + 
					"<a href=\"http://localhost:8080/ass4_online_apparel_store/welcomeuser.jsp\">View user page</a>");

			String query = "select * from users where username='" + username + "'";
			Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
			PreparedStatement statement = conn.prepareStatement(query);
			ResultSet resultset = statement.executeQuery();
			if (resultset.next()) {
				
				User user = new User();
				user.setUsername(username);
				user.setPassword(resultset.getString("password"));
				user.setGender(resultset.getString("gender"));
				user.setType(resultset.getString("type"));
				
				String query2 = "select * from items where gender='" + user.getGender() + "' and type='" + user.getType() + "' order by price";
				PreparedStatement statement2 = conn.prepareStatement(query2);
				ResultSet resultset2 = statement2.executeQuery();
				
				if(resultset2.next()) {
					out.println("<br><br><h3>Apparel list for you</h3>");
					out.println("<table><tr><td><b>NAME</b></td><td><b>PRICE</b></td><td><b>GENDER</b></td><td><b>TYPE</b></td></tr>");
					do {
						Item item = new Item();
						item.setName(resultset2.getString("name"));
						item.setPrice(Double.parseDouble(resultset2.getString("price")));
						item.setGender(resultset2.getString("gender"));
						item.setType(resultset2.getString("type"));
						
						out.println("<tr><td>"+item.getName()+"</td><td>"+item.getPrice()+"</td><td>"+item.getGender()+"</td><td>"+item.getType()+"</td></tr>");
						//break;
					} while(resultset2.next());
					out.println("</table>");
				} else {
					out.println("<h1>No apparel found according to your preferences!</h1>");
					out.println("Want to go to home page? \r\n" + 
							"<a href=\"http://localhost:8080/ass4_online_apparel_store/registeruser.jsp\">Home Page</a> ") ;
				}
				
			} else {
				out.println("<h1>No apparel found according to your preferences!</h1>");
				out.println("Want to go to home page? \r\n" + 
						"<a href=\"http://localhost:8080/ass4_online_apparel_store/registeruser.jsp\">Home Page</a> ") ;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
