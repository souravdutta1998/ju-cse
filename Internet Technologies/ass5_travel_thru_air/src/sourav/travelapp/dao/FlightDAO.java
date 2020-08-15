package sourav.travelapp.dao;
import java.sql.*;
import java.util.*;
import sourav.travelapp.model.*;

public class FlightDAO {
	public List<Flight> find(String query, Connection conn) {
		List<Flight> flightlist = new ArrayList<Flight>();
		try {
			PreparedStatement statement = conn.prepareStatement(query);					
			ResultSet resultset = statement.executeQuery();
			while(resultset.next()) {
				Flight flight = new Flight();
				flight.setFlightno(resultset.getString("flightno"));
				flight.setDeparturecity(resultset.getString("departurecity"));
				flight.setArrivalcity(resultset.getString("arrivalcity"));
				flight.setCost(resultset.getDouble("cost"));
				flight.setDeparturetime(resultset.getString("departuretime"));
				flight.setArrivaltime(resultset.getString("arrivaltime"));
				flight.setLegs(resultset.getInt("legs"));
				flightlist.add(flight);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return flightlist;
	}
}
