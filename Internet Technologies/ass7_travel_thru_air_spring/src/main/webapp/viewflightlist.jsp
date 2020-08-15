<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"
    import="java.util.*"
    import="java.sql.*"
    import="com.user.model.*" 
    import="com.user.dao.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Flight list</title>
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
	<br>
	Want to search flights again? 
	<a href="http://localhost:8080/ass7_travel_thru_air_spring/welcomecustomer.jsp">Profile Page</a>
	<br> <br>
	<h3>Flight list</h3>
	<%		
		int persons = Integer.parseInt((String) request.getAttribute("persons"));
		List<Flight> flights = (List<Flight>) request.getAttribute("flights");
		boolean flag = false;
	%>
	<table border="1">
		<tbody>
			<%
				int i = 0;
				for(Flight f : flights) {
					i++;
					if(flag == false) {
						%>
						<tr>
							<th><b>CHOOSE</b></th>
							<th><b>FLIGHT NUMBER</b></th>
							<th><b>DEPARTURE CITY</b></th>
							<th><b>ARRIVAL CITY</b></th>
							<th><b>TOTAL COST</b></th>
							<th><b>DEPARTURE TIME</b></th>
							<th><b>ARRIVAL TIME</b></th>
							<th><b>LEGS</b></th>
							<th><b>PERSONS</b></th>
						</tr>
						<%
					}
					flag = true;
			%>
			<tr>
				<th><input type="radio" name="index" value="<%=i%>"><%=i %></input></th>
				<th><%=f.getFlightno() %></th>
				<th><%=f.getDeparturecity() %></th>
				<th><%=f.getArrivalcity() %></th>
				<th><%="Rs. "+(f.getCost()*persons) %></th>
				<th><%=f.getDeparturetime()+" HRS"%></th>
				<th><%=f.getArrivaltime()+" HRS" %></th>
				<th><%=f.getLegs() %></th>
				<th><%=persons %></th>
			</tr>
			<%
				}
				if(flag == false) out.println("No flights to display currently");
			%>
		</tbody>
	</table>
	<button id="buyButton">BUY</button>
	<br><br>
	<div id="log"></div>
</body>

<script>
	var log = document.getElementById('log');
	document.getElementById("buyButton").onclick = function() {
		var index = document.getElementsByName('index');
		var flag = 0;
		log.innerHTML = "";
		for(var i=0;i<index.length;i++) {
			if(index[i].checked) {
				flag = 1;
				var idx = parseInt(index[i].value);
				log.innerHTML += "You bought ticket of Flight "+idx;
				break;
			}			
		}		
		if(flag == 0) log.innerHTML += "You did not choose a flight to buy!";
	};
</script>
</html>