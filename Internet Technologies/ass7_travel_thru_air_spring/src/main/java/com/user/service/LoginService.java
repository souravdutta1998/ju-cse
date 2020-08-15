package com.user.service;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import org.apache.log4j.Logger;
import org.springframework.stereotype.Service;

import com.user.model.User;

@Service
public class LoginService {
	
	final static Logger logger = Logger.getLogger(LoginService.class);
	
	public User login(String username, String password, Connection conn, String type) {
		User user = null;
		try { 
			String query;
			if(type == "customer") query = "select * from customers where username='" + username + "'";
			else query = "select * from managers where username='" + username + "'";
			PreparedStatement statement = conn.prepareStatement(query);
			ResultSet resultset = statement.executeQuery();
			if (resultset.next()) {
				if (resultset.getString("password").equals(password)) {
					user = new User(username, password, resultset.getString("name"), type);
					logger.info(type + " " + username + " login successful");
					return user;
				} else {
					logger.error(type + " " + username + " login failed : password mismatch");
					return null;
				}
			} else {
				logger.error(type + " " + username + " login failed : username not found");
				return null;
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		logger.error(type + " " + username + " login failed");
		return null;
	}
}
