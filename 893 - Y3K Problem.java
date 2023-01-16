import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main {
    public static void main(String[] args) {
      Scanner inp = new Scanner(System.in);
      
      while(true){
        int increase = inp.nextInt();
        int day = inp.nextInt();
        int month = inp.nextInt();
        int year = inp.nextInt();
        
        if(year == 0) break;
        
        Calendar cal = new GregorianCalendar(year, month-1, day); // month-1 because January is 0 and December is 11
        cal.add(Calendar.DAY_OF_MONTH, increase);
        System.out.printf("%d %d %d\n", cal.get(Calendar.DAY_OF_MONTH), cal.get(Calendar.MONTH)+1, cal.get(Calendar.YEAR));
        //cal.get(Calendar.MONTH)+1 because January is 0 and December is 11
      }
  }
}
