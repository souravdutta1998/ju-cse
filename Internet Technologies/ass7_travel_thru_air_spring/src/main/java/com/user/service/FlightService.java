package com.user.service;

import java.sql.Connection;
import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;
import org.springframework.stereotype.Service;

import com.user.dao.FlightDAO;
import com.user.model.Flight;

@Service
public class FlightService {
	
	final static Logger logger = Logger.getLogger(FlightService.class);
	
	public List<Flight> getFlights(String departurecity, String arrivalcity, int persons, String starttime, String endtime, Connection conn) {
		logger.info("Getting the flight details");
		List<Flight> flights = new ArrayList<Flight>();
		FlightDAO flightDAO = new FlightDAO();
		String query = "select * from flights where departurecity='" + departurecity + "' and arrivalcity='" + arrivalcity + "' order by departuretime";
		List<Flight> tempflights = flightDAO.find(query, conn);
		for(Flight f : tempflights) {
			if(Integer.parseInt(f.getDeparturetime()) < Integer.parseInt(starttime)) continue;
			if(Integer.parseInt(f.getDeparturetime()) > Integer.parseInt(endtime)) continue;
			flights.add(f);
		}
		return flights;
	}
	
}
