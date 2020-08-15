package com.user.controller;

import java.sql.Connection;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import com.user.model.Flight;
import com.user.service.FlightService;

@Controller
public class SearchFlightsController {
	
	@Autowired
	FlightService flightService;
	
	@RequestMapping("searchflights")
	public ModelAndView search(@RequestParam("departurecity") String departurecity,
			@RequestParam("arrivalcity") String arrivalcity,
			@RequestParam("persons") String persons,
			@RequestParam("starttime") String starttime,
			@RequestParam("endtime") String endtime,
			HttpServletRequest req, HttpServletResponse res) {
		
		ModelAndView mv = new ModelAndView();
		Connection conn = (Connection)req.getSession().getAttribute("DBConnection");
		List<Flight> flights = flightService.getFlights(departurecity, arrivalcity, Integer.parseInt(persons), starttime, endtime, conn);
		mv.addObject("flights", flights);
		mv.addObject("persons", persons);
		mv.setViewName("viewflightlist.jsp");		
		return mv;
	}
}
