package com.user.model;

public class User {
	private String username;
	private String password;
	private String name;
	private String usertype;
	public User() {
		
	}
	public User(String username, String password, String name, String usertype) {
		this.username = username;
		this.password = password;
		this.name = name;
		this.usertype = usertype;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getUsertype() {
		return usertype;
	}
	public void setUsertype(String usertype) {
		this.usertype = usertype;
	}
	
}
