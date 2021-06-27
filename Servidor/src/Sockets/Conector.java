package Sockets;

import java.net.*;
import java.io.*;

public class Conector {
	
	/*ServerSocket server;
	Socket socket;
	int port = 9000;
	DataOutputStream output;
	BufferedReader input;
	
	public void listen() {
		try {
			server = new ServerSocket(port);
			socket = new Socket();
			socket = server.accept();
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String mensaje = input.readLine();
			System.out.println(mensaje);
			output = new DataOutputStream(socket.getOutputStream());
			output.writeUTF("Se logro con exito la conexión");		
		}catch(Exception e){
		}
	}*/
	
    public String listen(int port){
        try {
            ServerSocket server = new ServerSocket(port);
            Socket mysocket = server.accept();
            InputStreamReader isr = new InputStreamReader(mysocket.getInputStream());
            BufferedReader buff=new BufferedReader(isr);
            String message=buff.readLine();
            mysocket.close();
            server.close();
            return message;
        }catch (IOException e) {
            return "";
        	}
    }

    public void send(String ip ,int port,String message) throws IOException {
        Socket mysocket=new Socket(ip,port);
        PrintWriter pw=new PrintWriter(mysocket.getOutputStream());
        pw.flush();
        pw.write(message);
        pw.close();
        mysocket.close();
    }
}
