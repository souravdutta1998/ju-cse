<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Update details</title>
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
Want to go back to the User page? 
<a href="http://localhost:8080/ass4_online_apparel_store/welcomeuser.jsp">View user page</a>

<h2>Enter the details you want to update</h2>
<form action="updateuser" method="post">
<pre>
    Username: <%=username %>
    
    Password: <input type="text" name="password" placeholder="Enter password here" required/>
    
    Gender: 
    <input type="radio" name="gender" value="m" required>Male</input> 
    <input type="radio" name="gender" value="f" required>Female</input>
    
    Preference type: 
    <input type="radio" name="type" value="discounted" >Discounted</input> 
    <input type="radio" name="type" value="new-arrival" >New Arrival</input>
	
              <input type="submit" value="UPDATE"/>
</pre>
</form>

</body>
</html>