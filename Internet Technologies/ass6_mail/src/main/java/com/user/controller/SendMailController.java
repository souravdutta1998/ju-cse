package com.user.controller;

import java.util.ArrayList;
import java.util.Date;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import com.user.model.MessageQueue;
import com.user.service.SendMailService;

@Controller
public class SendMailController {
	
	@Autowired
	SendMailService sendMailService;
	
	@RequestMapping("compose")
	public ModelAndView compose(@RequestParam("toId") String toId, @RequestParam("subject") String subject,
			@RequestParam("body") String body,HttpServletRequest req, HttpServletResponse res) {		  
		MessageQueue mq = new MessageQueue((String)req.getParameter("currentuser"), toId, subject, true, false);
		mq.setReceivedDate(new Date());
		ArrayList<MessageQueue> mp = new ArrayList<MessageQueue>();
		if(req.getSession().getAttribute("messagequeue") != null)
			mp = (ArrayList<MessageQueue>)req.getSession().getAttribute("messagequeue");
		else System.out.println("no messagequeue found");
		mp.add(mq);
		req.getSession().setAttribute("messagequeue", mp);
		System.out.println(toId);
		System.out.println(subject);
		System.out.println(body);

		sendMailService.sendMail((String)req.getParameter("currentuser"), (String)req.getParameter("password"), toId, subject, body);
		ModelAndView mv = new ModelAndView();
		mv.addObject("currentuser",(String)req.getParameter("currentuser") );
		mv.addObject("password",(String)req.getParameter("password") );
		mv.setViewName("homepage.jsp");
		return mv;
	}
	
}
