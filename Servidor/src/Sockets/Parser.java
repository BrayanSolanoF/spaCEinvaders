package Sockets;

public class Parser {
	
	public void doSomething(String message) {
		//System.out.println(message);
		String[] tokens = message.split(";");
		for (String t : tokens)
		  System.out.println(tokens[0]);
	}

}
