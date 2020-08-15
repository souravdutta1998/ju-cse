package sourav.travelapp.model;

public class Deal {
	private String departurecity;
	private String arrivalcity;	
	private double cost;
	public Deal() {
		
	}
	public Deal(String departurecity, String arrivalcity, double cost) {
		this.departurecity = departurecity;
		this.arrivalcity = arrivalcity;
		this.cost = cost;
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
	
}
