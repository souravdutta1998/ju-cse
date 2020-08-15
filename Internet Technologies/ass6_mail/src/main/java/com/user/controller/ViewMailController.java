package com.user.controller;

import java.io.IOException;
import java.util.Properties;

import javax.mail.Authenticator;
import javax.mail.Folder;
import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.NoSuchProviderException;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Store;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class ViewMailController {
	
	@RequestMapping("viewmails")
	public ModelAndView viewMails(HttpServletRequest req, HttpServletResponse res) {
		ModelAndView mav = new ModelAndView();
		mav.setViewName("viewpage.jsp");
		mav.addObject("currentuser", (String)req.getParameter("currentuser"));
		mav.addObject("password", (String)req.getParameter("password"));
		final String user = (String)req.getParameter("currentuser");
		final String pwd = (String)req.getParameter("password");

		try {
		// create properties field
			Properties properties = new Properties();
			properties.put("mail.pop3.host", "pop.gmail.com");
			properties.put("mail.pop3.port", "995");
			properties.put("mail.pop3.starttls.enable", "true");
			properties.put("mail.pop3.socketFactory.class" , "javax.net.ssl.SSLSocketFactory" );
			//Session emailSession = Session.getDefaultInstance(properties);
			Session emailSession = Session.getDefaultInstance(properties , new Authenticator() {
			    @Override
			            protected PasswordAuthentication getPasswordAuthentication() {
			                return new PasswordAuthentication( user , pwd);
			            }
			});
			// create the POP3 store object and connect with the pop server
			Store store = emailSession.getStore("pop3s");

			store.connect("pop.gmail.com", user, pwd);

			// create the folder object and open it
			Folder emailFolder = store.getFolder("INBOX");
			emailFolder.open(Folder.READ_WRITE);

			// retrieve the messages from the folder in an array and print it
			Message[] messages = emailFolder.getMessages();
			System.out.println("messages.length---" + messages.length);
			int c = 0;
			for (int i = messages.length-1;i >= 0; i--) {
				Message message = messages[i];
				System.out.println("---------------------------------");
				System.out.println("Email Number " + (c + 1));
				System.out.println("Subject: " + message.getSubject());
				System.out.println("From: " + message.getFrom()[0]);
				System.out.println("Body: " + message.getContent().toString());
				c++;
			}
			mav.addObject("messages", messages);
			req.getSession().setAttribute("messages", messages);
			// close the store and folder objects
//			emailFolder.close(false);
//			store.close();
		} catch (NoSuchProviderException e) {
			e.printStackTrace();
		} catch (MessagingException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return mav;
		
	}
}
