<html>
<body>
<h2> Welcome to the Email Application </h2>
<br>
Compose a new mail
 <br> <br>
<form action="compose" method="post" >
	<h3>To</h3>	
	<input type="text" placeholder="Receiver's gmail id" name="toId">
	<br> <br> <br>
	<h3>Subject</h3>
	<input type="text" name="subject">
	
	<h3>Body</h3>
	<textarea rows="7" cols="100" name="body"></textarea>
	<br> 
	<input type="submit" value="SEND" >
	<input type="hidden" name="currentuser" value= <%=request.getParameter("currentuser") %> >
	<input type="hidden" name="password" value= <%=request.getParameter("password") %> >
</form>

</body>
</html>