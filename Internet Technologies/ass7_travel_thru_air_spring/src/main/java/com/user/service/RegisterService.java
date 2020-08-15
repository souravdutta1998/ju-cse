package com.user.service;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import org.apache.log4j.Logger;
import org.springframework.stereotype.Service;

@Service
public class RegisterService {
	
	final static Logger logger = Logger.getLogger(RegisterService.class);
	
	public boolean register(String username, String password, String name, Connection conn, String type) {
		try {
			String query;
			if(type == "customer") query = "select * from customers where username='" + username +"'" ;
			else query = "select * from managers where username='" + username +"'" ;
			PreparedStatement statement = conn.prepareStatement(query);
			ResultSet resultset = statement.executeQuery();
			if (resultset.next()) {
				logger.warn(type + " " + username + " already exists");
				return false;
			} else {
				if(type == "customer") query = "insert into customers values('"+username+"','"+password+"','"+name+"')";
				else query = "insert into managers values('"+username+"','"+password+"','"+name+"')";
				statement = conn.prepareStatement(query);
				statement.execute();
				logger.info(type + " " + username + " registered successfully");
				return true;
			}
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		logger.error(type + " " + username + "registration failed");
		return false;
	}
}
