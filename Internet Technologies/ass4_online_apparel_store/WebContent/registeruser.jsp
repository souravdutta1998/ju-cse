<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Welcome</title>
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

Already registered? <a href="http://localhost:8080/ass4_online_apparel_store/loginuser.jsp">Login</a>
<br>
<h2>Register here!</h2>
<form action="registeruser" method="post">
<pre>
    Username: <input type="text" name="username" placeholder="Enter username here" required/>
    
    Password: <input type="text" name="password" placeholder="Enter password here" required/>
    
    Gender: 
    <input type="radio" name="gender" value="m" required>Male
    <input type="radio" name="gender" value="f" required>Female
    
    Preference type (optional): 
    <input type="radio" name="type" value="discounted" >Discounted
    <input type="radio" name="type" value="new-arrival" >New Arrival
	
              <input type="submit" value="REGISTER"/>
</pre>
</form>
</body>
</html>