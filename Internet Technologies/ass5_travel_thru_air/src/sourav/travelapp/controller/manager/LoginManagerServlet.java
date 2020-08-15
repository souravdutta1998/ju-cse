package sourav.travelapp.controller.manager;

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

import sourav.travelapp.model.User;

/**
 * Servlet implementation class LoginManagerServlet
 */
@WebServlet("/loginmanager")
public class LoginManagerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginManagerServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			PrintWriter out = response.getWriter();
			String username = request.getParameter("username");
			String password = request.getParameter("password");

			String query = "select * from managers where username='" + username + "'";
			Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
			PreparedStatement statement = conn.prepareStatement(query);
			ResultSet resultset = statement.executeQuery();
			if (resultset.next()) {
				if (resultset.getString("password").equals(password)) {
					HttpSession session = request.getSession();
					User user = new User(username, password, resultset.getString("name"), "manager");
					session.setAttribute("user", user);
					response.sendRedirect("welcomemanager.jsp");
				} else {
					out.println("<h1>Invalid Password for the given username!</h1>");
					out.println("Want to go to home page? \r\n" + 
							"<a href=\"http://localhost:8080/ass5_travel_thru_air/registermanager.jsp\">Home Page</a> ") ;
				}
			} else {
				out.println("<h1>Manager does not exist in the database!</h1>");
				out.println("Want to go to home page? \r\n" + 
						"<a href=\"http://localhost:8080/ass5_travel_thru_air/registermanager.jsp\">Home Page</a> ") ;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
