package sockets;

public class Main {


    public static void main(String[] args){
        Server s = new Server();
        System.out.println(s.escuchar(4187));
    }

}
