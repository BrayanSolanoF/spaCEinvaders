package Sockets;

public class Sala implements Runnable{
	
	private Integer port;
    private String jsonMatrix = "";
    public String ips[] = {"", "", ""};
    private Integer player = 0;
    private Integer turno = 0;
    private Conector socket = new Conector();
    private static Sala sala1 = null;
    private static Sala sala2 = null;
	
    
    private Sala(Integer player, Integer port){
        this.player = player;
        this.port = port;
    }
    
    public static Sala getInstance(Integer sala){
        if (sala == 1){
            if (sala1 == null){
                sala1 = new Sala(1, 8082);
            }
            return sala1;
        }else{
            if (sala2 == null){
                sala2 = new Sala(2, 8083);
            }
            return sala2;
        }
    }
    
    
    public void agregarJugador(String ip){
        ips[turno] = ip;
    }

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}
	

}
