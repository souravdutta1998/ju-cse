package com.user.model;


public class Flight {
	private String flightno;
	private String departurecity;
	private String arrivalcity;
	private double cost;
	private String departuretime;
	private String arrivaltime;
	private int legs;
	public Flight() {
		
	}
	public Flight(String flightno, String departurecity, String arrivalcity, double cost, String departuretime, String arrivaltime, int legs) {
		this.flightno = flightno;
		this.departurecity = departurecity;
		this.arrivalcity = arrivalcity;
		this.cost = cost;
		this.departuretime = departuretime;
		this.arrivaltime = arrivaltime;
		this.legs = legs;
	}
	public String getFlightno() {
		return flightno;
	}
	public void setFlightno(String flightno) {
		this.flightno = flightno;
	}
	public String getDeparturecity() {
		return departurecity;
	}
	public void setDeparturecity(String departurecity) {
		this.departurecity = departurecity;
	}
	public String getArrivalcity() {
		return arrivalcity;
	}
	public void setArrivalcity(String arrivalcity) {
		this.arrivalcity = arrivalcity;
	}
	public double getCost() {
		return cost;
	}
	public void setCost(double cost) {
		this.cost = cost;
	}
	public String getDeparturetime() {
		return departuretime;
	}
	public void setDeparturetime(String departuretime) {
		this.departuretime = departuretime;
	}
	public String getArrivaltime() {
		return arrivaltime;
	}
	public void setArrivaltime(String arrivaltime) {
		this.arrivaltime = arrivaltime;
	}
	public int getLegs() {
		return legs;
	}
	public void setLegs(int legs) {
		this.legs = legs;
	}
}
