package Sockets;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	
	Parser parser = new Parser();

    /*
    *Este metodo escuchar  lo que hace es abrir un socket en un epecifico puerto para recibir algo
    */
    public void escuchar(int puerto){
        int n = 0;
        try {
            ServerSocket servidor= new ServerSocket(puerto);
            System.out.println("Esperando conexion");
            while( n != 5){
                Socket misocket=servidor.accept();
                InputStreamReader isr =new InputStreamReader(misocket.getInputStream());
                BufferedReader buff=new BufferedReader(isr);
                String mensaje=buff.readLine();
                n = Integer.parseInt(mensaje);
                parser.doSomething(mensaje);
                System.out.println("Mensaje recibido");
                misocket.close();
            }
            servidor.close();
            return ;
        } catch (IOException e) {
            System.out.println("Error");
            return ;
        }

    }
    /*
    *Este metodo escuchar  lo que hace es abrir un socket en un epecifico puerto para enviar algo
    */
    public void enviar(String ip ,int puerto,String mensaje) throws IOException {
        Socket misocket=new Socket(ip,puerto);
        PrintWriter pw=new PrintWriter(misocket.getOutputStream());
        pw.flush();
        pw.write(mensaje);
        pw.close();
        misocket.close();
    }

}