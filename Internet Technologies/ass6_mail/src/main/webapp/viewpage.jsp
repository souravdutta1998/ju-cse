<%@page import="javax.mail.Message"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

Welcome to your mailbox  <%= request.getAttribute("currentuser") %>

<br>

<h2> Messages :  </h2>

<form action="viewmail.jsp">
<table>
<tr>
<td>From</td>
<td>Subject</td>
<td>Select</td>
</tr>

<% Message[] messages = (Message[])request.getAttribute("messages");
   for(int i=messages.length-1;i>=0;i--) {
	   %>
   <tr>
   <td> <%=messages[i].getFrom()[0] %> </td>
   <td> <%=messages[i].getSubject() %> </td>
   <td> <input type="radio" name="select" value=<%= String.valueOf(i) %> > </td>
   </tr>
   <%  }
   %>
   
</table>
	<input type="submit" value="view" >
   <input type="hidden" name="currentuser" value=<%= request.getAttribute("currentuser") %> >
   <input type="hidden" name="password" value=<%= request.getAttribute("password") %> >
</form>

</body>
</html>