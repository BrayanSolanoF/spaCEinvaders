package EnemiesPackage;
/**
 * Clase para enemigo tipo calamar
 * Implementa la interfaz Enemie
 */
public class Squid implements Enemie{
	private int Id;
	private int points;
	private boolean state = true;
	
	
	public Squid(int points, int Id) {
		this.Id = Id;
		this.points = points;
	}
		
	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}
		
	public int getPoints() {
		return points;
	}

	public void setPoints(int points) {
		this.points = points;
	}
	
	public boolean isState() {
		return state;
	}

	public void setState(boolean state) {
		this.state = state;
	}

	@Override
	public void shoting() {
		// TODO Auto-generated method stub
		System.out.println("This is a Squid " +  Integer.toString(Id) + " shoting");
	}

		
}



