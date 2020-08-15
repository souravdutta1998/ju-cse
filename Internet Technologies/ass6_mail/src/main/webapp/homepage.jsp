<%@page import="com.user.model.MessageQueue"%>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.user.model.User" %>
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

<br> <br> <br>

<form action = "logout">
	<div align="right">
	<input type="submit" value="LOGOUT">
	</div>
</form>

<form action = "composepage.jsp">
	<input type="submit" value="COMPOSE"  >
	<input type="hidden" name="currentuser" value= <%=request.getAttribute("currentuser") %> >
	<input type="hidden" name="password" value= <%=request.getAttribute("password") %> >
</form>
<br>
<form action = "viewmails">
	<input type="submit" value="VIEW MAILS" >
	<input type="hidden" name="currentuser" value= <%=request.getAttribute("currentuser") %> >
	<input type="hidden" name="password" value= <%=request.getAttribute("password") %> >
</form>

<%
	if(session.getAttribute("messagequeue")!=null) {
	System.out.println("got message queue");
	ArrayList<MessageQueue> received = new ArrayList<MessageQueue>();
	ArrayList<MessageQueue> mqs = (ArrayList<MessageQueue>)session.getAttribute("messagequeue");
	ArrayList<MessageQueue> newmqs = new ArrayList<MessageQueue>();
	for(MessageQueue mq : mqs) {
		System.out.println("yo "+mq.getFromId());
		if(mq.getFromId().equals(request.getAttribute("currentuser"))) {
			if(mq.isSeen())
				received.add(mq);
			else if(mq.isReceived()) { 
				received.add(mq);
				newmqs.add(mq);
			}
		}
		else newmqs.add(mq);
			
	}
	session.setAttribute("messagequeue", newmqs);
	if(!received.isEmpty()) {
		System.out.println("sending notification");   %>
		<h4>Notification Received</h4>
	<%
		for(MessageQueue mq : received) { 
			if(mq.isSeen()) {%>
			<br> <%= mq.getToId() %> has seen your mail "<%= mq.getSubject()%>"<br>
			<% }else{ %>
			<br> <%= mq.getToId() %> has received your mail "<%= mq.getSubject()%>"<br>
	<% 		}	
		}
	
	}
} %>

</body>
</html>