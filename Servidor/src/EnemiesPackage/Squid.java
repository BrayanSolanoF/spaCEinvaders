package EnemiesPackage;

public class Squid implements Enemie{
	private int posX;
	private int posY;
	private String image;
	private int points;
	
	public Squid(int posX, int posY, String image, int points) {
		super();
		this.posX = posX;
		this.posY = posY;
		this.image = image;
		this.points = points;
	}

	public int getPosX() {
		return posX;
	}

	public void setPosX(int posX) {
		this.posX = posX;
	}

	public int getPosY() {
		return posY;
	}

	public void setPosY(int posY) {
		this.posY = posY;
	}

	public String getImage() {
		return image;
	}

	public void setImage(String image) {
		this.image = image;
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
		System.out.println("This is a Squid shoting");
	}

}
