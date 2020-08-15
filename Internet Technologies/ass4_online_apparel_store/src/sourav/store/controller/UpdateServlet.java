package sourav.store.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class UpdateServlet
 */
@WebServlet("/updateuser")
public class UpdateServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			PrintWriter out = response.getWriter();
			HttpSession session = request.getSession();
			String username = (String)session.getAttribute("username");
			String password = request.getParameter("password");
			String gender = request.getParameter("gender");
			String type = request.getParameter("type");
			if(type == "" || type == null) {
				type = "discounted";
			}
			if(username == null) {
				response.sendRedirect("registeruser.jsp");
			}
			String query = "select * from users where username='" + username +"'";
			Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
			PreparedStatement statement = conn.prepareStatement(query);
			ResultSet resultset = statement.executeQuery();
			if (resultset.next()) {
				query = "update users set password='"+password+"', gender='"+gender+"', type='"+type+"' where username='"+username+"'";
				statement = conn.prepareStatement(query);
				statement.execute();
				response.sendRedirect("welcomeuser.jsp");
			} else {
				out.println("<h1>User does not exist in the database!</h1>");
				out.println("Want to go to home page? \r\n" + 
						"<a href=\"http://localhost:8080/ass4_online_apparel_store/registeruser.jsp\">Home Page</a> ") ;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
