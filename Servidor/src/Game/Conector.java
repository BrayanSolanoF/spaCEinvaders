package Game;

import java.net.*;
import java.io.*;

public class Conector {
	
	ServerSocket server;
	Socket socket;
	int port = 9000;
	DataOutputStream output;
	BufferedReader input;
	
	public void init() {
		try {
			server = new ServerSocket(port);
			socket = new Socket();
			socket = server.accept();
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String mensaje = input.readLine();
			System.out.println(mensaje);
			output = new DataOutputStream(socket.getOutputStream());
			output.writeUTF("Se logro con exito la conexión");
			socket.close();
						
		}catch(Exception e){
			
		}
		
		
	}
	

	

}
