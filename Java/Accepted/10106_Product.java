import java.io.*;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String str;
		BigInteger num1 = new BigInteger("1");
		BigInteger num2 = new BigInteger("2");
		boolean f = false;
		int i = 0;
		while((str = reader.readLine()) != null && str.length()>0) {
			if ( f == true) {
				num2 = new BigInteger(str);
				f = false;
				i++;
			}
			else if ( f == false) { 
				num1 = new BigInteger(str);
				f = true;
				i++;
			}
			
			if(i == 2) {
				num1 = num1.multiply(num2);
				System.out.println(num1);
				i = 0;
			}
		}
	}
}