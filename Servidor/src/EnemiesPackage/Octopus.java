package EnemiesPackage;

public class Octopus implements Enemie{
	private int Id;
	private int points;
	private boolean state = true;
	

	public boolean isState() {
		return state;
	}

	public void setState(boolean state) {
		this.state = state;
	}
	
	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}

	public Octopus(int points, int Id) {
		this.Id = Id;
		this.points = points;
	}

	public int getPoints() {
		return points;
	}

	public void setPoints(int points) {
		this.points = points;
	}

	@Override
	public void shoting() {
		// TODO Auto-generated method stub
		System.out.println("This is a Octopus " +  Integer.toString(Id) + " shoting");
	}

}



