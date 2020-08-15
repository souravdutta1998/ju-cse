package com.user.model;

import java.util.ArrayList;

public class User {
	String emailId;
	String password;
	
	public User(String email,String pwd) {
		this.emailId = email;
		this.password = pwd;
	}
	
	public static boolean isPresent(ArrayList<User> users, User user) {
		if(users.isEmpty() || users == null)
			return false;
		for(User usr : users) {
			if(usr.emailId.equals(user.emailId) && usr.password.equals(user.password) )
				return true;
		}
		return false;
	}

	public static ArrayList<User> addUser(ArrayList<User> users, User user) {
		if(isPresent(users, user))
			return users;
		else if(users != null) {
			users.add(user);
			return users;
		}
		else {
			users = new ArrayList<User>();
			users.add(user);
			return users;
		}
	}
	
	public String getId() {
		return emailId;
	}
	
}
