<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="com.user.model.*" import="java.sql.*, java.util.*, com.user.dao.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Welcome Manager</title>
</head>
<body>
<% 
User user = (User)session.getAttribute("user");
if(user == null) {
	response.sendRedirect("index.jsp");
	return;
} 
out.println("<h2>Hey "+user.getUsertype()+"! Welcome "+user.getName()+"</h2>");
%>
Want to logout? 
<a href="http://localhost:8080/ass7_travel_thru_air_spring/logout.jsp">Logout</a>
<br> <br>
<h3>Current Flights</h3>
<table border="1">
	<tbody>
		<%
			Connection conn = (Connection) request.getSession().getAttribute("DBConnection");
			FlightDAO flightDAO = new FlightDAO();
			String query = "select * from flights order by departurecity, arrivalcity, departuretime";
			List<Flight> flights = flightDAO.find(query, conn);
			boolean flag = false;
		%>
		<%
			for(Flight f : flights) {
				if(flag == false) {
					%>
					<tr>
						<th>FLIGHT NUMBER</th>
						<th>DEPARTURE CITY</th>
						<th>ARRIVAL CITY</th>
						<th>COST</th>
						<th>DEPARTURE TIME</th>
						<th>ARRIVAL TIME</th>
						<th>LEGS</th>
					</tr>
					<%
				}
				flag = true;
		%>
		<tr>
			<th><%=f.getFlightno() %></th>
			<th><%=f.getDeparturecity() %></th>
			<th><%=f.getArrivalcity() %></th>
			<th><%="Rs. "+f.getCost() %></th>
			<th><%=f.getDeparturetime()+" HRS"%></th>
			<th><%=f.getArrivaltime()+" HRS" %></th>
			<th><%=f.getLegs() %></th>
		</tr>
		<%
			}
			if(flag == false) out.println("No flights to display currently");
		%>
	</tbody>
</table>
<br>
Want to add, delete or update flights? [Table name is "flights"]
<form action="modifydata.jsp" method="post">
<pre>
       <input type="text" name="query" placeholder="Enter SQL query here" style="height:30px;width:600px" required> 
                                   
                                   <input type="submit" value="SUBMIT SQL QUERY" />
</pre>
</form>



</body>
</html>