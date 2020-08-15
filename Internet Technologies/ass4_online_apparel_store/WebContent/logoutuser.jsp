<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Logout</title>
</head>
<body>
<%
session.removeAttribute("username");
session.removeAttribute("user");
session.invalidate();
response.sendRedirect("registeruser.jsp");
%>
</body>
</html>