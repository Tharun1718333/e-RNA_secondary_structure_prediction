import java.awt.*;
import java.awt.geom.Arc2D;
import java.util.Scanner;
public class cand_box extends Frame{  
	public cand_box(){
	      super("Java AWT Examples");
	      prepareGUI();
	   }
	public static int len;
	public static int line_len;
	public static String rna; 
	public static int a[] = new int[100];
	public static int b[] = new int[100];
	   public static void main(String[] args){
	      Scanner sc= new Scanner(System.in);
	        rna = sc.next();
	       line_len = rna.length();
		   len = sc.nextInt();
		   for(int i=0;i<len;i++)
		   {
			   a[i] = sc.nextInt();
			   b[i] = sc.nextInt();
		   }
		   cand_box  awtGraphicsDemo = new cand_box();  
		      awtGraphicsDemo.setVisible(true);
	   }
	   private void prepareGUI(){
	      setSize(1000,1000); 
	   }    
	   @Override
	   public void paint(Graphics g) {
	      Graphics2D g2 = (Graphics2D) g; 
	      g2.setColor(Color.black);
	      g2.drawLine(0, 500, (line_len*20), 500);
	      for(int i=0;i<line_len;i++)
	      {
	    	  Font font = new Font("Serif", Font.PLAIN, 12);
 		      g2.setFont(font);
		      g.drawString(rna.substring(i,i+1), (i*20) + 20, 512); 
	      }
	      for(int i=0;i<len;i++)
	      {
	    	  Arc2D.Float arc = new Arc2D.Float(Arc2D.PIE);
		      arc.setFrame(min(a[i],b[i])*20,500-(10*abs(a[i],b[i])),20*abs(a[i],b[i]),20*abs(a[i],b[i]));
		      arc.setAngleStart(0);
		      arc.setAngleExtent(180);
		      g2.draw(arc);
	      }
	   }
	private int abs(int x,int y) {
		if( x > y)
			return x-y;
	   return y-x;
	}
	private int min(int x,int y) {
		if( x > y)
			return y;
	   return x;
	}
	private int max(int x,int y) {
		if( x > y)
			return x;
	   return y;
	}
}  