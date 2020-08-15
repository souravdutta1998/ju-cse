<%@page import="java.util.ArrayList"%>
<%@page import="javax.mail.Message"%>
<%@page import="com.user.model.*, java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

Welcome to your mailbox  <%= request.getParameter("currentuser") %>

<br>
<%  Message[] messages = (Message[])request.getSession().getAttribute("messages");
	// System.out.println("you selected" + request.getAttribute("select"));
	System.out.println("you selected" + request.getParameter("select"));
	int i = Integer.parseInt((String)request.getParameter("select"));
	Message ms = messages[i];
	if(request.getSession().getAttribute("messagequeue") != null) {
		System.out.println("message queue found");
		System.out.println("requirement " + ms.getFrom()[0] + " currentuser");
		ArrayList<MessageQueue> mqs = (ArrayList<MessageQueue>)request.getSession().getAttribute("messagequeue");
		for(MessageQueue mq : mqs) {
			System.out.println(mq.getFromId() + ":" + ms.getFrom()[0]);
			if(mq.getFromId().equals(ms.getFrom()[0].toString()) && mq.getToId().equals((String)request.getParameter("currentuser")) && mq.getSubject().equals(ms.getSubject())) {
				if(!mq.isSeen()) {
					mq.setSeenDate(new Date());
				}
				mq.setSeen(true);
				System.out.println("setting true seen");
			}
		}
		request.getSession().setAttribute("messagequeue",mqs);
	}
	else System.out.println("no messagequeue found");
	%>
	<h2>From</h2>
	<%=ms.getFrom()[0] %>
	<br> <br>
	<h2> Subject</h2>
	<%=ms.getSubject() %>
	<br>
	<h2> Body </h2>
	<%=ms.getContent().toString() %>


</body>
</html>