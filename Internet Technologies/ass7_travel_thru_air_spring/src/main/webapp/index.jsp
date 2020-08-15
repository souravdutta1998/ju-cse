<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"
    import="com.user.model.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Travel Thru Air</title>
</head>
<body>
<% 
User user = (User) session.getAttribute("user");
if(user != null) {
	if(user.getUsertype() == "customer") response.sendRedirect("welcomecustomer.jsp");
	else if(user.getUsertype() == "manager") response.sendRedirect("welcomemanager.jsp");
	return;
} 
%>
<h1>Welcome to Travel Thru Air</h1>
<h3>
Are you from management department?
<a href="http://localhost:8080/ass7_travel_thru_air_spring/registermanager.jsp">Management Portal</a>
</h3>
<br> <br>
<h3>
Are you a customer?
<a href="http://localhost:8080/ass7_travel_thru_air_spring/registercustomer.jsp">Customer Portal</a>
</h3>

</body>
</html>