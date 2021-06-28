package Game;

import EnemiesPackage.Enemie;
import Factory.AbstractFactory;
import Factory.FactoryProvider;
import Sockets.Server;

public class Main {

	public static void main(String[] args) {

		
        Server s = new Server();
        s.escuchar(7000);

	}
}
