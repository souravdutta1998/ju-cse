<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"
    import="sourav.travelapp.model.*, java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Modify Data</title>
</head>
<body>
<% 
User user = (User)session.getAttribute("user");
if(user == null) {
	response.sendRedirect("index.jsp");
	return;
} 
out.println("<h2>Hey "+user.getUsertype()+"! Welcome "+user.getName()+"</h2>");
%>
Want to logout? 
<a href="http://localhost:8080/ass5_travel_thru_air/logout.jsp">Logout</a>
<br>
Want to go back to Manager Home Page? 
<a href="http://localhost:8080/ass5_travel_thru_air/welcomemanager.jsp">Home Page</a>
<br> <br>
<%
String query = (String) request.getParameter("query");
out.println("SQL query you entered: " + query + "<br><br>");
try {
	Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
	PreparedStatement statement = conn.prepareStatement(query);
	statement.execute();
	out.println("<b>SQL query executed!</b>");
} catch(Exception e) {
	out.println("<b>Invalid SQL query!</b>");
}

%>
</body>
</html>