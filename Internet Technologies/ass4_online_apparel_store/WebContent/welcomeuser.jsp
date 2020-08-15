<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" 
    import="sourav.store.model.Item" import="sourav.store.model.User" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Welcome User</title>
</head>
<body>
<% 
String username = (String)session.getAttribute("username");
if(username == null) {
	response.sendRedirect("registeruser.jsp");
	return;
} 
out.println("<h2>Welcome "+username+"</h2>");
%>
Want to logout? 
<a href="http://localhost:8080/ass4_online_apparel_store/logoutuser.jsp">Logout</a>
<br> <br>
Want to update the user details? 
<a href="http://localhost:8080/ass4_online_apparel_store/updateuser.jsp">Update</a>
<br> <br>
Want to view the apparel list? 
<a href="http://localhost:8080/ass4_online_apparel_store/viewlist">View list</a>

</body>
</html>