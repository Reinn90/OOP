
/**
 *
 * @author dongmo
 */

public class Date {

    private int day;
    private int month;
    private int year;

    public Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    public void setDay(int d) {day = d;}
    
    public void setMonth(int m) {month = m;}

    public void setYear(int y) {year = y;}

    public int getDay() {return day;}
    
    public int getMonth() {return month;}
    
    public int getyear() {return year;}
    

    public void display() {
        System.out.println(day + " " + month + " " + year);
    }

    public static void main(String[] args) {
        Date d1 = new Date(1,1,2019);
        Date d2 = new Date(18,9,2019);
        
        d1.display();
        d2.display();
        System.out.println();

        d1 = d2;

        d1.display();
        d2.display();
        System.out.println();

        d2.setDay(25);

        d1.display();
        d2.display();
        System.out.println();
    }
}
