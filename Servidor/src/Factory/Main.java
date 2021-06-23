package Factory;

import EnemiesPackage.Enemie;

public class Main {

	public static void main(String[] args) {
		 AbstractFactory abstractFactory;
	        
	     abstractFactory = FactoryProvider.getFactory("Enemie");
	     Enemie enemie = (Enemie) abstractFactory.create("Crab", 0, 0, null, 0);
	     Enemie enemie2 = (Enemie) abstractFactory.create("Octopus", 0, 0, null, 0);
	     Enemie enemie3 = (Enemie) abstractFactory.create("Squid", 0, 0, null, 0);
	     
	     enemie.shoting();
	     enemie2.shoting();
	     enemie3.shoting();
	}

}
