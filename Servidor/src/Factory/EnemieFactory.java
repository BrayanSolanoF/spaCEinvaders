package Factory;

import EnemiesPackage.Crab;
import EnemiesPackage.Enemie;
import EnemiesPackage.Octopus;
import EnemiesPackage.Squid;

/**
 * Clase para la factory de los enemigos
 * Implementa la asbtract Factory
 */
public class EnemieFactory implements AbstractFactory{

	@Override
	public Enemie create(String EnemieType, int points, int Id) {
		// TODO Auto-generated method stub
		if ("Crab".equals(EnemieType)) {
			return new Crab(points, Id);
		}else if("Octopus".equals(EnemieType)) {
			return new Octopus(points , Id);
		}else if("Squid".equals(EnemieType)) {
			return new Squid(points , Id);
		}
		return null;
	}	
}
