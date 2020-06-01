import javazoom.jl.decoder.JavaLayerException;

import java.io.FileNotFoundException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class NormalAlarm {
    public static void main(String... args) throws FileNotFoundException, JavaLayerException, ParseException {
        // Must import javazoom library to use following class
        Alarm a = new Alarm("timer.mp3");
        Scanner sc = new Scanner(System.in);
        String date = sc.nextLine();
        Date d = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss").parse(date);
        while(new Date().compareTo(d) < 0);
        for (int i = 0; i < 3; i++){
            a.play();
        }
        a.close();
    }
}
