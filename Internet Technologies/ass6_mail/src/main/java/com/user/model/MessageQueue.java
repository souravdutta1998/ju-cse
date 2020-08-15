package com.user.model;

import java.util.Date;

public class MessageQueue {

	String fromId;
	String toId;
	String subject;
	boolean received;
	boolean seen;
	Date receivedDate;
	Date seenDate;
	
	public MessageQueue(String fromId, String toId, String subject, boolean received, boolean seen) {
		super();
		this.fromId = fromId;
		this.toId = toId;
		this.received = received;
		this.subject = subject;
		this.seen = seen;
	}

	public String getFromId() {
		return fromId;
	}

	public void setFromId(String fromId) {
		this.fromId = fromId;
	}

	public String getToId() {
		return toId;
	}

	public void setToId(String toId) {
		this.toId = toId;
	}

	public String getSubject() {
		return subject;
	}

	public void setSubject(String subject) {
		this.subject = subject;
	}

	public boolean isReceived() {
		return received;
	}

	public void setReceived(boolean received) {
		this.received = received;
	}

	public boolean isSeen() {
		return seen;
	}

	public void setSeen(boolean seen) {
		this.seen = seen;
	}

	public Date getReceivedDate() {
		return receivedDate;
	}

	public void setReceivedDate(Date receivedDate) {
		this.receivedDate = receivedDate;
	}

	public Date getSeenDate() {
		return seenDate;
	}

	public void setSeenDate(Date seenDate) {
		this.seenDate = seenDate;
	}

}
