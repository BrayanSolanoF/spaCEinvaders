package Factory;

import EnemiesPackage.Crab;
import EnemiesPackage.Enemie;
import EnemiesPackage.Octopus;
import EnemiesPackage.Squid;

public class EnemieFactory implements AbstractFactory{

	@Override
	public Enemie create(String EnemieType, int posX, int posY, String image, int points) {
		if("Crab".equals(EnemieType)) {
		return new Crab(points, points, image, points);
		}else if("Octopus".equals(EnemieType)) {
			return new Octopus(posX, posY, image, points);
		}else if("Squid".equals(EnemieType)) {
			return new Squid(points, points, image, points);
		}
		return null;
	}

	
}
