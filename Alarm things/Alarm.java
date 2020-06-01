import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Alarm {
    Player p;
    String path;
    public Alarm(String path){
        try{
            FileInputStream fis = new FileInputStream(path);
            p = new Player(fis);
        }catch(FileNotFoundException | JavaLayerException e){
            e.printStackTrace();
        }
        this.path = path;
    }
    public void play() throws JavaLayerException, FileNotFoundException {
        p.play();
        p.close();
        p = new Player(new FileInputStream(path));
    }
    public void close(){
        p.close();
    }
}
