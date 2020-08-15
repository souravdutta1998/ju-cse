<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Login</title>
</head>
<body>
<% 
String username = (String)session.getAttribute("username");
if(username != null) {
	response.sendRedirect("welcomeuser.jsp");
	return;
} 
%>
<h1>Welcome to my apparel store!</h1>

Want to go back to registration page? <a href="http://localhost:8080/ass4_online_apparel_store/registeruser.jsp">Register</a>
<br>
<h2>Login here!</h2>
<form action="loginuser" method="post">
<pre>
    Username: <input type="text" name="username" placeholder="Enter username here" required/>
    
    Password: <input type="text" name="password" placeholder="Enter password here" required/>
    
              <input type="submit" value="LOGIN"/>
</pre>
</form>
</body>
</html>