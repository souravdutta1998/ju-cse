package com.user.controller;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import com.user.model.User;

@Controller
public class LoginController {
		
	@RequestMapping("login")
	public ModelAndView login(@RequestParam("text") String emailId, @RequestParam("pwd") String password, 
			HttpServletRequest req, HttpServletResponse res ) {
		ModelAndView mv = new ModelAndView();
		mv.setViewName("homepage.jsp");
		User user = new User(emailId, password);
		ArrayList<User> users = null;
		if(req.getSession().getAttribute("users")!=null)
			users = (ArrayList<User>)req.getSession().getAttribute("users");
		else
			users = new ArrayList<User>();
		users = User.addUser(users, user);
		mv.addObject("currentuser",emailId);
		mv.addObject("password", password);
		return mv;
		
	}

}
