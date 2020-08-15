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
import com.user.model.User;
import com.user.service.LoginService;

@Controller
public class LoginController {

	@Autowired
	LoginService loginService;
	
	@RequestMapping("logincustomer")
	public ModelAndView loginCustomer(@RequestParam("username") String username, @RequestParam("password") String password
			,HttpServletRequest req, HttpServletResponse res) {
		ModelAndView mv = new ModelAndView();
		Connection conn = null;
		if(req.getSession().getAttribute("DBConnection") == null) {
			conn = DBConnection.getConnection();
			req.getSession().setAttribute("DBConnection", conn);
		} else {
			conn = (Connection) req.getSession().getAttribute("DBConnection");
		}
		User user = loginService.login(username, password, conn, "customer");
		if(user != null) {
			mv.setViewName("welcomecustomer.jsp");
			req.getSession().setAttribute("user", user);
		}
		else {
			mv.setViewName("logincustomer.jsp");
		}		
		return mv;
	}
	
	@RequestMapping("loginmanager")
	public ModelAndView loginManager(@RequestParam("username") String username, @RequestParam("password") String password
			,HttpServletRequest req, HttpServletResponse res) {
		ModelAndView mv = new ModelAndView();
		Connection conn = null;
		if(req.getSession().getAttribute("DBConnection") == null) {
			conn = DBConnection.getConnection();
			req.getSession().setAttribute("DBConnection", conn);
		} else {
			conn = (Connection) req.getSession().getAttribute("DBConnection");
		}
		User user = loginService.login(username, password, conn, "manager");
		if(user != null) {
			mv.setViewName("welcomemanager.jsp");
			req.getSession().setAttribute("user", user);
		}
		else {
			mv.setViewName("loginmanager.jsp");
		}		
		return mv;
	}	
}
