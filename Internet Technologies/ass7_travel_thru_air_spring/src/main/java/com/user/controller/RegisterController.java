package com.user.controller;

import java.sql.Connection;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import com.user.db.DBConnection;
import com.user.service.RegisterService;

@Controller
public class RegisterController {

	@Autowired
	RegisterService registerService;
	
	/*
	 * Registering a customer  
	 */
	@RequestMapping("registercustomer")
	public ModelAndView registerCustomer(@RequestParam("username") String username, @RequestParam("password") String password
			, @RequestParam("name") String name, HttpServletRequest req, HttpServletResponse res) {
		ModelAndView mv = new ModelAndView();
		Connection conn = null;
		if(req.getSession().getAttribute("DBConnection") == null) {
			conn = DBConnection.getConnection();
			req.getSession().setAttribute("DBConnection", conn);
		} else {
			conn = (Connection) req.getSession().getAttribute("DBConnection");
		}
		if(registerService.register(username, password, name, conn, "customer")) {
			mv.setViewName("logincustomer.jsp");
		} else {
			mv.setViewName("registercustomer.jsp");
		}		
		return mv;
	}
	
	/*
	 * Registering a manager
	 */
	@RequestMapping("registermanager")
	public ModelAndView registerManager(@RequestParam("username") String username, @RequestParam("password") String password
			, @RequestParam("name") String name, HttpServletRequest req, HttpServletResponse res) {
		ModelAndView mv = new ModelAndView();
		Connection conn = null;
		if(req.getSession().getAttribute("DBConnection") == null) {
			conn = DBConnection.getConnection();
			req.getSession().setAttribute("DBConnection", conn);
		} else {
			conn = (Connection) req.getSession().getAttribute("DBConnection");
		}
		if(registerService.register(username, password, name, conn, "manager")) {
			mv.setViewName("loginmanager.jsp");
		} else {
			mv.setViewName("registermanager.jsp");
		}		
		return mv;
	}
}
